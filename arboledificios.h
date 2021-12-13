#ifndef ARBOLEDIFICIOS_H
#define ARBOLEDIFICIOS_H

#include "edificio.h"
#include "ramaedificios.h"

#define ArbolEdificios ListaEdificios

class RamaEdificios;

class ArbolEdificios{

private:
    RamaEdificios* raiz;

public:
    //Constructor
    //PRE: -
    //POS: -
    ArbolEdificios(/*Edificio edificio*/);

    //PRE: -
    //POS: -
    ~ArbolEdificios();

    //PRE: -
    //POS: agrega el edificio al arbol
    void alta(std::string nombre, int piedra, int madera, int metal, int maximos);

    //PRE: que el edificio exista
    //POS: devuelve el edificio
    Edificio* consulta(std::string edificio);

    //PRE: -
    //POST: Devuelve la cantidad de edificios
    int devolver_cantidad();

    //PRE: -
    //POST: Crea el arbol con los datos de edificios.txt
    void procesar_archivo_edificios();

    //PRE: -
    //POST: Devuelve si el edificio se encuentra en el diccionario
    bool es_edificio_valido(std::string nombre);

    //PRE: -
    //POST: Libera la memoria y guarda los edificios en edificios.txt
    void destruir();

    //PRE: -
    //POST: Devuelve un array con todos los edificios
    Edificio** devolver_todo();

    //PRE: -
    //POST: Cambia el edificio por otro con el mismo nombre
    void cambiar_nodo(Edificio* edificio);

    //PRE: -
    //POST: Reescribe el archivo edificios
    void reescribir();
};

#endif

//ARCORDARSE DE BORRAR TODAS LAS APARICIONES DE "BUSCAR INDICE" Y MODIFICIAR TODAS LAS CONSULTAS