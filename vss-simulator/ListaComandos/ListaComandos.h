/*
 * ListaComandos.c
 *
 *  Created on: 27 de set de 2018
 *      Author: Lorena
 */

#ifndef LISTACOMANDOS_C_
#define LISTACOMANDOS_C_


typedef struct lComands ListaComandos;

ListaComandos* newListaComandos(char* linha);

ListaComandos* deleteListaComandos(ListaComandos* comandos);

void insereComandos(ListaComandos* comandos, char* cmd);

int getNComandos(ListaComandos* comandos);

char* getComando(ListaComandos* comandos, int Index);

char** getArgs(ListaComandos* comandos, int Index);

int verificarComando(ListaComandos* lista);//1 para exit, -1 para waitz e 0 para comando normal

#endif /* LISTACOMANDOS_C_ */
