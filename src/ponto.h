#ifndef PONTO_H
#define PONTO_H
/* Nome do m�dulo: Ponto
 * Ano de cria��o: 2018/10
 * Descri��o do m�dulo: Cria��o dos pontos mais uma fun��o extra para resolver sistemas lineares de ordem N
 * Vers�o: 1.1
 * Pr�-requisitos: Coordenadas dos pontos n�o negativas
 * Membros: Ricardo Ramos, Gabriel Valdino
 */
#include <cmath>
#include <vector>
#include <iostream>
#include <cstdio>
#define DOUBLE_CMP_THRESHOLD 0.000000000000001

using namespace std;

namespace vsssERUS {
class Ponto
{
	double x;
	double y;
public:
	Ponto(double x = 0, double y = 0);

	/* distancia
	* Inten��o da fun��o:
	* Pr�-requisitos:
	* Efeitos colaterais:
	* Parametros:
	* Retorno:
	*/
	double distancia(Ponto outro) const;

	/* getX
	* Inten��o da fun��o:
	* Pr�-requisitos:
	* Efeitos colaterais:
	* Parametros:
	* Retorno:
	*/
	double getX() const;

	/* getY
	* Inten��o da fun��o:
	* Pr�-requisitos:
	* Efeitos colaterais:
	* Parametros:
	* Retorno:
	*/
	double getY() const;

	/* setX
	* Inten��o da fun��o:
	* Pr�-requisitos:
	* Efeitos colaterais:
	* Parametros:
	* Retorno:
	*/
	void setX(double x);

	/* setY
	* Inten��o da fun��o:
	* Pr�-requisitos:
	* Efeitos colaterais:
	* Parametros:
	* Retorno:
	*/
	void setY(double y);

	/* resolucaoDeSistemaLinear
	* Inten��o da fun��o:
	* Pr�-requisitos:
	* Efeitos colaterais:
	* Parametros:
	* Retorno:
	*/
	//Resolu��o do sistema Ax = b, sendo A = matrix, b = vetor, N = ordem de matrix
	//Aten��o � chamada da fun��o, pois ela precisa de um "double** A" e n�o um "double A[N][N]", logo, � necess�rio o uso de mallocs
	//Cr�ditos � professora Cl�udia Galarda Varassin pela cria��o da fun��o que foi poucamente modificada para atender � nossos anseios
	static vector<double> resolucaoDeSistemaLinear(double** matrix, double* vetor, int N);

	bool operator==(Ponto const &p);
};
} // vsssERUS
#endif // PONTO_H
