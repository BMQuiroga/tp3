
#ifndef TP3_2021_2C_CANSADO_H
#define TP3_2021_2C_CANSADO_H
#include "objetivo.h"

class Cansado : public Objetivo {
private:
    Jugador * jugador;
    int energia;
    int energia_minima;
    bool cumplio;
public:
    Cansado(Jugador * jugador);
    ~Cansado();

    void mostrar();
    int calcular_progreso();
    bool checkear();
};


#endif //TP3_2021_2C_CANSADO_H
