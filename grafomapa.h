#ifndef GRAFOMAPA_H
#define GRAFOMAPA_H
#include "casillero_construible.h"
#include "casillero_inaccesible.h"
#include "casillero_transitable.h"
#include "listarecorrido.h"

using namespace std;

class GrafoMapa {
private:
    int filas;
    int columnas;
    int** matriz_adyacencia;
    int** matriz_vertices;
    Casillero*** matriz;
    Jugador jugador;

public:


private:

};

#endif