/*
 ============================================================================
 Name        : Simulador.cpp
 Author      : Lorena
 Version     : V 1.0
 Description : Programa que roda simulação do vsss
 IMPORTANTE  : 
 ============================================================================
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <wait.h>
#include <iostream>

#include "vss-simulator/ListaComandos/ListaComandos.h"

using namespace std;

#define rodavelList {{"VSS-Simulator","./vss-simulator/VSS-Simulator/build/vss-simulator"}, {"VSS-Sample","./vss-simulator/VSS-SampleCpp/build/vss-sample"}, /*{"VSS-Sample","./vss-simulator/VSS-SampleCpp/build/vss-sample -t blue"},*/ {"VSSS-ERUS", "./build/vsss-erus"}, {"VSS-Viewer","./vss-simulator/VSS-Viewer/build/vss-viewer"}}
#define tam 4

bool desejaRodar();
void roda(char*);

int main(int argc, char const *argv[])
{
    char* Rodavel[][2] = rodavelList;
    pid_t filhos[tam];

    cout << "VSS-Simulator by Rodetas e RobôCIn\n" << endl;
    cout << "Verifique se todos os programas do simulador estão devidamente instalados" << endl;
    cout << "Deseja rodar o Simulador?" << endl;

    if(!desejaRodar()){
        cout << "Finalizando.." << endl;
        return 0;
    }

    for(int i = 0; i < tam; i++){
        cout << "Deseja rodar "<< Rodavel[i][0] << "?" << endl;
        if(desejaRodar()){
            pid_t filho = filhos[i] = fork();
            //O pai entra nesse bloco
	        if(filho > 0){
                continue;
	        }
            //O filho entra nesse bloco
            else if(filho == 0){
                freopen("log.txt", "w", stdout);
                freopen("log.txt", "w", stderr);
                roda((char *)Rodavel[i][1]);
            }
            //Erro de fork
            else{
                printf("Erro ao criar novo processo\n");
	            printf("Erro %d - %s\n", errno, strerror(errno));
            }
        }
    }

    while(wait(NULL) > 0);

    return 0;
}

bool desejaRodar(){
    char deseja;
    do{
        cout << "[s]/[n]: ";
        cin >> deseja;
        if(deseja == 's' || deseja == 'S') {return true;}
        else if (deseja == 'n' || deseja == 'N'){return false;}
    }while(true);
}

void roda(char* rodavel){
    ListaComandos* lista = newListaComandos(rodavel);
    execvp(getComando(lista, 0),getArgs(lista, 0));
    printf("Erro de exec:\n");
	printf("Erro %d - %s\n", ENOENT, strerror(ENOENT));
    exit(-1);
}