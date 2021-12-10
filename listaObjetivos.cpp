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

/*
ListaObjetivos::ListaObjetivos( Jugador jugador, /*ListaMateriales materiales,*/ /*ListaEdificios edificios*//*, Mapa * mapa){

     objetivos[0] = new ComprarAndypolis;
     objetivos[1] = new EdadDePiedra(jugador);
     objetivos[2] = new Bombardero;
     objetivos[3] = new Energetico(jugador);
     objetivos[4] = new Letrado(edificios/*, mapa, jugador);
     objetivos[5] = new Minero(/*edificios, mapa, jugador);
     objetivos[6] = new Cansado(jugador);
     objetivos[7] = new Constructor(/*edificios, mapa, jugador);
     objetivos[8] = new Armado(/*materiales, jugador);
     objetivos[9] = new Extremista;

}*/

void ListaObjetivos::alta(Objetivo *objetivo, int posicion) {
    this->objetivos[posicion] = objetivo;
}

Objetivo** ListaObjetivos::obtener_objetivos_aleatorios(Jugador jugador, ListaEdificios edificios) {
    int pos1, pos2, pos3;

    pos1 = rand() % 10;
    pos2 =rand() % 10;
    while (pos2 == pos1){
        pos2 =rand() % 10;
    }
    pos3 =rand() % 10;
    while(pos3 == pos2 || pos3 == pos1){
        pos3 =rand() % 10;
    }
    asignar_objetivos_correspondientes(pos1, pos2, pos3, jugador, edificios);

    return this->objetivos;
}


void ListaObjetivos::asignar_objetivos_correspondientes(int pos1, int pos2, int pos3, Jugador jugador, ListaEdificios edificios) {

    int pos;
    for (int i = 0; i < 3; ++i) {

        if (i == 0){
            pos = pos1;
        } else if (i == 1){
            pos = pos2;
        } else if (i == 2){
            pos = pos3;
        }
        switch (pos) {
            case 0:
                objetivos[i] = new ComprarAndypolis;
                break;

            case 1:
                objetivos[i] = new EdadDePiedra(jugador);
                break;

            case 2:
                objetivos[i] = new Bombardero;
                break;

            case 3:
                objetivos[i] = new Energetico(jugador);
                break;

            case 4:
                //objetivos[i] = new Letrado(edificios/*, mapa, jugador*/);
                break;

            case 5:
                objetivos[i] = new Minero(/*edificios, mapa, jugador*/);
                break;

            case 6:
                objetivos[i] = new Cansado(jugador);
                break;

            case 7:
                objetivos[i] = new Constructor(/*edificios, mapa, jugador*/);
                break;

            case 8:
                objetivos[i] = new Armado(jugador);
                break;

            case 9:
                objetivos[i] = new Extremista;
                break;
        }
    }

}

/*
void ListaObjetivos::obtener_objetivos_aleatorios(Jugador jugador) {
    jugador.
}*/