#include <TimerOne.h>
//#include <SoftPWM.h>

#define ID  '2'             //ID do robô, sendo  '3' = atk, '2' = def, '1' = goleiro

#define ledPin 13           //Led indicativo de bateria fraca porta D13

#define pwm_left 9          //definindo pinos para ajustar a velocidade do motor
#define pwm_right 6         

#define dir_left 8
#define dir_right 11

//Constantes do PI
//Formato: kp + ki*z/(z-1)
#define kp 12.79
#define ki 1   

volatile int D;
volatile int E;
volatile int vel;

int dir_left_value;
int dir_right_value;


#define NOID   0xFF
#define ALLID  0x00

int flag;
long mill;
int pwmR, pwmL;
int pwmRForcado, pwmLForcado;
float veloc;
float velE;
float velD;
volatile double aux;     //constante de velocidade

int paused = 0;
int usandoPWM = 0;

void rodaD (){          //incrementando a roda direita
  D++;
}

void rodaE (){          //incrementando a roda esquerda
  E++;
}

void TimeInt (){
  vel = 1;
}

int mapVelPWM(float vel)  //Mapeamento da velocidade
{
  int v = vel*100;
  int pwm = 0;
  if(v <= 0)
    return 0;
  if(v <= 117)
    return map(v,0,117,16,19);
  if(v <= 325)
    return map(v,117,325,19,32);
  if(v <= 443)
    return map(v,325,443,32,44);
  if(v <= 582)
    return map(v,443,582,44,80);
  return 80;
}

double sumErroR = 0, sumErroL = 0;

double pi_right(float setpoint, float medicao)
{
  double erro = setpoint - medicao;
  sumErroR += erro;
  return kp*erro + ki*sumErroR;
}

double pi_left(float setpoint, float medicao)
{
  double erro = setpoint - medicao;
  sumErroL += erro;
  return kp*erro + ki*sumErroL;
}

float mapPWMvel(int pwm)                //???
{
  
}

void setup () {
  //pinMode(ledPin, OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(ledPin,LOW);
  //digitalWrite(LED_BUILTIN, LOW);
  
  Serial.begin(4800);

  /** Toda vez que o estado dos pinos identificados aqui por 0 e 1 mudarem, chama rodaE e rodaD respectivamente
   *  Na doc. diz que essa forma de utilização não é recomendada:
   *        attachInterrupt(digitalPinToInterrupt(pin), ISR, mode); (recommended)
   *        attachInterrupt(interrupt, ISR, mode); (not recommended) <- <- <-
   *  OBS.: IMPORTANTE
   *        attachInterrupt faz com que essas funções bloqueem qualquer interrupção enquanto dentro delas
   *        De acordo com a doc.:
   *          Inside the attached function, delay() won’t work and the value returned by millis() will not increment.
   *          (NOTE NESTA LINHA ESPECIFICA) Serial data received while in the function may be lost. 
   *          You should declare as volatile any variables that you modify within the attached function.
   *        Mesmo sendo funções pequenas, elas podem ocorrer com frequência suficiente para bagunçar o sistema de comuniação.
   */
  attachInterrupt(0, rodaE, CHANGE);//Gera interrupção quando muda o sensor do encoder
  attachInterrupt(1, rodaD, CHANGE);

   /** Configura a função TimeInt para ocorrer a cada 10000 ms (10s)
    * faz vel = 1 em TimeInt 
    * Também utiliza attachInterrupt
    */
  Timer1.initialize(10000);            //tempo entre as interrupçes
  Timer1.attachInterrupt(TimeInt);    //depois da interrupção volta para o mesmo lugar que parou

  aux = 0.133333;

  pinMode(dir_right, OUTPUT);       //configurando o pino 'dir_right' como  saida
  pinMode(pwm_right, OUTPUT);       //configurando o pino 'pwm_right' como saída
  pinMode(dir_left, OUTPUT);        //configurando o pino 'dir_left' como saída
  pinMode(pwm_left, OUTPUT);        //configurando o pino 'pwm_left' como saída

  flag = pwmR  = pwmL = 0;
  
  digitalWrite(dir_right,LOW);      //Inicializa o pino 'dir_right' como low
  digitalWrite(dir_left,HIGH);      //Inicializa o pino 'dir_left' como high

  //while(Serial.read() != 's') {}
  
  mill = millis();
  D = 0;
  
  Timer1.pwm(pwm_left,0);           //Isso configura o tipo de onda pwm, pwm feito por sofware, não tem 2 pinos pwm pq o arduino nano é pirata
  
  analogWrite(pwm_right,0);         //configurando o pino 'pwm_right' com valor pwm 0
}

float setpoint_right;
float setpoint_left;

