//
// Created by ydsas on 4/12/2021.
//

#include "Bombardero.h"

Bombardero::Bombardero() {
    this->nombre="Bombardero";
    this->bombas_usadas = 0;
    this->bombas_objetivos = 5;
    this->cumplio = false;

}

Bombardero::~Bombardero() {}

void Bombardero::mostrar(){
    cout << "Bombardero: haber usado 5 bombas." << endl;
    cout << "Bombas usadas: " << calcular_progreso() << "/5" << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}

void Bombardero::actualizar(int valor) {
    this->bombas_usadas += valor;
}

bool Bombardero::checkear() {
    if (this->bombas_usadas >= this->bombas_objetivos){
        this->cumplio = true;
    }
    return this->cumplio;
}

int Bombardero::calcular_progreso(){
    return bombas_usadas;
}
