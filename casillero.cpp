#include <iostream>
#include <string>
#include "casillero.h"


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
