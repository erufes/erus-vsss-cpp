#include "teamplayer.h"
#include "campo.h"

namespace vsssERUS {

TeamPlayer::TeamPlayer(Funcao comportamento, int id, double theta, double distanciaMinDaParede) : Player(id, theta)
{
	//this->comportamento = NULL;
	this->mudaComportamento(comportamento);
	this->distanciaMinDaParede = distanciaMinDaParede;
}

Ponto TeamPlayer::movimenta(Ponto posicao, World* mundo){
	return comportamento->movimenta(posicao, mundo);
}

std::pair<int,int> TeamPlayer::controle(Ponto posicao, World* mundo){
	return comportamento->controle(posicao, mundo);
}

void TeamPlayer::mudaComportamento(Funcao novo){
	if (comportamento != NULL) delete comportamento;
	switch(novo){
		case Goleiro:
			comportamento = new GoleiroBehavior();
			break;
		case Atacante:
			comportamento = new AtaqueBehavior();
			break;
		case Defensor:
			comportamento = new DefesaBehavior();
			break;
	}
}

void TeamPlayer::adicionaPontoDeRepulsao(Ponto p) {
	this->campoPotencial[(int) ((p.getX()) / STEP_X)][(int) ((p.getY()) / STEP_Y)] = 1.0;
}

// i = intensidade do campo no ponto, -1 <= i <= 1
void TeamPlayer::adicionaPontoDeRepulsao(Ponto p, double i) {
	if(i < -1)
		i = -1;
	else if (i > 1)
		i = 1;
	this->campoPotencial[(int) ((p.getX()) / STEP_X)][(int) ((p.getY()) / STEP_Y)] = i;
}

void TeamPlayer::adicionaPontoDeAtracao(Ponto p) {
	this->campoPotencial[(int) ((p.getX()) / STEP_X)][(int) ((p.getY()) / STEP_Y)] = -1.0;
}

void TeamPlayer::adicionaPontoDeAtracao(Ponto p, double i) {
	if(i < -1)
		i = -1;
	else if (i > 1)
		i = 1;
	this->campoPotencial[(int) ((p.getX()) / STEP_X)][(int) ((p.getY()) / STEP_Y)] = -i;
}

// Impede que o robô bata na parede
void TeamPlayer::resetaBordasPotencial() {
	for(int i = 0; i < DISC_X; i++) {
		for(int j = 0; j < DISC_Y; j++) {
			if(i == 0 || j == 0 || i == DISC_X - 1 || j == DISC_Y - 1)
			this->campoPotencial[i][j] = 1.0;
		}
	}
}

/*
 * Seguindo a lógica da teoria aplicada no projeto, os pontos de atração têm associados
 * a eles um potencial negativo ("queda"), enquanto os pontos de repulsão têm associados
 * um potencial positivo. Com isso, a resultante deve apontar para longe dos obstáculos e
 * para perto dos objetivos. As bordas do campo também são obstáculos.
 */
void TeamPlayer::atualizaCampoPotencial() {
	Campo::dadosDoCampo d = campo->getPositions();
	// Em todo tick(), reseta a fronteira do domínio da análise
	this->resetaBordasPotencial();
	this->adicionaPontoDeAtracao(d.b);
	this->adicionaPontoDeRepulsao(d.f1);
	this->adicionaPontoDeRepulsao(d.f2);
	this->adicionaPontoDeRepulsao(d.f3);
	this->adicionaPontoDeRepulsao(d.e1);
	this->adicionaPontoDeRepulsao(d.e2);
	this->adicionaPontoDeRepulsao(d.e3);
	return;
}

void TeamPlayer::notifica() {
	// Ao receber notificação do evento, atualizar campo potencial
	this->atualizaCampoPotencial();
}

#ifdef UsingSimulator
	vss::WheelsCommand TeamPlayer::update(vss::State state, int index, World* mundo) {
		Utils::Posture objective = defineObjective(state, index, mundo);
		return motionControl(state, objective, index);
	}

	Utils::Posture TeamPlayer::defineObjective(vss::State, int index, World* mundo)
	{
		Ponto onde = this->movimenta(this->getPosicao(), mundo);
		Utils::Posture resp(onde.getX(), onde.getY(), M_PI/4.);
		// Retorne o objetivo aqui
		return Utils::Posture(10., 65.0, M_PI/4.);

		//Quando estiverem implementadas as funções de controles
		//return resp;
	}

	vss::WheelsCommand TeamPlayer::motionControl(vss::State state, Utils::Posture objective, int index){
		vss::WheelsCommand result;
		double  alpha, beta, rho, lambda;
		double linearSpeed, angularSpeed;

		double kRho = 1.85, kAlpha = 9.7, kBeta = -0.01;

		vss::Robot robot = (vss::TeamType::Blue == vss::TeamType::Blue) ? state.teamBlue[index] : state.teamYellow[index];

		robot.angle = Utils::to180range(robot.angle * M_PI / 180.0);

		rho = Utils::distance(doublePair(objective.x, objective.y), doublePair(robot.x, robot.y));

		lambda = atan2(objective.y - robot.y, objective.x - robot.x);

		if (rho < 3)
			lambda = 0;

		alpha = Utils::to180range(lambda - robot.angle);
		beta = -lambda + objective.angle;

		linearSpeed = -kRho * rho;
		angularSpeed = kAlpha * alpha + kBeta * beta;

		double constantSpeed = 60;
		double scale = constantSpeed / linearSpeed;
		linearSpeed *= scale;
		angularSpeed *= scale;

		if (rho < 3){
			linearSpeed = 0;
			angularSpeed *= 0.4;
		}

		if (fabs(alpha) > 0.5 * M_PI) {
			linearSpeed = -linearSpeed;
		}

		result.leftVel = (linearSpeed - angularSpeed * 3.35) / 2.;
		result.rightVel = (linearSpeed + angularSpeed * 3.35) / 2.;

		double maxSpeed = std::max(fabs(result.leftVel), fabs(result.rightVel));

		if (maxSpeed > 100) {
			result.leftVel *= 100 / fabs(maxSpeed);
			result.rightVel *= 100 / fabs(maxSpeed);
		}

		return result;
	};
#endif

} // vsssERUS