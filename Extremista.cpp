//
// Created by ydsas on 4/12/2021.
//

#include "Extremista.h"
#include <iostream>


Extremista::Extremista() {
    this->nombre="Extremista";
    this->bombas_compradas = 0;
    this->bombas_necesarias = 500;
    this->cumplio = false;
}

void Extremista::mostrar(){
    std::cout << "Extremista: haber comprado 500 bombas en una partida." << std::endl;
    std::cout << "Bombas compradas: " << calcular_progreso() << "/500" << std::endl;
    if(checkear())
        std::cout << "Este objetivo ha sido completado" << std::endl;
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

/*
void Extremista::mostrar_progreso() {
    cout << "la cantidad de bombas comprada es: " << this->bombas_compradas << endl;
}*/

int Extremista::calcular_progreso(){
    return this->bombas_compradas;
}
