
#ifndef TP3_2021_2C_CANSADO_H
#define TP3_2021_2C_CANSADO_H
#include "objetivo.h"

class Cansado : public Objetivo {
private:
    Jugador * jugador;
    int energia;
    int energia_minima;
    bool cumplio;
public:

    //Pre: Recibe el jugador de la partida
    //Pos: Inicializa los atributos, energia minima = 0
    Cansado(Jugador * jugador);

    //Pre:-
    //Pos: Destructor
    ~Cansado();

    //Pre:-
    //Pos: Muestra por pantalla el objetivo, y si lo cumple muestra que fue completado
    void mostrar();

    //Pre:
    //Pos:
    int calcular_progreso();

    //Pre:
    //Pos:Retorna true si la energia es igual a 0
    bool checkear();

    void actualizar(int valor);
};


#endif //TP3_2021_2C_CANSADO_H
