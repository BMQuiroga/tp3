
#ifndef TP3_2021_2C_COMPRARANDYPOLIS_H
#define TP3_2021_2C_COMPRARANDYPOLIS_H

#include "objetivo.h"

class ComprarAndypolis : public Objetivo {

private:
    int andycoins_juntadas;
    int cantidad_andycoins_objetivo;
    bool cumplio;

public:

    //Pre:-
    //Pos:Inicializa los atributos, cant andycoins objetivo = 100 000
    ComprarAndypolis();

    //Pre:
    //Pos:Retorna la cant de andycoins juntados
    int calcular_progreso();

    //Pre:-
    //Pos:Muestra por pantalla el objetivp, los andycoins juntados , 
    //    y si cumple el obj muestra que fue completado
    void mostrar();

    //Pre:-
    //Pos: Devuelve true si los andycoins juntados es mayor o igual que 100 000
    bool checkear();

    //Pre: Recibe cant de andycoins nuevo
    //Pos: Actualiza la cant de andycoins juntados sumandole el del parametro
    void actualizar(int valor);
};


#endif //TP3_2021_2C_COMPRARANDYPOLIS_H
