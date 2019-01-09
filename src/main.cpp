#include <iostream>
#include <iterator>
#include "world.h"
#include "camera.h"

/* ###############################################################################################################
 * Projeto: VSSS o Melhor
 * Github: https://github.com/erusbot/VSSS-o-Melhor
 * Autor: ERUS UFES
 * 				e-mail: erus@inf.ufes.br
 * 				site: erus.ufes.br
 * Membros:
 * 			Gabriel Valdino, Lara de Luca, Lorena Bassani, Ricardo Rauta, Victor de Oliveira
 */

using namespace std;

int main(int argc, char **argv) {

	char a = '0';
	Campo campo(&a);

	Ball B1(5.0, 5.0);
	B1.set_position(10, 10);
	B1.set_position(15, 15);
	B1.set_position(20, 20);
	B1.set_position(25, 25);
	B1.set_position(30, 30);

	Ball B2(3.0, 9.0);
	B2.set_position(5, 8);
	B2.set_position(7, 7);
	B2.set_position(9, 6);
	B2.set_position(11, 5);
	B2.set_position(13, 4);

	Ball B3(0, -0.5);
	B3.set_position(1, 1.5);
	B3.set_position(4, -4.5);
	B3.set_position(9, -36.5);
	B3.set_position(16, -112.5);
	B3.set_position(25, -250.5);

	Player* P1 = new TeamPlayer(Funcao::Goleiro, 1, 15);
	Player* P2 = new TeamPlayer(Funcao::Atacante, 2, 90);

	cout << P1->getId() << P2->getId() << endl;

	cout << "X:  " << B3.getPonto().getX() << "  Y:  " << B3.getPonto().getY() << endl;
	pair<double, double> R = B3.predicao_adaptativa();
	cout << "< " << R.first << ", " << R.second << " >" << endl;
	B3.set_position(R.first, R.second);

	for(unsigned int j = 0; j != B3.getxy_old().size(); ++j){
		cout << B3.getxy_old()[j].getX() << "/" << B3.getxy_old()[j].getY() << " ";
	}
	cout << endl;

	R = B3.predicao_adaptativa();
	cout << "< " << R.first << ", " << R.second << " >" << endl;
	B3.set_position(R.first, R.second);
	for(unsigned int j = 0; j != B3.getxy_old().size(); ++j){
			cout << B3.getxy_old()[j].getX() << "/" << B3.getxy_old()[j].getY() << " ";
		}
		cout << endl;

	return 1;
}

