#include "objetivo.h"
#include "mapa.h"

std::string LISTA_OBJETIVOS [11] = { // NO CAMBIAR DE ORDEN
    "Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida",
    "Edad de piedra: tener en el inventario 50000 piedras",
    "Bombardero: haber usado 5 bombas.",
    "Energético: haber terminado un turno con 100 puntos de energía.",
    "Letrado: haber construido el máximo posible de escuelas.",
    "Minero: haber construido una mina de cada tipo.",
    "Cansado: terminar un turno con 0 de energía.",
    "Constructor: construir un edificio de cada tipo.",
    "Armado: tener 10 bombas en el inventario.",
    "Extremista: haber comprado 500 bombas en una partida."
    "Más alto que las nubes: construir el obelisco.",
};

Objetivo::Objetivo() {}

Objetivo::~Objetivo() {}

bool Objetivo::checkear(){
    return false;
}


std::string Objetivo::devolver_nombre() {
    return this->nombre;
}

void Objetivo::actualizar(int valor) {
    
}
