//
// Created by ydsas on 4/12/2021.
//

#include "Minero.h"
Minero::Minero(/*ListaEdificios edificios, Mapa *mapa, Jugador *jugador*/) {

    this->cantidad_minero = 0;
    this->cantidad_minero_oro = 0;
    this->cantidad_mineros_necesarios = 1;
    this->cumplio = false;
}

void Minero::mostrar(){
    cout << "Minero: haber construido una mina de cada tipo. " << endl;
}

bool Minero::checkear() {
    if (this->cantidad_minero >= this->cantidad_mineros_necesarios && this->cantidad_minero_oro >= this->cantidad_mineros_necesarios){
        this->cumplio = true;
    }
    return this->cumplio;
}

void Minero::actualizar(string nombre, int valor ){

    if (nombre == "minero"){

        this->cantidad_minero += valor;
    }else if (nombre == "minero oro"){

        this->cantidad_minero_oro += valor;
    }
}

void Minero::mostrar_progreso() {
    cout << "La cantidad de minero contruido es: " << this->cantidad_minero << " y la cantidad de minero de oro contruido es: " << this->cantidad_minero_oro << endl;
}