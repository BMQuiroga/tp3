//
// Created by rui on 12/5/21.
//

#include "listaObjetivos.h"
#include "ComprarAndypolis.h"
#include "EdadDePiedra.h"
#include "Bombardero.h"
#include "Energetico.h"
#include "Letrado.h"
#include "Minero.h"
#include "Cansado.h"
#include "Constructor.h"
#include "Armado.h"
#include "Extremista.h"


ListaObjetivos::ListaObjetivos( Jugador jugador, ListaMateriales materiales, ListaEdificios edificios, Mapa * mapa){

     objetivos[0] = new ComprarAndypolis;
     objetivos[1] = new EdadDePiedra(materiales, jugador);
     objetivos[2] = new Bombardero;
     objetivos[3] = new Energetico(jugador);
     objetivos[4] = new Letrado(edificios/*, mapa, jugador*/);
     objetivos[5] = new Minero(/*edificios, mapa, jugador*/);
     objetivos[6] = new Cansado(jugador);
     objetivos[7] = new Constructor(/*edificios, mapa, jugador*/);
     objetivos[8] = new Armado(materiales, jugador);
     objetivos[9] = new Extremista;

}

void ListaObjetivos::alta(Objetivo *objetivo, int posicion) {
    this->objetivos[posicion] = objetivo;
}

Objetivo ListaObjetivos::obtener_objetivo(int posicion) {
    //return (this->objetivos[posicion]);
}

/*
void ListaObjetivos::obtener_objetivos_aleatorios(Jugador jugador) {
    jugador.
}*/