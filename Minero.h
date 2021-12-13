
#ifndef TP3_2021_2C_MINERO_H
#define TP3_2021_2C_MINERO_H

#include "objetivo.h"

class Minero : public Objetivo {
private:
    ListaEdificios * edificios;
    Mapa * mapa;
    Jugador * jugador;
    bool existe_mina;
    bool existe_mina_oro;
    bool hay_mina;
    bool hay_mina_oro;
    bool cumplio;
    int cantidad_minas_necesarias;
    int cantidad_minas_construidas;
public:

    //Pre:-
    //Pos:Muestra por pantalla la cant de tiṕo de minas y si tiene los 2 tipos muestra que el obj fue completado
    void mostrar();

    //Pre: Recibe lista de edificios, mapa y el jugador de la partida
    //Pos:Asigna la cantidad de minas, chequea si hay mina oro, si hay mina, e inicializa los atributos
    Minero(ListaEdificios * edificios, Mapa * mapa, Jugador * jugador);

    //Pre:-
    //Pos:Chequea si la cant de minas necesarias es igual  a la cant minas construidas
    bool checkear();

    //Pre:-
    //Pos:Asigna la cant de minas construidas y la retorna
    int calcular_progreso();

    //Pre:
    //Pos:
    void actualizar(string nombre, int valor);

    //void actualizar_minero(int valor);
    //void actualizar_minero_oro(int valor_minero, int valor_minero_oro);

    void actualizar(int valor);
};




#endif
