
#ifndef TP3_2021_2C_COMPRARANDYPOLIS_H
#define TP3_2021_2C_COMPRARANDYPOLIS_H

#include "objetivo.h"

class ComprarAndypolis : public Objetivo {
public:
    ComprarAndypolis();
    int calcular_progreso();
    void mostrar_objetivo(){cout << "Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida (las monedas gastadas también cuentan para este objetivo)" << endl;}
    bool checkear();
    void actualizar(int valor);
};


#endif //TP3_2021_2C_COMPRARANDYPOLIS_H
