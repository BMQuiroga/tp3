#include "jugador.h"
#include <iostream>

Jugador::Jugador(int x,int y,int numero){
    mover_gratis(x,y);
    this->energia=50;
    this->nombre=numero;
    asignar_objetivos();
}

void Jugador::mover_gratis(int x, int y){
    this->coordenada_x=x;
    this->coordenada_y=y;
}