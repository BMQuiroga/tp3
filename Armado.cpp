//
// Created by ydsas on 4/12/2021.
//

#include "Armado.h"
#include "jugador.h"

Armado::Armado(Jugador *jugador) {
    this->nombre="Armado";
    this->cantidad_bombas = 0;
    this->jugador=jugador;
    this->cantidad_bombas_necesarias = 10;
    this->cumplio = false;
}

bool Armado::checkear() {
    if (this->cantidad_bombas >= this->cantidad_bombas_necesarias){
        this->cumplio = true;
    }
    return this->cumplio;
}


void Armado::mostrar(){
    cout << "Armado: tener 10 bombas en el inventario." << endl;
    cout << "Bombas en el inventario: " << calcular_progreso() << "/10" << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}
/*
void Armado::actualizar(int valor) {
    this->cantidad_bombas = valor;
}
*/
int Armado::calcular_progreso(){
    cantidad_bombas = this->jugador->devolver_materiales()->consulta(this->jugador->devolver_materiales()->buscar_indice("bombas"))->devolver_cantidad();
    return cantidad_bombas;
}