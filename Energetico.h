
#ifndef TP3_2021_2C_ENERGETICO_H
#define TP3_2021_2C_ENERGETICO_H

#include "objetivo.h"

class Energetico  : public Objetivo {
private:
    //Jugador * jugador;
    int energia;
    int energia_maxima;
    bool cumplio;
public:

    void mostrar();
    Energetico(Jugador jugador);
    void mostrar_progreso();
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);

};


#endif //TP3_2021_2C_ENERGETICO_H
