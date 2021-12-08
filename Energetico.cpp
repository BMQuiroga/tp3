//
// Created by ydsas on 4/12/2021.
//

#include "Energetico.h"

Energetico::Energetico(Jugador *jugador) {

    this->jugador = jugador;
}

void Energetico::mostrar(){
    cout << "Energético: haber terminado un turno con 100 puntos de energía. " << endl;
}