
#ifndef TP3_2021_2C_LETRADO_H
#define TP3_2021_2C_LETRADO_H

#include "objetivo.h"
#include "mapa.h"

class Letrado : public Objetivo {
private:
    ListaEdificios* edificios;
    Mapa * mapa;
    Jugador * jugador;
    int cantidad_escuelas_construidas;
    int cantidad_escuela_maxima;
    bool cumplio;
public:

    //Pre:-
    //Pos:Muestra el objetivo por pantalla,cant escuelas construidas y la maxima,
    //    si cumple el objetivo muestra que fue completado
    void mostrar();

    //Pre:Recibe la lista de edificios, mapa y el jugador de la partida
    //Pos:Asigna los atributos 
    Letrado(ListaEdificios* edificios, Mapa * mapa, Jugador * jugador);

    //Pre:-
    //Pos:Retorna la cant de escuelas construidas
    int calcular_progreso();

    //Pre:-
    //Pos:Devuelve true si la cant de escuelas construidas == cant escuelas maxima
    bool checkear();

    //Pre:-
    //Pos: actualiza el objetivo
    void actualizar(int valor);
};


#endif
