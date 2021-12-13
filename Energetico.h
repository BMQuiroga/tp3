
#ifndef TP3_2021_2C_ENERGETICO_H
#define TP3_2021_2C_ENERGETICO_H

#include "objetivo.h"

class Energetico : public Objetivo {
private:
    Jugador * jugador;
    int energia;
    int energia_maxima;
    bool cumplio;
public:

    //Pre:-
    //Pos:Muestra por pantalla el objetivo, y si cumple muestra que fue completado
    void mostrar();

    //Pre: Recibe el jugador de la partida
    //Pos: Inicializa los atributos, energia_maxima = 100
    Energetico(Jugador * jugador);

    //Pre:
    //Pos:
    int calcular_progreso();

    //Pre:-
    //Pos: Devuelve true si la energia es mayor o igual que 100 (energia maxima)
    bool checkear();

    //pre: -
    //pos: actualiza el progreso del objetivo
    void actualizar(int valor);
};


#endif 
