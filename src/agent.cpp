#include "agent.h"


namespace vsssERUS {
	double** ajusteDeCurva(vector<Ponto> vet, int grau);


	float Agent::distancia(Agent& agente) const {
		return this->getPosicao().distancia(agente.getPosicao());
	}

	Agent::Agent(double x, double y)
	{
		posicao = Ponto(x, y);
		for(int i = 0; i < 5; i++){
			posicoesAnteriores.push_back(Ponto(0.0, 0.0));
		}
	}

	Agent::Agent(Ponto ponto){
		posicao = ponto;
		for(int i = 0; i < 5; i++){
			posicoesAnteriores.push_back(Ponto(0.0, 0.0));
		}
	}

	vector<Ponto> Agent::getxyOld() const{
		return this->posicoesAnteriores;
	}

	// Faz a previsão de uma futura posição da bola/player
	std::pair<double, double> Agent::previsaoDePosicao() const{
		double Kx1, Kx2, Kx3, Kx4, Ky1, Ky2, Ky3, Ky4, t;
		int i;
		pair<double, double> ponto_futuro;

		// f[][0]: X = f(t), f[][1]: Y = g(t) <------- DE SUMA IMPORTÂNCIA PARA ENTENDER O CÓDIGO, na maioria dos casos, [0] denota X e [1] denota Y
		double f[4][2];
		double** AUXf = ajusteDeCurva(posicoesAnteriores, 4);
		for(i = 0; i < 4; i++){
			f[i][0] = AUXf[0][i+1]*(i+1);
			f[i][1] = AUXf[1][i+1]*(i+1);
		}
		free(AUXf[0]); // Confira se está liberando memória corretamente
		free(AUXf[1]);
		free(AUXf);

		// Previsão via método de Runge-Kutta de 4ª ordem
		t = 5;
		double hx = 1;
		Kx1 = f[0][0] + f[1][0] * t + f[2][0] * pow(t, 2) + f[3][0] * pow(t, 3);
		Kx2 = f[0][0] + f[1][0] * (t + hx/2) + f[2][0] * pow(t + hx/2, 2) + f[3][0] * pow(t + hx/2, 3);
		Kx3 = Kx2;
		Kx4 = f[0][0] + f[1][0] * (t + hx) + f[2][0] * pow(t + hx, 2) + f[3][0] * pow(t + hx, 3);


		double hy = 1;
		Ky1 = f[0][1] + f[1][1] * t + f[2][1] * pow(t, 2) + f[3][1] * pow(t, 3);
		Ky2 = f[0][1] + f[1][1] * (t + hy/2) + f[2][1] * pow(t + hy/2, 2) + f[3][1] * pow(t + hy/2, 3);
		Ky3 = Ky2;
		Ky4 = f[0][1] + f[1][1] * (t + hy) + f[2][1] * pow(t + hy, 2) + f[3][1] * pow(t + hy, 3);

		ponto_futuro.first = posicao.getX() + ((hx/6) * (Kx1 + 2*Kx2 + 2*Kx3 + Kx4));
		ponto_futuro.second = posicao.getY() + ((hy/6) * (Ky1 + 2*Ky2 + 2*Ky3 + Ky4));
		// Fim da previsão pelo método de Runge-Kutta de 4ª ordem

		return ponto_futuro;
	}

	void Agent::updatePosition(double x, double y){
		this->posicoesAnteriores.erase(this->posicoesAnteriores.begin());
		this->posicoesAnteriores.push_back(this->getPosicao());
		posicao.setX(x);
		posicao.setY(y);
	}

	void Agent::updatePosition(Ponto ponto){
		this->posicoesAnteriores.erase(this->posicoesAnteriores.begin());
		this->posicoesAnteriores.push_back(this->getPosicao());
		posicao.setX(ponto.getX());
		posicao.setY(ponto.getY());
	}

	Ponto Agent::getPosicao() const{
		return this->posicao;
	}

	/* Função que descobre a curva de grau 'grau' que melhor descreve os pontos presentes em 'vet'
	* Ela retorna os coeficientes (B0, B1, B2, ..., Bgrau-1, Bgrau) da equação B0 + B1*t + B2*t² + ... + Bgrau*t^grau
	* Essa função foi desenvolvida pensando em descobrir os valores das posições X e Y num tempo t, logo, ela ocorre "duas vezes" 
	* (na mesma chamada da função) para realizar esse processo mais rapidamente 
	*/
	double** ajusteDeCurva(vector<Ponto> vet, int grau){

		// Separação dos pontos em coordenadas independentes
		vector<double> vetX, vetY;

		// vetOut[0]: coeficientes de X = f(t), vetOut[1]: coeficientes de Y = g(t)
		double** vetOut = (double**)malloc(2*sizeof(double**));
		for(unsigned k = 0; k != vet.size(); ++k){
			vetOut[0] = (double*)calloc(grau, sizeof(double));
			vetOut[1] = (double*)calloc(grau, sizeof(double));
			vetX.push_back(vet[k].getX());
			vetY.push_back(vet[k].getY());
		}

		// Resolução via ajuste polinomial
		// MatrixX = Matrix[0] e MatrixY = Matrix[1]
		double** Matrix[2];
		Matrix[0]  = (double**)malloc((grau+1)*sizeof(double*));
		Matrix[1]  = (double**)malloc((grau+1)*sizeof(double*));
		// Faz Matrix[i][j] = somatório(vet^(i+j))
		for(int i = 0; i <= grau; i++){
			Matrix[0][i] = (double*)calloc((grau+1),sizeof(double));
			Matrix[1][i] = (double*)calloc((grau+1),sizeof(double));
			for(int j = 0; j <= grau; j++){
				for(unsigned k = 0; k != vet.size(); k++){
					Matrix[0][i][j] += pow(k,i+j);
					Matrix[1][i][j] += pow(k,i+j);
				}
			}
		}

		// vetorX = vetor[0] e vetorY = vetor[1]
		double vetor[2][grau + 1];

		// Faz vetor = somatório(tj*vetj^i)
		for(int i = 0; i <= grau; i++){
			vetor[0][i] = 0;
			vetor[1][i] = 0;
			for(unsigned j = 0; j != vet.size(); j++){
				vetor[0][i] += vetX[j]*pow(j, i);
				vetor[1][i] += vetY[j]*pow(j, i);
			}
		}

		vector<double> aux0 = Ponto::resolucaoDeSistemaLinear(Matrix[0], vetor[0], grau+1);
		vector<double> aux1 = Ponto::resolucaoDeSistemaLinear(Matrix[1], vetor[1], grau+1);

		// Passo com o único intuito de arredondar valores muito pequenos e próximos de zero
		for(int i = 0; i <= grau; i++){
			if(aux0[i] < 0.001 && aux0[i] > -0.001){
				aux0[i] = 0;
			}
			if(aux1[i] < 0.001 && aux1[i] > -0.001){
				aux1[i] = 0;
			}
			vetOut[0][i] = aux0[i];
			vetOut[1][i] = aux1[i];
		}


		for(int i = 0; i <= grau; i++){
			free(Matrix[0][i]);
			free(Matrix[1][i]);
		}

		free(Matrix[0]);
		free(Matrix[1]);
		// Fim da resolução via ajuste polinomial

		return vetOut;
	}
}