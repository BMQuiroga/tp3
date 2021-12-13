#ifndef TP3_2021_2C_CONSTRUCTOR_H
#define TP3_2021_2C_CONSTRUCTOR_H

#include "objetivo.h"

class Constructor : public Objetivo {
private:
    ListaEdificios * edificios;
    Mapa * mapa;
    Jugador * jugador;
    int edificios_construidos;
    int edificios_requeridos;
    bool cumplio;
public:
    //Pre: Recibe la lista de edificios y el jugador de la partida
    //Pos: Inicializa los atributos
    Constructor(ListaEdificios *edificios, Mapa * mapa, Jugador * jugador);

    //Pre:-
    //Pos: Muestra por pantalla el objetivo, y si lo cumplio muestra que fue completado
    void mostrar();

    //Pre:-
    //Pos: Muestra por pantalla el progreso  
    void mostrar_progreso();

    //Pre:-
    //Pos:Retorna la cantidad de edificios construidos
    int calcular_progreso();

    //Pre:-
    //Pos: Devuelve true si la cant de edificios construidos== cant de edif requeridos
    bool checkear();

    //Pre:-
    //Pos: Actualiza los edificios construidos
    void actualizar(int valor);
};


#endif 
