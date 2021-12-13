#include "Constructor.h"
#include <iostream>
#include "mapa.h"

Constructor::Constructor(ListaEdificios *edificios, Mapa * mapa,Jugador *jugador) {

    this->nombre="Constructor";
    this->edificios = edificios;
    this->mapa = mapa;
    this->jugador = jugador;
    this->cumplio = false;
    this->edificios_requeridos=edificios->devolver_cantidad()-1;//dando por hecho que existe obelisco, no lo necesitas para este objetivo
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
    for (int i = 0; i < edificios->devolver_cantidad()-1; i++) {
        nombre = array_edificios[i]->devolver_nombre();
        resultado = mapa->edificios_construidos(nombre, jugador);   
        if (resultado>=1) {
            contador++;
        }
    }
    edificios_construidos = contador;
    delete [] array_edificios;
    return contador;
}

void Constructor::actualizar(int valor){
    calcular_progreso();
}