
#ifndef TP3_2021_2C_EDADDEPIEDRA_H
#define TP3_2021_2C_EDADDEPIEDRA_H
#include "objetivo.h"

class EdadDePiedra : public Objetivo {
private:
    Jugador * jugador;
    int cantidad_piedras;
    int cantidad_piedras_necesarias;
    bool cumplio;
public:
    EdadDePiedra(Jugador * jugador);

    void mostrar();
    int calcular_progreso();
    bool checkear();

};


#endif //TP3_2021_2C_EDADDEPIEDRA_H
