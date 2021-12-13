#include "Obelisco.h"
#include <iostream>
#include "mapa.h"

Obelisco::Obelisco(ListaEdificios * edificios, Mapa * mapa, Jugador * jugador) {

    this->nombre="Obelisco";
    this->edificios = edificios;
    this->cumplio = false;
    this->mapa=mapa;
    this->jugador=jugador;

}

void Obelisco::mostrar(){
    int numero = calcular_progreso();
    std::cout << "Más alto que las nubes: construir el obelisco." << std::endl;
    std::cout << "Obeliscos construidos: " << numero << "/1" <<  std::endl;
    if(checkear())
        std::cout << "Este objetivo ha sido completado" << std::endl;
}

int Obelisco::calcular_progreso(){
    if(this->mapa->tiene_edificio("obelisco",jugador))
        obeliscos_construidos = 1;
    else
        obeliscos_construidos = 0;
    return obeliscos_construidos;
}    

bool Obelisco::checkear(){
    if (obeliscos_construidos == 1) 
        this->cumplio = true;
    
    return cumplio;
}

void Obelisco::actualizar(int valor){
    
}
