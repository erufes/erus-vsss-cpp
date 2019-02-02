#include <iostream>
#include <iterator>
#include "world.h"
#include "camera.h"

/* ###############################################################################################################
 * Projeto: VSSS o Melhor
 * Github: https://github.com/erusbot/VSSS-o-Melhor
 * Autor: ERUS UFES
 * 				e-mail: erus@inf.ufes.br, vssserus@gmail.com
 * 				site: erus.ufes.br
 * Membros:
 * 			Gabriel Valdino, Lara de Luca, Lorena Bassani, Ricardo Rauta, Victor de Oliveira
 */

using namespace std;
using namespace vsssERUS;

int main2(int argc, char **argv) {

	char* y = "tst.txt";
	cout << y << endl;
	Campo c(y);

	Ponto p(-1, 1);
	if(c.estaDentroDoCampo(p)){
		cout << "Est�!" << endl;
	} else {
		cout << "N�o est�!" << endl;
	}

	c.setLado(1);
	if(c.getLado() == 0){
		cout << "Esquerdo" << endl;
	} else if(c.getLado() == 1){
		cout << "Direito" << endl;
	} else {
		cout << "Que lado � esse?" << endl;
	}

	cout << "Borda Superior: " << c.getBordaSuperior() << endl;
	cout << "Borda Inferior: " << c.getBordaInferior() << endl;
	cout << "Borda Direita: " << c.getBordaDireita() << endl;
	cout << "Borda Esquerda: " << c.getBordaEsquerda() << endl;
	cout << "Meio do Campo: " << c.getMeioDeCampo().getX() << ", " << c.getMeioDeCampo().getY() << endl;
	cout << "Gol Aliado: " << c.getMeioDeGolAliado().getX() << ", " << c.getMeioDeGolAliado().getY() << endl;
	cout << "Gol Inimigo: " << c.getMeioDeGolInimigo().getX() << ", " << c.getMeioDeGolInimigo().getY() << endl;
	return 0;
}

