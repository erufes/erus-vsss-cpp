//.cpp incompleto
#ifndef TEAMPLAYER_H
#define TEAMPLAYER_H
#include "player.h"
#include "ataquebehavior.h"
#include "defesabehavior.h"
#include "goleirobehavior.h"

class Ponto;

/* Nome do módulo: TeamPlayer
 * Ano de criação: 2018/12
 * Descrição do módulo: Classe que representa jogadores do time, criado para definir as funções de cada robô {Goleiro, Atacante, Defensor} e seus métodos de controle.
 * Versão: 1.1
 * Pré-requisitos: pré-requisitos de player
 * Membros: Ricardo Ramos
 */

enum Funcao{Goleiro, Atacante, Defensor};
class PlayBehavior;
class TeamPlayer: public Player
{
	PlayBehavior* comportamento;
    double distanciaMinDaParede;
public:
    TeamPlayer(Funcao comportamento, int id = 0,double theta = 0.0, double distanciaMinDaParede = 0.0);

    /* movimenta
	 * Intenção da função: Calcular onde o robô deverá ir
	 * Pré-requisitos: Comportamento correto
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Posição atual do robô
	 * Retorno: Posição para onde o robô deverá se movimentar
	 */
    Ponto movimenta(Ponto posicao, World* mundo);

    /* controle
	 * Intenção da função: Calcular velocidade do robô para ir até a posiçao desejada
	 * Pré-requisitos: Comportamento correto
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Posição para onde o robô deverá ir
	 * Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
	 */
    std::pair<int,int> controle(Ponto posicao, World* mundo);

    /* mudaComortamento
	 * Intenção da função: Mudar o comportamento do robô, para goleiro, atacante ou defensor
	 * Pré-requisitos: Nova função válida {Goleiro, Atacante, Defensor}
	 * Efeitos colaterais: Muda a funcionalidade das funções movimenta() e controle()
	 * Parametros: Funcao nova para o robô
	 * Retorno: Não possui retorno
	 */
    void mudaComportamento(Funcao novo);

    std::pair<double,double> predicao_adaptativa(){
    	return this->Player::predicao_adaptativa();
    };

    bool isEnemy(){
    	return false;
    };
};

#endif // TEAMPLAYER_H
