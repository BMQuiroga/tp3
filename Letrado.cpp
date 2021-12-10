//
// Created by ydsas on 4/12/2021.
//

#include "Letrado.h"
Letrado::Letrado(ListaEdificios * edificios, Mapa * mapa, Jugador * jugador) {
    this->nombre="Letrado";
    this->edificios = edificios;
    this->mapa = mapa;
    this->cantidad_escuelas_construidas = 0; //
    this->cantidad_escuela_maxima = edificios->consulta("escuela")->devolver_maximos_permitidos();
    this->cumplio = false;
}

void Letrado::mostrar(){
    cout << "Letrado: haber construido el máximo posible de escuelas. " << endl;
    cout << "Escuelas construidas: " << calcular_progreso() << "/" << cantidad_escuela_maxima << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}

bool Letrado::checkear() {
    if (this->cantidad_escuelas_construidas == this->cantidad_escuela_maxima){
        this->cumplio = true;
    }
    return cumplio;
}

int Letrado::calcular_progreso(){
    cantidad_escuelas_construidas = (mapa->edificios_construidos("escuela",jugador));
    return cantidad_escuelas_construidas;
}

/*
void Letrado::mostrar_progreso() {
    cout << "La cantidad de escuelas construidas es: " << this->cantidad_escuelas_construidas << endl;
}*/