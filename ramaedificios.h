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

    RamaEdificios(Edificio edificio);

    //PRE: -
    //POST: Devuelve un edificio, lo busca por nombre
    Edificio buscar_edificio(std::string edificio);

    //PRE: -
    //POST: Crea un nuevo nodo
    void asignar_nodo(/*RamaEdificios* rama,*/ Edificio edificio);

    //PRE: -
    //POST: Devuelve la cantidad de edificios
    int contador_de_elementos();

    //PRE: -
    //POST: Devuelve si el edificio se encuentra en el diccionario
    bool es_valido(std::string nombre);

    //PRE: -
    //POST: Devuelve si tiene un hijo del lado izquierdo
    bool tiene_rama_izq();

    //PRE: -
    //POST: Devuelve si tiene un hijo del lado derecho
    bool tiene_rama_der();

    //PRE: -
    //POST: Despues de que sus hijos borraron a todos sus respectivos hijos, los borra
    void destruir();

};


#endif