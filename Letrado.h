
#ifndef TP3_2021_2C_LETRADO_H
#define TP3_2021_2C_LETRADO_H

#include "objetivo.h"

class Letrado : public Objetivo {
private:
    ListaEdificios edificios;
    Mapa * mapa;
    Jugador * jugador;
public:

    void mostrar();
    Letrado(ListaEdificios edificios, Mapa * mapa, Jugador * jugador);
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);

};


#endif //TP3_2021_2C_LETRADO_H
