#ifndef RAMAEDIFICIOS_H
#define RAMAEDIFICIOS_H

#include <iostream>
#include "listaedificios.h"


class RamaEdificios{

private:
    std::string clave;
    Edificio valor;
    RamaEdificios* nodo_izq;
    RamaEdificios* nodo_der;

public:

    RamaEdificios();

    std::string devolver_nombre();

    Edificio devolver_edificio();

    void asignar_nodo(RamaEdificios* rama);











};


#endif