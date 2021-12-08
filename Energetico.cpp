//
// Created by ydsas on 4/12/2021.
//

#include "Energetico.h"

Energetico::Energetico(Jugador *jugador) {

    this->jugador = jugador;
    this->energia = jugador->devolver_energia();
    this->energia_maxima = 100;
    this->cumplio = false;
}

void Energetico::mostrar(){
    cout << "Energético: haber terminado un turno con 100 puntos de energía. " << endl;
}

void Energetico::actualizar(int valor) {
    this->energia = valor;
}

bool Energetico::checkear() {
    if (this->energia == this->energia_maxima){
        this->cumplio = true;
    }
    return this->cumplio;
}

void Energetico::mostrar_progreso() {
    if (this->cumplio){
        cout << "Ya terminaste tu turno con 100 puntos de energia por lo menos una vez." << endl;
    } else{
        cout << "Todavia no terminaste tu turno con 100 puntos de energia" << endl;
    }
}