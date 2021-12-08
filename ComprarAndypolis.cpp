//
// Created by ydsas on 4/12/2021.
//

#include "ComprarAndypolis.h"
ComprarAndypolis::ComprarAndypolis(){
    this->andycoins_juntadas = 0;
    this->cantidad_andycoins_objetivo = 100000;
    this->cumplio = false;
}

void ComprarAndypolis::actualizar(int valor) {
    this->andycoins_juntadas += valor;
}

bool ComprarAndypolis::checkear() {

    if (this->andycoins_juntadas >= this->cantidad_andycoins_objetivo){
        this->cumplio = true;
    }
    return cumplio;
}

void ComprarAndypolis::mostrar_progreso() {
    cout << "Andycoins conseguidos a lo largo del partido es: " << this->andycoins_juntadas << endl;
}

void ComprarAndypolis::mostrar(){
    cout << "Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida (las monedas gastadas también cuentan para este objetivo)" << endl;
}
