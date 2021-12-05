
#ifndef TP3_2021_2C_CANSADO_H
#define TP3_2021_2C_CANSADO_H
#include "objetivo.h"

class Cansado : public Objetivo {
private:
    Jugador * jugador;
public:

    void mostrar(){cout << "Cansado: terminar un turno con 0 de energía." << endl;}
    Cansado(Jugador * jugador);
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);
};


#endif //TP3_2021_2C_CANSADO_H