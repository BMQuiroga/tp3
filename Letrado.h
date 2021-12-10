
#ifndef TP3_2021_2C_LETRADO_H
#define TP3_2021_2C_LETRADO_H

#include "objetivo.h"
#include "mapa.h"

class Letrado : public Objetivo {
private:
    ListaEdificios* edificios;
    Mapa * mapa;
    Jugador * jugador;
    int cantidad_escuelas_construidas;
    int cantidad_escuela_maxima;
    bool cumplio;
public:

    void mostrar();
    Letrado(ListaEdificios* edificios, Mapa * mapa, Jugador * jugador);
    int calcular_progreso();
    bool checkear();

};


#endif //TP3_2021_2C_LETRADO_H
