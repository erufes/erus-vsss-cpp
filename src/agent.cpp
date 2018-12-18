#include "agent.h"
#include <stdlib.h>
#include <iostream>

Agent::Agent(double x, double y)
{
    posicao = Ponto(x, y);
}
Agent::Agent(Ponto ponto){
	posicao = ponto;
}

//faz a previsão de uma futura posição da bola/player
std::pair<double, double> Agent::predicao_adaptativa(Ponto ponto_atual, vector<Ponto> vetor_funcao){
	double Kx1, Kx2, Kx3, Kx4, Ky1, Ky2, Ky3, Ky4, t;
	int i;
	pair<double, double> ponto_futuro;

	//f[][0]: X = f(t), f[][1]: Y = g(t) <------- DE SUMA IMPORTÂNCIA PARA ENTENDER O CÓDIGO, na maioria dos casos, [0] denota X e [1] denota Y
	double f[4][2];
	double** AUXf = ajusteDeCurva(vetor_funcao, 4);
	for(i = 0; i < 4; i++){
		f[i][0] = AUXf[0][i+1]*(i+1);
		f[i][1] = AUXf[1][i+1]*(i+1);
	}
	free(AUXf[0]); // Confira se está liberando memória corretamente
	free(AUXf[1]);
	free(AUXf);

//	cout << "f(t) = " << f[0][0] << " + " << f[1][0] << "t + " << f[2][0] << "t² + " << f[3][0] << "t³" << endl;
//	cout << "g(t) = " << f[0][1] << " + " << f[1][1] << "t + " << f[2][1] << "t² + " << f[3][1] << "t³" << endl;
//	cout << endl;

	//Previsão via método de Runge-Kutta de 4ª ordem
	t = 5;
	double hx = 1;
	Kx1 = f[0][0] + f[1][0] * t + f[2][0] * pow(t, 2) + f[3][0] * pow(t, 3);
	Kx2 = f[0][0] + f[1][0] * (t + hx/2) + f[2][0] * pow(t + hx/2, 2) + f[3][0] * pow(t + hx/2, 3);
	Kx3 = Kx2;
	Kx4 = f[0][0] + f[1][0] * (t + hx) + f[2][0] * pow(t + hx, 2) + f[3][0] * pow(t + hx, 3);
//	cout << "Kx1: " << Kx1 << " Kx2: " << Kx2 << " Kx3: " << Kx3 << " Kx4: " << Kx4 << endl;

	double hy = 1;
	Ky1 = f[0][1] + f[1][1] * t + f[2][1] * pow(t, 2) + f[3][1] * pow(t, 3);
	Ky2 = f[0][1] + f[1][1] * (t + hy/2) + f[2][1] * pow(t + hy/2, 2) + f[3][1] * pow(t + hy/2, 3);
	Ky3 = Ky2;
	Ky4 = f[0][1] + f[1][1] * (t + hy) + f[2][1] * pow(t + hy, 2) + f[3][1] * pow(t + hy, 3);

	ponto_futuro.first = ponto_atual.getX() + ((hx/6) * (Kx1 + 2*Kx2 + 2*Kx3 + Kx4));
	ponto_futuro.second = ponto_atual.getY() + ((hy/6) * (Ky1 + 2*Ky2 + 2*Ky3 + Ky4));
	//Fim da previsão pelo método de Runge-Kutta de 4ª ordem

	return ponto_futuro;
    //return 4.5 + (x - World.World.FIELD_LEFT) * (3.5 - 4.5) / (World.World.FIELD_RIGHT - World.World.FIELD_LEFT)
}

void Agent::update_position(double x, double y){
    posicao.setX(x);
    posicao.setY(y);
}

Ponto Agent::getPonto(){
    return this->posicao;
}

