
#ifndef TP3_2021_2C_MINERO_H
#define TP3_2021_2C_MINERO_H

#include "objetivo.h"

class Minero : public Objetivo {
private:
    ListaEdificios edificios;
    Mapa * mapa;
    Jugador * jugador;
public:

    void mostrar(){cout << "Minero: haber construido una mina de cada tipo. " << endl;}
    Minero(ListaEdificios edificios, Mapa * mapa, Jugador * jugador);
    bool checkear();
    int calcular_progreso();
    void actualizar(int valor);
};




#endif //TP3_2021_2C_MINERO_H
