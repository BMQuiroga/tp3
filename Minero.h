
#ifndef TP3_2021_2C_MINERO_H
#define TP3_2021_2C_MINERO_H

#include "objetivo.h"

class Minero : public Objetivo {
private:
    ListaEdificios * edificios;
    Mapa * mapa;
    Jugador * jugador;
    bool existe_mina;
    bool existe_mina_oro;
    bool hay_mina;
    bool hay_mina_oro;
    bool cumplio;
    int cantidad_minas_necesarias;
    int cantidad_minas_construidas;
public:

    void mostrar();
    Minero(ListaEdificios * edificios, Mapa * mapa, Jugador * jugador);
    bool checkear();
    int calcular_progreso();
    void actualizar(string nombre, int valor);
    //void actualizar_minero(int valor);
    //void actualizar_minero_oro(int valor_minero, int valor_minero_oro);
};




#endif //TP3_2021_2C_MINERO_H
