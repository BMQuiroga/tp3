
#ifndef TP3_2021_2C_EXTREMISTA_H
#define TP3_2021_2C_EXTREMISTA_H
#include "objetivo.h"

class Extremista : public Objetivo {
private:
    int bombas_compradas;
    int bombas_necesarias;
    bool cumplio;
public:
    Extremista();
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);
    void mostrar();
    void mostrar_progreso();
};


#endif //TP3_2021_2C_EXTREMISTA_H
