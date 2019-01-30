### Makefile Do projeto VSSS-o-Melhor###

all: Simulador

ponto.o: ponto.h ponto.cpp
	g++ -c agent.cpp

agent.o: agent.h agent.cpp
	g++ -c agent.cpp

ball.o: ball.h ball.cpp
	g++ -c ball.cpp

player.o: player.h player.cpp
	g++ -c player.cpp

enemy.o: enemy.h enemy.cpp
	g++ -c enemy.cpp

teamplayer.o: teamplayer.h teamplayer.cpp
	g++ -c teamplayer.cpp

playbehavior.o: playbehavior.h playbehavior.cpp
	g++ -c playbehavior.cpp

ataquebehavior.o: ataquebehavior.h ataquebehavior.cpp
	g++ -c ataquebehavior.cpp

goleirobehavior.o: goleirobehavior.h goleirobehavior.cpp
	g++ -c goleirobehavior.cpp

defesabehavior.o: defesabehavior.h defesabehavior.cpp
	g++ -c defesabehavior.cpp

campo.o: campo.h campo.cpp
	g++ -c campo.cpp

world.o: world.h world.cpp
	g++ -c world.cpp

Simula.o: mainSimulacao.cpp
	g++ -c mainSimulacao.cpp

Simulador: ponto.o agent.o ball.o player.o enemy.o teamplayer.o playbehavior.o ataquebehavior.o goleirobehavior.o defesabehavior.o campo.o world.o senderCommands.hpp senderDebug.hpp
	g++ -o Simulador ponto.o agent.o ball.o player.o enemy.o teamplayer.o playbehavior.o ataquebehavior.o goleirobehavior.o defesabehavior.o campo.o world.o Simula.o

VSSS: ponto.o agent.o ball.o player.o enemy.o teamplayer.o playbehavior.o ataquebehavior.o goleirobehavior.o defesabehavior.o campo.o world.o

clean: 
	rm -rf *.o

mrproper: clean
	rm -rf Simulador
