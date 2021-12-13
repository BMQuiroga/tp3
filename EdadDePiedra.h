
#ifndef TP3_2021_2C_EDADDEPIEDRA_H
#define TP3_2021_2C_EDADDEPIEDRA_H
#include "objetivo.h"

class EdadDePiedra : public Objetivo {
private:
    Jugador * jugador;
    int cantidad_piedras;
    int cantidad_piedras_necesarias;
    bool cumplio;
public:

    //Pre:Recibe el jugador de la partida
    //Pos:Inicializa los atributos, cant piedras necesarias = 5000
    EdadDePiedra(Jugador * jugador);

    //Pre:-
    //Pos:Muestra por pantalla el objetivo, y si lo cumple muestra que fue completado
    void mostrar();

    //Pre:-
    //Pos:Retorna la cantidad de piedras
    int calcular_progreso();

    //Pre:
    //Pos: Chequea que la cant de piedras sea mayor o igual que 5000
    bool checkear();

};


#endif //TP3_2021_2C_EDADDEPIEDRA_H
