#ifndef ARBOLEDIFICIOS_H
#define ARBOLEDIFICIOS_H

#include "listaedificios.h"
#include "ramaedificios.h"

class ArbolEdificios{

private:
    NodoEdificios* raiz;

public:
    //Constructor
    //PRE: -
    //POS: tope = 0
    ArbolEdificios();

    //PRE: 1 <= pos <= cantidad + 1
    //POS: agrega d arriba de la pila e incrementa tope en 1
    void alta(std::string nombre, int piedra, int madera, int metal, int maximos, int pos);

    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba
    Edificio consulta(int pos);

    //Destructor
    void destruir();

    //PRE: -
    //POST: Devuelve el indice del edificio buscado
    int buscar_indice(std::string nombre);

    //PRE: -
    //POST: Devuelve la cantidad de edificios
    int devolver_cantidad();
};

#endif