void loop () {

    /** Leitura das variáveis no buffer
      *  São enviadas com o padrão:
      *        0 : Inicio do recebimento
      *       id : ID do robô
      *            Se 1 Goleiro
      *            Se 2 Zagueiro
      *            Se 3 Atacante
      *      cmd : Comando que o robô ira obedecer
      *            Se 'l' altera config. da roda esquerda
      *            Se 'r' altera config. da roda direita
      *            Se 'L' altera config. da roda esquerda de forma forçada -> ?
      *            Se 'R' altera config. da roda direita de forma forçada -> ?
      *            Se 's' pausa
      *    value : Valor usado no comando
     */
    char inicio = 1;
    if(Serial.available() >= 4){
      inicio = Serial.read();    //Lê o valor do primeiro comando, pegando o valor como um char e convertendo para inteiro.
    }
    if(inicio == 0){
      //if(Serial.available() >= 3) // Sem time out, estou confiando no protocolo zigbee e na placa.
      //{ 
        //if(digitalRead(LED_BUILTIN) == HIGH){
                
               //   digitalWrite(LED_BUILTIN,LOW);
              //}else{
                
                //digitalWrite(LED_BUILTIN,HIGH);
          
              //}
              //delay(100);
          //digitalWrite(LED_BUILTIN,HIGH);
          char cmd;
          signed int value;
          char id = Serial.read();  //Lê o ID do robô, podendo ser '1', '2', ou '3', para goleiro, zagueiro e atacante respectivamente.
          cmd = Serial.read();      //Lê o comando do robô, sendo 'l', 'r', 'L', 'R' ou 's', explicação de cada comando no switch
          value = Serial.read();    //Lê o valor do comando, pegando o valor como um char e convertendo para inteiro.
  
           
          if(id == ID){//Confere qual o numero do robô
            switch(cmd)
            {
              
                case 'l': // Comando pwm da roda esquerda
                {
                    paused = 0;
                    usandoPWM = 0;
                    value = (value-128)*2;
                    
                    if(value < 0) {
                      value *= -1;
                      dir_left_value = 1;
                    } else {
                      dir_left_value = 0;
                    }
                    setpoint_left = 5*value/255.0;
                    if( value == 0)
                      sumErroL = 0;
                    break;
                } 
                case 'r': // Comando pwm da roda direita
                {
                    paused = 0;
                    usandoPWM = 0;
                    value = (value-128)*2;
                    
                    if(value < 0) {
                      value *= -1;
                      dir_right_value = 0;
                    } else {
                      dir_right_value = 1;
                    }
                    setpoint_right = 5*value/255.0;
                    if( value == 0)
                      sumErroR = 0;      
                    break;
                }
                case 'L': // Comando de forçar pwm da roda esquerda
                {
                    paused = 0;
                    usandoPWM = 1;
                    value = (value-128)*2;
                    
                    if(value < 0) {
                      value *= -1;
                      dir_left_value = 1;
                    } else {
                      dir_left_value = 0;
                    }
                    pwmLForcado = value;
                    break;
                } 
  
                case 'R': // Comando de forçar pwm da roda direita
                {
                    paused = 0;
                    usandoPWM = 1;
                    value = (value-128)*2;            
                    if(value < 0) {
                      value *= -1;
                      dir_right_value = 0;
                    } else {
                      dir_right_value = 1;
                    }
                    pwmRForcado = value;
                    break;
                }
  
                case 's': // Comando de pausa
                {
                    //digitalWrite(ledPin,HIGH);
                    setpoint_right = 0;
                    setpoint_left = 0;
                    sumErroR = 0;
                    sumErroL = 0;
                    paused = 1;            
                    break;
                }
            }
          //}else if (id != '1' && id != '3'){
          //  //digitalWrite(ledPin,HIGH);
          //}
      }
  
      if (vel == 1) // 
      {
        vel = 0;
        velD = D*aux;
        velE = E*aux;
        E = 0;
        D = 0;
        if(usandoPWM){
          pwmR = pwmRForcado;
          pwmL = pwmLForcado;
        }else{
          pwmR = mapVelPWM(pi_right(setpoint_right, velD));
          pwmL = 4*mapVelPWM(pi_left(setpoint_left, velE));
        }
      }
      if(paused)
      {
        analogWrite(pwm_right, 0);        //fazendo o pino pwm_right ficar com o valor 0
        Timer1.pwm(pwm_left, 0);
      } else {
        analogWrite(pwm_right, pwmR);
        Timer1.pwm(pwm_left, pwmL);
        digitalWrite(dir_right,dir_right_value);   //Se não pausar, setar o valor dir_right_value no pino dir_right
        digitalWrite(dir_left,dir_left_value);
      }  
    }
}

