#ifndef JUGADOR_H
#define JUGADOR_H
#include "menu.h"


class Jugador{

private:
    std::string nombre;
    ListaMateriales materiales;
    int energia;
    int objetivo1,objetivo2,objetivo3;

public:
    void mover();
    void sumar_energia(int cantidad);
    void restar_energia(int cantidad);
    Jugador();
    void mostrar_objetivos();

private:
    void asignar_objetivos();

};






#endif