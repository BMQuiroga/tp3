
#ifndef TP3_2021_2C_BOMBARDERO_H
#define TP3_2021_2C_BOMBARDERO_H
#include "objetivo.h"

class Bombardero : public Objetivo {
private:

    int bombas_usadas;
    int bombas_objetivos;
    bool cumplio;

public:
    Bombardero();

    void mostrar();
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);
    void mostrar_progreso();
};


#endif //TP3_2021_2C_BOMBARDERO_H
