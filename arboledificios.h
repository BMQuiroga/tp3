#ifndef ARBOLEDIFICIOS_H
#define ARBOLEDIFICIOS_H

#include "listaedificios.h"
#include "ramaedificios.h"

class ArbolEdificios{

private:
    RamaEdificios* raiz;

public:
    //Constructor
    //PRE: -
    //POS: tope = 0
    ArbolEdificios(Edificio edificio);

    //PRE: 1 <= pos <= cantidad + 1
    //POS: agrega d arriba de la pila e incrementa tope en 1
    void alta(std::string nombre, int piedra, int madera, int metal, int maximos);

    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba
    Edificio consulta(std::string edificio);

    //PRE: -
    //POST: Devuelve la cantidad de edificios
    int devolver_cantidad();

    void procesar_archivo_edificios();
};

#endif

//ARCORDARSE DE BORRAR TODAS LAS APARICIONES DE "BUSCAR INDICE" Y MODIFICIAR TODAS LAS CONSULTAS