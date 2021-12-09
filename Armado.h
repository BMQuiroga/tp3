
#ifndef TP3_2021_2C_ARMADO_H
#define TP3_2021_2C_ARMADO_H

#include "objetivo.h"

class Armado : public Objetivo {
private:
    ListaMateriales materiales;
    int cantidad_bombas;
    int cantidad_bombas_necesarias;
    bool cumplio;
public:

    void mostrar();
    Armado(Jugador jugador);
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);

};


#endif //TP3_2021_2C_ARMADO_H
