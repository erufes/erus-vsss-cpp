#include "campo.h"

//o arquivo deve cnter os pontos x e y dos pontos
//direito inferior direito superior esquerto inferior esquerto superior
//goldieito inferior gol direito superior
//gol esquerdo infrior gol esquerdo superior
void Campo::atualizarCampo(char *campo)
{
    FILE *arq = fopen(campo,"r+");
    double x,y;
    if (arq == NULL)
    {
        printf("ERRO! O arquivo não foi aberto!\n");
        exit(1);
    }

    //pegar lado Direito
    fscanf(arq,"%lf %lf",&x,&y); // x e y do direito inferior
    Ponto aux1 = Ponto(x,y);
    fscanf(arq,"%lf %lf",&x,&y); // x e y do direito suerior
    Ponto aux2 = Ponto(x,y);
    this->limiteDireito = Lado(aux1,aux2);

    //pegar lado esquerdo
    fscanf(arq,"%lf %lf",&x,&y); // x e y do esquerto inferior
    aux1 = Ponto(x,y);
    fscanf(arq,"%lf %lf",&x,&y); // x e y do esquerdo superior
    aux2 = Ponto(x,y);
    this->limiteEsquerdo = Lado(aux1,aux2);

    //pegar lado de baixo
    aux1 = limiteDireito.returnPonto(1); // ponto direito inferior
    aux2 = limiteEsquerdo.returnPonto(1);// ponto esquerdo inferior
    this->limiteInferior = Lado(aux1,aux2);

    //pegar lado de cima
    aux1 = limiteDireito.returnPonto(2); // ponto direito superior
    aux2 = limiteEsquerdo.returnPonto(2);// ponto esquerdo superior
    this->limiteSuperior = Lado(aux1,aux2);

    //gol direito
    fscanf(arq,"%lf %lf",&x,&y); // x e y do gol direito inferior
    aux1 = Ponto(x,y);
    fscanf(arq,"%lf %lf",&x,&y); // x e y do gol direito suerior
    aux2 = Ponto(x,y);
    this->golDireito = Lado(aux1,aux2);

    //gol esquerdo
    fscanf(arq,"%lf %lf",&x,&y); // x e y do gol esquerdo inferior
    aux1 = Ponto(x,y);
    fscanf(arq,"%lf %lf",&x,&y); // x e y do gol esquerdo suerior
    aux2 = Ponto(x,y);
    this->golEsquerdo = Lado(aux1,aux2);


    fclose(arq);
}

Campo::Campo(char *campo){
    atualizarCampo(campo);
}

Campo::Lado::Lado(Ponto p1, Ponto p2)
{
    ponto1 = p1;
    ponto2 = p2;
}

Ponto Campo::Lado::pontoMedio(){
    double x, y;
    x = (ponto1.getX() + ponto2.getX()) / 2;
    y = (ponto1.getY() + ponto2.getY()) / 2;
    return Ponto(x,y);
}

double Campo::Lado::distancia(){
    return ponto1.distancia(ponto2);
}

double Campo::Lado::distanciaParaOutroLado(Lado outro){
    return pontoMedio().distancia(outro.pontoMedio());
}

Ponto Campo::Lado::returnPonto(int x){
    if(x==1){
        return this->ponto1;
    }
    return this->ponto2;
}

int Campo::getYBordaSuperior(){
	return this->limiteSuperior.pontoMedio().getY();
}

int Campo::getYBordaInferior(){
	return this->limiteInferior.pontoMedio().getY();
}

int Campo::getXBordaEsquerda(){
	return this->limiteEsquerdo.pontoMedio().getX();
}

int Campo::getXBordaDireita(){
	return this->limiteDireito.pontoMedio().getX();
}
