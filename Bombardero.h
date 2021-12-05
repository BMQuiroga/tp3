
#ifndef TP3_2021_2C_BOMBARDERO_H
#define TP3_2021_2C_BOMBARDERO_H
#include "objetivo.h"

class Bombardero : public Objetivo {
public:
    Bombardero();

    void mostrar(){cout << "Bombardero: haber usado 5 bombas." << endl;}
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);
};


#endif //TP3_2021_2C_BOMBARDERO_H