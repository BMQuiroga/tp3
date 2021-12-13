#include <iostream>
#include <string>
#include "casillero.h"

/*bool Casillero::esta_ocupado(){

}
std::string Casillero::contenido(){
    
}*/

/*Casillero::Casillero(){
    this->coordenada_x=0;
    this->coordenada_y=0;

}
Casillero::Casillero(int coord_x, int coord_y){
    this->coordenada_x=coord_x;
    this->coordenada_y=coord_y;

}*/

Casillero::Casillero() {}

Casillero::~Casillero() {}

void Casillero::setear_id(int id) {
    this->id = id;
}

int Casillero::obtener_id() {
    return this->id;
}

char Casillero::devolver_tipo(){
    return this->tipo;

}

char Casillero::devolver_tipo_camino() {
    return this->letra;
}