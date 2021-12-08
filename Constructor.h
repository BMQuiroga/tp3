

#ifndef TP3_2021_2C_CONSTRUCTOR_H
#define TP3_2021_2C_CONSTRUCTOR_H

#include "objetivo.h"

class Constructor : public Objetivo {
private:
    ListaEdificios edificios;
    Mapa * mapa;
    Jugador * jugador;
public:

    void mostrar();
    Constructor(ListaEdificios edificios, Mapa * mapa, Jugador * jugador);
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);

};


#endif //TP3_2021_2C_CONSTRUCTOR_H
