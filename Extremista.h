
#ifndef TP3_2021_2C_EXTREMISTA_H
#define TP3_2021_2C_EXTREMISTA_H
#include "objetivo.h"

class Extremista : public Objetivo {
public:
    Extremista();
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);
};


#endif //TP3_2021_2C_EXTREMISTA_H
