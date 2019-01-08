/*
 * goleirobehavior.cpp
 *
 *  Created on: 10 de dez de 2018
 *      Author: ERUS
 */

#include "goleirobehavior.h"

GoleiroBehavior::GoleiroBehavior() {}

GoleiroBehavior::~GoleiroBehavior() {}

Ponto GoleiroBehavior::movimenta(Ponto posicao, World* mundo){
	/*pair<double,double> predicaoBola = mundo->getBall()->predicao_adaptativa();
	int posx, posy;


	xp, yp = world.get_ball().predict_ball_method(self)
	#adiciona_ponto(int(xp), int(yp), 255, 0, 102, 'bola prevista')

	posx = world.get_team_goal()[0] + 10

	'''
	theta_r = math.atan2(float(world.get_ball().gety() - world.trave_left_upper[1]),
						 float(world.get_ball().getx() - (world.trave_left_upper[0])))
	theta_s = math.atan2(float(world.get_ball().gety() - world.trave_left_lower[1]),
						 float(world.get_ball().getx() - (world.trave_left_lower[0])))
	'''

	theta_r = math.atan2(float(yp - world.trave_left_upper[1]),
						 float(xp - (world.trave_left_upper[0])))
	theta_s = math.atan2(float(yp - world.trave_left_lower[1]),
						 float(xp - (world.trave_left_lower[0])))

	m_bissetriz = math.tan((theta_r + theta_s) / 2.0)

	#bissetriz = -m_bissetriz * (world.get_ball().getx() - posx) + world.get_ball().gety()
	bissetriz = -m_bissetriz * (xp - posx) + yp

	#posy = (bissetriz + world.get_ball().gety()) * 0.5
	#posy = (bissetriz*3 + world.get_ball().gety()) /4.0
	posy = (bissetriz*3 + yp) /4.0

	if(abs(posx - world.get_ball().getx()) < 30):
		#posy = world.get_ball().gety()
		posy = yp
		#print posy
	if posy < world.trave_left_upper[1] - 1.8:
		posy = world.trave_left_upper[1] - 1.8
		posx -= 3
	if posy > world.trave_left_lower[1] + 1.8:
		posx -= 3
		posy = world.trave_left_lower[1] + 1.8

	# kc = 0.1 #kc define a curvatura do trajeto de setpoint do goleiro
	# posx = world.get_team_goal()[0] - 30 + abs(kc*(posy - world.get_team_goal()[1]))

		# cv2.circle(frame,(   int(posx)   , int(posy)   ),5,(200,100,100),-1)

	'''
	posicaox[1] = posicaox[0] #guarda posicao antiga da bolinha
	posicaox[0] = world.get_ball().getx() #atualiza posicao atual da bolinha

	posicaoy[1] = posicaoy[0]
	posicaoy[0] = world.get_ball().gety()

	posicaox[3] = posicaox[2] #guarda posicao antiga do setpoint
	posicaox[2] = posx #atualiza posicao atual do setpoint

	posicaoy[3] = posicaoy[2]
	posicaoy[2] = posy

	#print "Antigo" , posicaoy[1]
	#print "Novo", posicaoy[0]

	print "Vetor velocidade da bolinha (", posicaox[0] - posicaox[1] , "       ", posicaoy[0] - posicaoy[1], ")"
	print "Vetor velocidade do setpoint (", posicaox[2] - posicaox[3] , "       ", posicaoy[2] - posicaoy[3], ")"

	'''
	adiciona_ponto(int(world.trave_left_upper[0]), int(world.trave_left_upper[1]),255,255,2555,'xg+20, yg')
	adiciona_ponto(int(world.trave_left_lower[0]), int(world.trave_left_lower[1]),255,255,2555,'xg+20, yg')
	#print 'goleiro : ',posx, posy
	return posx , posy # coordenadas que o goleiro deve ficar
	 */
	//return Ponto(posx, posy);
	return Ponto();
}

std::pair<int,int> GoleiroBehavior::controle(Ponto posicao, World* mundo){
	/*
	pd = world.get_goalkeeper()
	xfront , yfront = pd.get_front()  #unidade das coordenadas eh cm
	xback , yback = pd.get_back()  #unidade das coordenadas eh cm
	pd_x , pd_y = pd.getx() , pd.gety()  #unidade das coordenadas eh cm
	#xb, yb = world.get_ball().getxy()
	xb, yb = self.defende(world) # coordenadas que o goleiro deve ficar

	'''if(math.sqrt((xb - pd_x)/100, (yb - pd_y)/100) < 0.05 or start):
		start = False
		xb = self.position_x.pop()
		yb = self.position_y.pop()
	'''
	theta_jog = self.get_theta()
	theta_ball = math.atan2(yb,xb) # unidade rad

	# matriz de rotacao e matriz de translacao que colocar o eixo de coordanadas no robo alinhado com o theta, e calcula o angulo de erro
	M_rot = np.array([[math.cos(theta_jog), math.sin(theta_jog)], [-math.sin(theta_jog), math.cos(theta_jog)]])
	M_trans =  np.array([[pd_x], [pd_y]])
	oldcoords_bola = np.array([[xb], [yb]])
	newcoords_bola = M_rot.dot(oldcoords_bola - M_trans)

	# erro robo bola baseado
	theta_erro = math.atan2(newcoords_bola[1][0], newcoords_bola[0][0])

	#distancia das rodas em metros
	D = 0.075

	#tempo de amostragem
	T = 30

	#dado o sistema y = pseudoA*Matriz_erro obtem-se y que eh a velocidade da roda direita e velocidade da roda esquerda
	A = np.array([[math.cos(theta_jog)/2, math.cos(theta_jog)/2], [math.sin(theta_jog)/2, math.sin(theta_jog)/2],[1/D, -1/D]])
	pseudoA = np.linalg.pinv(A)
	Matriz_erro = (T)*np.array([[(xb - pd_x)/100], [(yb - pd_y)/100], [theta_erro]])
	y = pseudoA.dot(Matriz_erro)
	vmax = max(abs(y[0][0]), abs(y[1][0])) # paga a maior velocidade

	#como a velocidade foi parametrizada pela maior, K eh a maior velocidade que a roda pode assumir
	K = 100
	vr, vl = y[0][0]*K/vmax, y[1][0]*K/vmax  #mudei a constante para 255 antes era 100

	return int(vr), int(vl)
	*/
}
