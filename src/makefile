### Makefile Do projeto VSSS-o-Melhor###

all: Simulador

ponto.o: ponto.h ponto.cpp
	g++ -cpp agent.cpp

agent.o: agent.h agent.cpp
	g++ -cpp agent.cpp

ball.o: ball.h ball.cpp
	g++ -cpp ball.cpp

player.o: player.h player.cpp
	g++ -cpp player.cpp

enemy.o: enemy.h enemy.cpp
	g++ -cpp enemy.cpp

teamplayer.o: teamplayer.h teamplayer.cpp
	g++ -cpp teamplayer.cpp

playbehavior.o: playbehavior.h playbehavior.cpp
	g++ -cpp playbehavior.cpp

ataquebehavior.o: ataquebehavior.h ataquebehavior.cpp
	g++ -cpp ataquebehavior.cpp

goleirobehavior.o: goleirobehavior.h goleirobehavior.cpp
	g++ -cpp goleirobehavior.cpp

defesabehavior.o: defesabehavior.h defesabehavior.cpp
	g++ -cpp defesabehavior.cpp

campo.o: campo.h campo.cpp
	g++ -cpp campo.cpp

world.o: world.h world.cpp
	g++ -cpp world.cpp

Simula.o: mainSimulacao.cpp
	g++ -cpp mainSimulacao.cpp

Simulador: ponto.o agent.o ball.o player.o enemy.o teamplayer.o playbehavior.o ataquebehavior.o goleirobehavior.o defesabehavior.o campo.o world.o senderCommands.hpp senderDebug.hpp
	g++ -o Simulador ponto.o agent.o ball.o player.o enemy.o teamplayer.o playbehavior.o ataquebehavior.o goleirobehavior.o defesabehavior.o campo.o world.o Simula.o

VSSS: ponto.o agent.o ball.o player.o enemy.o teamplayer.o playbehavior.o ataquebehavior.o goleirobehavior.o defesabehavior.o campo.o world.o

clean: 
	rm -rf *.o

mrproper: clean
	rm -rf Simulador