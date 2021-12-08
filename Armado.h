
#ifndef TP3_2021_2C_ARMADO_H
#define TP3_2021_2C_ARMADO_H

#include "objetivo.h"

class Armado : public Objetivo {
private:
    ListaMateriales materiales;
public:

    void mostrar();
    Armado(ListaMateriales materiales);
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);

};


#endif //TP3_2021_2C_ARMADO_H
