#include "campo.h"

namespace vsssERUS {

// O arquivo deve conter os pontos x e y dos pontos
// direito inferior, direito superior, esquerdo inferior e esquerdo superior
// gol direito inferior, gol direito superior
// gol esquerdo inferior, gol esquerdo superior
void Campo::atualizarCampo(char *campo)
{
    FILE *arq = fopen(campo,"r+");
    double x,y;
    if (arq == NULL)
    {
        printf("ERRO! O arquivo nao foi aberto!\n");
        exit(1);
    }

    // pegar lado Direito
    fscanf(arq,"%lf %lf",&x,&y); // x e y do direito inferior
    Ponto aux1 = Ponto(x,y);
    fscanf(arq,"%lf %lf",&x,&y); // x e y do direito superior
    Ponto aux2 = Ponto(x,y);
    this->limiteDireito = Limite(aux1,aux2);

    // pegar lado esquerdo
    fscanf(arq,"%lf %lf",&x,&y); // x e y do esquerdo inferior
    aux1 = Ponto(x,y);
    fscanf(arq,"%lf %lf",&x,&y); // x e y do esquerdo superior
    aux2 = Ponto(x,y);
    this->limiteEsquerdo = Limite(aux1,aux2);

    // pegar lado de baixo
    aux1 = limiteDireito.returnPonto(1); // Ponto direito inferior
    aux2 = limiteEsquerdo.returnPonto(1);// Ponto esquerdo inferior
    this->limiteInferior = Limite(aux1,aux2);

    // pegar lado de cima
    aux1 = limiteDireito.returnPonto(2); // Ponto direito superior
    aux2 = limiteEsquerdo.returnPonto(2);// Ponto esquerdo superior
    this->limiteSuperior = Limite(aux1,aux2);

    // gol direito
    fscanf(arq,"%lf %lf",&x,&y); // x e y do gol direito inferior
    aux1 = Ponto(x,y);
    fscanf(arq,"%lf %lf",&x,&y); // x e y do gol direito superior
    aux2 = Ponto(x,y);
    this->golDireito = Limite(aux1,aux2);

    // gol esquerdo
    fscanf(arq,"%lf %lf",&x,&y); // x e y do gol esquerdo inferior
    aux1 = Ponto(x,y);
    fscanf(arq,"%lf %lf",&x,&y); // x e y do gol esquerdo superior
    aux2 = Ponto(x,y);
    this->golEsquerdo = Limite(aux1,aux2);


    fclose(arq);
}

Campo::Campo() {
}

Campo::Campo(char *campo) {
    #ifdef USE_VSSS_SIZE_AS_PARAM
    this->disc_x = FIELD_SIZE_X / VSSS_SIZE_X;
    this->disc_y = FIELD_SIZE_Y / VSSS_SIZE_Y;
    #else
        // Leia a descrição do define acima no arquivo de cabeçalho da classe para
        // mais informações
        throw runtime_error("Nao implementado! Cheque o construtor do Campo!");
    #endif
    atualizarCampo(campo);
}

Campo::Limite::Limite(Ponto p1, Ponto p2)
{
    ponto1 = p1;
    ponto2 = p2;
}

Ponto Campo::Limite::pontoMedio(){
    double x, y;
    x = (ponto1.getX() + ponto2.getX()) / 2;
    y = (ponto1.getY() + ponto2.getY()) / 2;
    return Ponto(x,y);
}

double Campo::Limite::distancia(){
    return ponto1.distancia(ponto2);
}

double Campo::Limite::distanciaParaOutroLimite(Limite outro){
    return pontoMedio().distancia(outro.pontoMedio());
}

Ponto Campo::Limite::returnPonto(int x){
    if(x==1){
        return this->ponto1;
    }
    return this->ponto2;
}

int Campo::getBordaSuperior(){
	return this->limiteSuperior.pontoMedio().getY();
}

int Campo::getBordaInferior(){
	return this->limiteInferior.pontoMedio().getY();
}

int Campo::getBordaEsquerda(){
	return this->limiteEsquerdo.pontoMedio().getX();
}

int Campo::getBordaDireita(){
	return this->limiteDireito.pontoMedio().getX();
}


Ponto Campo::getMeioDeCampo(){
	Limite aux1(this->limiteDireito.pontoMedio(), this->limiteEsquerdo.pontoMedio());
	return aux1.pontoMedio();
}
Ponto Campo::getMeioDeGolAliado() {
	if(this->nossoLado == Campo::Lado::Direita) {
		return this->golDireito.pontoMedio();
	}else{
		return this->golEsquerdo.pontoMedio();
	}
}
Ponto Campo::getMeioDeGolInimigo(){
	Ponto resp;
		if(this->nossoLado == Campo::Lado::Esquerda) {
			resp = Ponto(this->golDireito.pontoMedio());
		}else{
			resp = Ponto(this->golEsquerdo.pontoMedio());
		}
		return resp;
}

bool Campo::estaDentroDoCampo(Ponto posicao){
	if(posicao.getX() <= this->limiteDireito.returnPonto(1).getX() &&
			posicao.getX() >= this->limiteEsquerdo.returnPonto(1).getX() &&
			posicao.getY() <= this->limiteSuperior.returnPonto(1).getY() &&
			posicao.getY() >= this->limiteInferior.returnPonto(1).getY()){
		return true;
	} else {
		return false;
	}
}

void Campo::setLado(int x){
	if(x == 1){
		this->nossoLado = Esquerda;
	} else if(x == 2){
		this->nossoLado = Direita;
	} else {
		cout << "Lado "<< x << " invalido!" << endl;
	}
}

Campo::dadosDoCampo& Campo::getPositions() {
    Campo::dadosDoCampo* d = new dadosDoCampo();
    d->b = this->ball->getPosicao();
    d->f1 = this->friendlies->getPlayerByIdx(0).getPosicao();
    d->f2 = this->friendlies->getPlayerByIdx(1).getPosicao();
    d->f3 = this->friendlies->getPlayerByIdx(2).getPosicao();
    d->e1 = this->enemies->getPlayerByIdx(0).getPosicao();
    d->e2 = this->enemies->getPlayerByIdx(1).getPosicao();
    d->e3 = this->enemies->getPlayerByIdx(2).getPosicao();
    return *d;
}

} // vsssERUS