//Função que descobre a curva de grau 'grau' que melhor descreve os pontos presentes em 'vet'
//Ela retorna os coeficientes (B0, B1, B2, ..., Bgrau-1, Bgrau) da equação B0 + B1*t + B2*t² + ... + Bgrau*t^grau
//Essa função foi desenvolvida pensando em descobrir os valores das posições X e Y num tempo t, logo, ela ocorre "duas vezes" (na mesma chamada da função) para realizar esse processo mais rapidamente
double** Agent::ajusteDeCurva(vector<Ponto> vet, int grau){

	//Separação dos pontos em coordenadas independentes
	vector<double> vetX, vetY;

	//vetOut[0]: coeficientes de X = f(t), vetOut[1]: coeficientes de Y = g(t)
	double** vetOut = (double**)malloc(2*sizeof(double**));
	for(int k = 0; k != vet.size(); ++k){
		vetOut[0] = (double*)calloc(grau, sizeof(double));
		vetOut[1] = (double*)calloc(grau, sizeof(double));
		vetX.push_back(vet[k].getX());
		vetY.push_back(vet[k].getY());
	}

	//Resolução via ajuste polinomial
	//MatrixX = Matrix[0] e MatrixY = Matrix[1]
	double** Matrix[2];
	Matrix[0]  = (double**)malloc((grau+1)*sizeof(double*));
	Matrix[1]  = (double**)malloc((grau+1)*sizeof(double*));
	//Faz Matrix[i][j] = somatório(vet^(i+j))
	for(int i = 0; i <= grau; i++){
		Matrix[0][i] = (double*)calloc((grau+1),sizeof(double));
		Matrix[1][i] = (double*)calloc((grau+1),sizeof(double));
		for(int j = 0; j <= grau; j++){
			for(int k = 0; k != vet.size(); k++){
				Matrix[0][i][j] += pow(k,i+j);
				Matrix[1][i][j] += pow(k,i+j);
			}
		}
	}

	//vetorX = vetor[0] e vetorY = vetor[1]
	double vetor[2][grau + 1];

	//Faz vetor = somatório(tj*vetj^i)
	for(int i = 0; i <= grau; i++){
		vetor[0][i] = 0;
		vetor[1][i] = 0;
		for(int j = 0; j != vet.size(); j++){
			vetor[0][i] += vetX[j]*pow(j, i);
			vetor[1][i] += vetY[j]*pow(j, i);
		}
	}



	vector<double> aux0 = Ponto::resolucaoDeSistemaLinear(Matrix[0], vetor[0], grau+1);
	vector<double> aux1 = Ponto::resolucaoDeSistemaLinear(Matrix[1], vetor[1], grau+1);

	//Passo com o único intuito de arredondar valores muito pequenos e próximos de zero
	for(int i = 0; i <= grau; i++){
		if(aux0[i] < 0.001 && aux0[i] > -0.001){
			aux0[i] = 0;
		}
		if(aux1[i] < 0.001 && aux1[i] > -0.001){
			aux1[i] = 0;
		}
		vetOut[0][i] = aux0[i];
		vetOut[1][i] = aux1[i];
	}


	for(int i = 0; i <= grau; i++){
		free(Matrix[0][i]);
		free(Matrix[1][i]);
	}

	free(Matrix[0]);
	free(Matrix[1]);
	//Fim da resolução via ajuste polinomial

	return vetOut;
}

////resolve a equação Ax³ + Bx² + Cx + D = 0
//double resolucaoDeEquacaoDoTerceiroGrau(double A, double B, double C, double D){
//	double x, p, q, r;
//	p = (B*(-1))/(3*A);
//	q = pow(p, 3) + (B*C - 3*A*D)/(6*A*A);
//	r = C/(3*A);
//	x = (pow(q + (pow(q*q + pow(r - p*p, 3), 1/2)), 1/3)) + (pow(q - (pow(q*q + pow(r - p*p, 3), 1/2)), 1/3)) + p;
//	return x;
//}
//
//double resolucaoDeEquacaoDoSegundoGrau(double A, double B, double C){
//	double delta, x1, x2;
//	delta = B*B - 4*A*C;
//	x1 = ((-1)*B + sqrt(delta))/(2*A);
//	x2 = ((-1)*B - sqrt(delta))/(2*A);
//}
