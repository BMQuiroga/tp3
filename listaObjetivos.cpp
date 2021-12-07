//
// Created by rui on 12/5/21.
//

#include "listaObjetivos.h"

ListaObjetivos::ListaObjetivos( Jugador jugador, ListaMateriales materiales, ListaEdificios edificios, Mapa * mapa){

    this->objetivos[0] = new ComprarAndypolis;
    this->objetivos[1] = new EdadDePiedra(materiales);
    this->objetivos[2] = new Bombardero;
    this->objetivos[3] = new Energetico(jugador);
    this->objetivos[4] = new Letrado(edificios, mapa, jugador);
    this->objetivos[5] = new Minero(edificios, mapa, jugador);
    this->objetivos[6] = new Cansado(jugador);
    this->objetivos[7] = new Constructor(edificios, mapa, jugador);
    this->objetivos[8] = new Armado(materiales);
    this->objetivos[9] = new Extremista;

}

void ListaObjetivos::alta(Objetivo *objetivo, int posicion) {
    this->objetivos[posicion] = objetivo;
}
