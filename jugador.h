#ifndef JUGADOR_H
#define JUGADOR_H
#include "menu.h"


class Jugador{

private:
    int nombre;
    ListaMateriales materiales;
    int energia;
    int objetivo1,objetivo2,objetivo3;
    int coordenada_x,coordenada_y;

public:
    void mover();
    void mover_gratis(int x, int y);
    void sumar_energia(int cantidad);
    void restar_energia(int cantidad);
    int devolver_energia();
    Jugador(int x, int y, int numero);
    void mostrar_objetivos();
    void asignar_lista_materiales(ListaMateriales materiales);
    void comprar_bombas();
    // ListaMateriales* devolver_materiales();
    ListaMateriales devolver_materiales();

    int devolver_nombre();
    int devolver_coordenada_x();
    int devolver_coordenada_y();
private:
    void asignar_objetivos();

};






#endif