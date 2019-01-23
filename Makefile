### Makefile ###

all:
	g++ -o Simulador Simulador.cpp vss-simulator/ListaComandos/ListaComandos.c

run:
	./Simulador

