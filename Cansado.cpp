//
// Created by ydsas on 4/12/2021.
//

#include "Cansado.h"
Cansado::Cansado(Jugador jugador) {
    this->energia = jugador.devolver_energia();
    this->energia_minima = 0;
    this->cumplio = false;

}

void Cansado::mostrar(){
    cout << "Cansado: terminar un turno con 0 de energía." << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}

void Cansado::actualizar(int valor) {
    this->energia = valor;
}

bool Cansado::checkear() {
    if (this->energia == this->energia_minima){
        this->cumplio = true;
    }
    return this->cumplio;
}

/*
void Cansado::mostrar_progreso() {
    if (this->cumplio){
        cout << "Ya terminaste tu turno con 0 puntos de energia por lo menos una vez." << endl;
    } else{
        cout << "Todavia no terminaste tu turno con 0 puntos de energia" << endl;
    }
}*/

int Cansado::calcular_progreso(){
    return 0;
}