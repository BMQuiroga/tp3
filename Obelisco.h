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

    void mostrar();
    Obelisco(ListaEdificios * edificios, Mapa * mapa, Jugador * jugador);
    int calcular_progreso();
    bool checkear();
};


#endif //TP3_2021_2C_OBELISCO_H
