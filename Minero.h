
#ifndef TP3_2021_2C_MINERO_H
#define TP3_2021_2C_MINERO_H

#include "objetivo.h"

class Minero : public Objetivo {
private:
    ListaEdificios edificios;
    Mapa * mapa;
    Jugador * jugador;
    int cantidad_minero;
    int cantidad_minero_oro;
    int cantidad_mineros_necesarios;
    bool cumplio;
public:

    void mostrar();
    void mostrar_progreso();
    Minero(/*ListaEdificios edificios, Mapa * mapa, Jugador * jugador*/);
    bool checkear();
    int calcular_progreso();
    void actualizar(string nombre, int valor);
    //void actualizar_minero(int valor);
    //void actualizar_minero_oro(int valor_minero, int valor_minero_oro);
};




#endif //TP3_2021_2C_MINERO_H
