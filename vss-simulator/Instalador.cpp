/*
 ============================================================================
 Name        : Instalador.cpp
 Author      : Lorena
 Version     : V 1.0
 Description : 
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

#define InstalavelList {"VSS-Core", "VSS-Simulator", "VSS-Viewer", "VSS-SampleCpp", "../VSSSERUS"}
#define tam 5

using namespace std;

bool desejaInstalar();
void instala(char*);

int main(int argc, char const *argv[])
{
    char* Instalavel[] = InstalavelList;

    cout << "Instalador VSS-Simulator by Rodetas e RobôCIn\n" << endl;
    cout << "Verifique se:\n\t*Sua distribuição linux encontra-se em todos os arquivos configure.sh\n\t*Se o seu computador possui git, CMake e Boost\n\t*Se nenhuma biblioteca está faltando" << endl;
    cout << "\nLembre-se de rodar este programa com sudo\n" << endl;
    cout << "Deseja instalar o VSS-Simulator?" << endl;

    if(!desejaInstalar()){
        cout << "Finalizando.." << endl;
        return 0;
    }

    for(int i = 0; i < tam; i++){
        cout << "Deseja instalar "<< Instalavel[i] << "?" << endl;
        if(desejaInstalar()){
            instala(Instalavel[i]);
        }
    }
    return 0;
}

bool desejaInstalar(){
    char deseja;
    do{
        cout << "[s]/[n]: ";
        cin >> deseja;
        if(deseja == 's' || deseja == 'S') {return true;}
        else if (deseja == 'n' || deseja == 'N'){return false;}
    }while(true);
}

void instala(char* instalar){
    pid_t filho = fork();
	
	//O pai entra nesse bloco
	if(filho > 0){
        int status;
        while(wait(&status) > 0);
        return;
	}

	//O filho entra nesse bloco
	else if(filho == 0){
        chdir(instalar);
        char *args[]={"./configure.sh",NULL}; 
        execvp(args[0],args);
        printf("Erro de exec:\n");
		printf("Erro %d - %s\n", ENOENT, strerror(ENOENT));
        exit(-1);
    }
	//Erro no fork
    else if (filho < 0){
        printf("Erro ao criar novo processo\n");
	    printf("Erro %d - %s\n", errno, strerror(errno));
    }
}