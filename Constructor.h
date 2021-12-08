

#ifndef TP3_2021_2C_CONSTRUCTOR_H
#define TP3_2021_2C_CONSTRUCTOR_H

#include "objetivo.h"

class Constructor : public Objetivo {
private:
    ListaEdificios edificios;
    Mapa * mapa;
    Jugador * jugador;

    int cantidad_yacimiento;
    int cantidad_mina;
    int cantidad_mina_oro;
    int cantidad_planta_electrica;
    int cantidad_fabrica;
    int cantidad_aserradero;
    int cantidad_escuela;
    int cantidad_casa;
    int cantidad_necesaria;
    bool cumplio;
public:

    void mostrar();
    void mostrar_progreso();
    Constructor(ListaEdificios edificios, Mapa * mapa, Jugador * jugador);
    int calcular_progreso();
    bool checkear();
    void actualizar(string nombre, int valor);
    void actualizar_yacimiento(int valor);
    void actualizar_mina(int valor);
    void actualizar_mina_oro(int valor);
    void actualizar_planta_electrica(int valor);
    void actualizar_fabrica(int valor);
    void actualizar_aserradero(int valor);
    void actualizar_escuela(int valor);
    void actualizar_casa(int valor);
};


#endif //TP3_2021_2C_CONSTRUCTOR_H
