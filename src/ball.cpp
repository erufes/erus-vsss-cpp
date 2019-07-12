#include "ball.h"
#include <iostream>

vsssERUS::Ball::Ball(double x, double y) : vsssERUS::Agent(x,y)
{

}

vsssERUS::Ball::Ball(Ponto p) : vsssERUS::Agent(p){

}

//Favor comentar o que este c�digo est� fazendo
//Ponto vsssERUS::Ball::predict_ball_method(Player* jogador){
//    double x_ball_predic, y_ball_predic;
//    double mx = 0, my = 0;
//    for(int i = 0;i < 5; i++){
//        mx += old[i].getX();
//        my += old[i].getY();
//    }
//    mx /= 5;
//    my /= 5;
//    cout << "mx:  " << mx << "  my:  " << my << endl;
//
//    double vx_ball, vy_ball;
//    vx_ball = (this->getPonto().getX() - mx)/2.0;
//    vy_ball = (this->getPonto().getY() - my)/2.0;
//
//    double norm_v_ball = sqrt(vx_ball*vx_ball + vy_ball*vy_ball);
//    cout << "Normal:  " << norm_v_ball << endl;
//
//    if(norm_v_ball < 2){
//        x_ball_predic = this->getPonto().getX();
//        y_ball_predic = this->getPonto().getY();
//    }else{
//        vx_ball /= norm_v_ball;
//        vy_ball /= norm_v_ball;
//
//        double dif_x = this->getPonto().getX()-jogador->getPonto().getX();;
//        double dif_y = this->getPonto().getY()-jogador->getPonto().getY();
//        double ro_aux = sqrt(dif_x*dif_x + dif_y*dif_y);
//
//        double c_magic = 4;
//        double k_pred = c_magic*ro_aux/100.0;
//
//        x_ball_predic = this->getPonto().getX() + vx_ball * k_pred * norm_v_ball;
//        y_ball_predic = this->getPonto().getY() + vy_ball * k_pred * norm_v_ball;
//    }
//    return Ponto(x_ball_predic, y_ball_predic);
//}
//
//
////Favor comentar o que este c�digo est� fazendo
//Ponto vsssERUS::Ball::predict_ball_method_ofensive(Player* jogador){
//    double x_ball_predic, y_ball_predic;
//    double mx = 0, my = 0;
//    for(int i = 0;i < 5; i++){
//        mx += old[0].getX();
//        mx += old[0].getY();
//    }
//    mx /= 5;
//    my /= 5;
//
//    double vx_ball, vy_ball;
//    vx_ball = (this->getPonto().getX() - mx)/2.0;
//    vy_ball = (this->getPonto().getY() - my)/2.0;
//
//    double norm_v_ball = sqrt(vx_ball*vx_ball + vy_ball*vy_ball);
//
//    if(norm_v_ball == 0)
//        norm_v_ball = 1;
//    vx_ball /= norm_v_ball;
//    vy_ball /= norm_v_ball;
//
//    double dif_x = this->getPonto().getX()-jogador->getPonto().getX();;
//    double dif_y = this->getPonto().getY()-jogador->getPonto().getY();
//    double ro_aux = sqrt(dif_x*dif_x + dif_y*dif_y);
//
//    double c_magic = 1;
//    //double c_magic = predicao_adaptativa();
//    double k_pred = c_magic*ro_aux/85.0;
//
//    x_ball_predic = this->getPonto().getX() + vx_ball * k_pred * norm_v_ball;
//    y_ball_predic = this->getPonto().getY() + vy_ball * k_pred * norm_v_ball;
//    return Ponto(x_ball_predic, y_ball_predic);
//}




