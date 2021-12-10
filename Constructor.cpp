//
// Created by ydsas on 4/12/2021.
//

#include "Constructor.h"
#include <iostream>
#include "mapa.h"

Constructor::Constructor(ListaEdificios * edificios, Mapa * mapa, Jugador * jugador) {

    this->nombre="Constructor";
    this->edificios = edificios;
    this->mapa=mapa;
    this->jugador=jugador;
    this->cumplio = false;
    this->edificios_requeridos=edificios->devolver_cantidad();
    this->edificios_construidos=0;

}

void Constructor::mostrar(){
    int numero = calcular_progreso();
    std::cout << "Constructor: construir un edificio de cada tipo. " << std::endl;
    std::cout << "Edificios construidos: " << numero << "/" << edificios_requeridos << std::endl;
    if(checkear())
        std::cout << "Este objetivo ha sido completado" << std::endl;
}

bool Constructor::checkear() {
    if (edificios_construidos == edificios_requeridos) 
        this->cumplio = true;
    
    return cumplio;
}

int Constructor::calcular_progreso(){
    int contador = 0;
    bool resultado = true;
    std::string nombre;
    Edificio** array_edificios = edificios->devolver_todo();
    for (int i = 0; i < edificios->devolver_cantidad(); i++) {
        nombre = array_edificios[i]->devolver_nombre();
        resultado = mapa->tiene_edificio(nombre, jugador);   
        if (resultado) {
            contador++;
        }
    }
    edificios_construidos = contador;
    delete[] array_edificios;
    return contador;
}
