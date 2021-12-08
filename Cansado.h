
#ifndef TP3_2021_2C_CANSADO_H
#define TP3_2021_2C_CANSADO_H
#include "objetivo.h"

class Cansado : public Objetivo {
private:
    //Jugador * jugador;
    int energia;
    int energia_minima;
    bool cumplio;
public:

    void mostrar();
    void mostrar_progreso();
    Cansado(Jugador jugador);
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);
};


#endif //TP3_2021_2C_CANSADO_H
