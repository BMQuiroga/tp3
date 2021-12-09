
#ifndef TP3_2021_2C_COMPRARANDYPOLIS_H
#define TP3_2021_2C_COMPRARANDYPOLIS_H

#include "objetivo.h"

class ComprarAndypolis : public Objetivo {

private:
    int andycoins_juntadas;
    int cantidad_andycoins_objetivo;
    bool cumplio;

public:
    ComprarAndypolis();
    int calcular_progreso();
    void mostrar();
    bool checkear();
    void actualizar(int valor);
};


#endif //TP3_2021_2C_COMPRARANDYPOLIS_H
