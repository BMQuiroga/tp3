//
// Created by ydsas on 4/12/2021.
//

#include "Armado.h"

Armado::Armado(/*ListaMateriales materiales, */Jugador jugador) {
    this->cantidad_bombas = jugador.devolver_materiales().consulta(jugador.devolver_materiales().buscar_indice("bombas")).devolver_cantidad();
    this->cantidad_bombas_necesarias = 10;
    this->cumplio = false;
}

void Armado::mostrar(){
    cout << "Armado: tener 10 bombas en el inventario." << endl;
}

bool Armado::checkear() {
    if (this->cantidad_bombas >= this->cantidad_bombas_necesarias){
        this->cumplio = true;
    }
    return this->cumplio;
}

void Armado::actualizar(int valor) {
    this->cantidad_bombas = valor;
}

void Armado::mostrar_progreso() {
    cout << "La cantidad de bombas obtenida es: " << this->cantidad_bombas << endl;
}