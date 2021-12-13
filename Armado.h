
#ifndef TP3_2021_2C_ARMADO_H
#define TP3_2021_2C_ARMADO_H

#include "objetivo.h"

class Armado : public Objetivo {
private:
    Jugador * jugador;
    int cantidad_bombas;
    int cantidad_bombas_necesarias;
    bool cumplio;
public:

    //Pre: Recibe el jugador de la partida
    //Pos: Inicializa los atributos, cant_bombas_necesarias = 10
    Armado(Jugador * jugador);

    //Pre:-
    //Pos:Destructor
    ~Armado();

    //Pre:-
    //Pos:Muestra por pantalla el objetivo, cantidad de bombas del inventario,
    //    si cumple el objetivo muestra que fue completado
    void mostrar();

    //Pre:-
    //Pos: Retorna la cantidad de bombas
    int calcular_progreso();

    //Pre:-
    //Pos: Devuelve true si la cant de bombas es mayor o igual que 10 (bombas necesarias)
    bool checkear();

    void actualizar(int valor);
};


#endif //TP3_2021_2C_ARMADO_H
