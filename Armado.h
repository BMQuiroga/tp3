
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
    Armado(Jugador * jugador);
    ~Armado();

    void mostrar();
    int calcular_progreso();
    bool checkear();
};


#endif //TP3_2021_2C_ARMADO_H
