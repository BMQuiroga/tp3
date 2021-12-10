//
// Created by ydsas on 4/12/2021.
//

#include "Energetico.h"

Energetico::Energetico(Jugador * jugador) {
    this->nombre="Energetico";
    this->jugador = jugador;
    this->energia = jugador->devolver_energia();
    this->energia_maxima = 100;
    this->cumplio = false;
}

void Energetico::mostrar(){
    cout << "Energético: haber terminado un turno con 100 puntos de energía. " << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}

bool Energetico::checkear() {
    if (jugador->devolver_energia() >= this->energia_maxima){
        this->cumplio = true;
    }
    return this->cumplio;
}

int Energetico::calcular_progreso(){
    return 0;
}
/*
void Energetico::mostrar_progreso() {
    if (this->cumplio){
        cout << "Ya terminaste tu turno con 100 puntos de energia por lo menos una vez." << endl;
    } else{
        cout << "Todavia no terminaste tu turno con 100 puntos de energia" << endl;
    }
}*/