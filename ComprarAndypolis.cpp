//
// Created by ydsas on 4/12/2021.
//

#include "ComprarAndypolis.h"
ComprarAndypolis::ComprarAndypolis(){
    this->andycoins_juntadas = 0;
    this->cantidad_andycoins_objetivo = 100000;
}

void ComprarAndypolis::actualizar(int valor) {
    this->andycoins_juntadas += valor;
}

bool ComprarAndypolis::checkear() {

    return (this->andycoins_juntadas >= this->cantidad_andycoins_objetivo);
}

void ComprarAndypolis::mostrar_progreso() {
    cout << "Andycoins conseguidos a lo largo del partido es: " << this->andycoins_juntadas << endl;
}

