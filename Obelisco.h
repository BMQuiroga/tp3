#ifndef TP3_2021_2C_OBELISCO_H
#define TP3_2021_2C_OBELISCO_H

#include "objetivo.h"

class Obelisco : public Objetivo {
private:
    ListaEdificios * edificios;
    Mapa * mapa;
    Jugador * jugador;
    bool cumplio;
    int obeliscos_construidos;
public:

    //Pre:-
    //Pos:Muestra por pantalla el objetivo, y si lo cumple muestra que fue completado
    void mostrar();

    //Pre: Recibe edificios, mapa y el jugador de la partida
    //Pos:Inicializa los atributos
    Obelisco(ListaEdificios * edificios, Mapa * mapa, Jugador * jugador);

    //Pre:-
    //Pos:Retorna la cantidad de obeliscos construidos
    int calcular_progreso();

    //Pre:-
    //Pos:Devuelve true si la cant de obeliscos es 1
    bool checkear();

    void actualizar(int valor);
};


#endif //TP3_2021_2C_OBELISCO_H
