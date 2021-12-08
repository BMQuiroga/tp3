//
// Created by ydsas on 4/12/2021.
//

#include "Bombardero.h"

Bombardero::Bombardero() {
    this->bombas_usadas = 0;
    this->bombas_objetivos = 5;
    this->cumplio = false;

}

void Bombardero::mostrar(){
    cout << "Bombardero: haber usado 5 bombas." << endl;
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

void Bombardero::mostrar_progreso() {
    cout << "Bombas usadas a lo largo del partido es: " << bombas_usadas << endl;
}