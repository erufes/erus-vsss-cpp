#include "ListaComandos.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct cel Cel;

struct cel{
	char* comando;
	char** argumentos;
	int numArgs;
    Cel* prox;
    Cel* ant;
};

struct lComands{
	Cel* prim;
	Cel* ult;
	int tam;
};


int separaComandos(ListaComandos* lista, char* linha ){
    int i = 0, j = 0, pos =0, tam;
    for(tam = 0; tam < strlen(linha); tam++){
        if(linha[tam] == ' ' && linha[tam+1] == '@' && linha[tam+2] == ' ') {
            linha[tam] = 0;
            insereComandos(lista, &linha[pos]);
            linha[tam] = ' ';
            pos = tam+3;
            i++; j = 0; tam=tam+3;
            linha[tam];
        }
        j++;
    }
    insereComandos(lista, &linha[pos]);
    return (i+1);
}

ListaComandos* newListaComandos(char* linha){
	ListaComandos* nova = (ListaComandos*)malloc(sizeof(ListaComandos));
	nova->prim = NULL;
	nova->ult = NULL;
	nova->tam = 0;
	separaComandos(nova, linha);
	return nova;
}


ListaComandos* deleteListaComandos(ListaComandos* comandos){
    if(comandos != NULL){
        Cel* aux1 = comandos->prim;
        Cel* aux2;
        while(aux1!=NULL){
            aux2 = aux1->prox;
            int i = 0;
            while(aux1->argumentos[i] != NULL)
				free(aux1->argumentos[i++]);
            free(aux1->argumentos);
            free(aux1);
            aux1 = aux2;
        }
	free(comandos);
    }
    return NULL;
}

Cel* newCel(char* cmd){
	Cel* newL = (Cel*)malloc(sizeof(Cel));
	newL->comando = cmd;
	newL->ant = NULL;
	newL->prox = NULL;
	return newL;
}



void insereComandos(ListaComandos* comandos, char* cmd){

	Cel* m = newCel(cmd);
	char auxiliarEstatico[500];
	sscanf(cmd, "%s", auxiliarEstatico);
	m->comando = (char*) malloc((strlen(auxiliarEstatico)+1)*sizeof(char));
	strcpy(m->comando, auxiliarEstatico);
    	char** argumentos = (char**)malloc( 6 * sizeof(char*));
    	int i = 1, j = strlen(cmd), k = strlen(auxiliarEstatico)+1;
    	cmd = cmd+k;
    while(k < j && i < 6){
        sscanf(cmd, "%s", auxiliarEstatico);
        argumentos[i] = (char*) malloc((strlen(auxiliarEstatico)+1)*sizeof(char));
	    strcpy(argumentos[i++], auxiliarEstatico);

	    cmd = cmd+strlen(auxiliarEstatico)+1;
	    k += strlen(auxiliarEstatico)+1;
    }
    argumentos[0] = m->comando;
    
    argumentos[i] = NULL;
    m->argumentos = argumentos;
    m->numArgs = i;
    if (comandos->ult == NULL){
    	comandos->prim = comandos->ult = m;
    }else{
    	comandos->ult->prox= m;
        m->ant = comandos->ult;
        comandos->ult = m;
    }
    comandos->tam++;
}

int getNComandos(ListaComandos* comandos){
	return comandos->tam;
}

char* getComando(ListaComandos* comandos, int Index){
    if (comandos != NULL && Index < comandos->tam){
        Cel* aux1 = comandos->prim;
        int i;
        for(i = 0;i < Index; i++){
           aux1 = aux1->prox;
        }
        return aux1->comando;
    }
    return NULL;
}

char** getArgs(ListaComandos* comandos, int Index){
    if (comandos != NULL && Index < comandos->tam){
        Cel* aux1 = comandos->prim;
        int i;
        for(i = 0;i < Index; i++){
           aux1 = aux1->prox;
        }
        return aux1->argumentos;
    }
    return NULL;
}


void imprime(char *ar[], int n){
    int i;
	for(i = 0; i<n; i++)printf("ard->%s\n", ar[i]);
}

int verificarComando(ListaComandos* lista){
	if(lista->tam == 1){
		if (strcmp(lista->prim->comando, "exit") == 0) return 1;
		else if (strcmp(lista->prim->comando, "waitz") ==0 ) return -1;
		else if (strcmp(lista->prim->comando, "cd") == 0) return 2;
	}return 0;
}
