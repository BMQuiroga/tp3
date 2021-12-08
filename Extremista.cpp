//
// Created by ydsas on 4/12/2021.
//

#include "Extremista.h"
Extremista::Extremista() {

    this->bombas_compradas = 0;
    this->bombas_necesarias = 500;
    this->cumplio = false;
}

void Extremista::mostrar(){
    cout << "Extremista: haber comprado 500 bombas en una partida." << endl;
}

bool Extremista::checkear() {
    if (this->bombas_compradas >= this->bombas_necesarias){
        this->cumplio = true;
    }
    return cumplio;
}

void Extremista::actualizar(int valor) {
    this->bombas_compradas += valor;
}

void Extremista::mostrar_progreso() {
    cout << "la cantidad de bombas comprada es: " << this->bombas_compradas << endl;
}