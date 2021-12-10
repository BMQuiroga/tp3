#ifndef RAMAEDIFICIOS_H
#define RAMAEDIFICIOS_H

#include <iostream>
#include "arboledificios.h"
#include <fstream>

class RamaEdificios{

private:
    std::string clave;
    Edificio* valor;
    RamaEdificios* nodo_izq;
    RamaEdificios* nodo_der;

public:

    RamaEdificios(Edificio* edificio);

    //PRE: -
    //POST: Devuelve un edificio, lo busca por nombre
    Edificio* buscar_edificio(std::string edificio);

    //PRE: -
    //POST: Crea un nuevo nodo
    void asignar_nodo(/*RamaEdificios* rama,*/ Edificio* edificio);

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

    //PRE: -
    //POST: Añade al array su edificio, y llama a la funcion en sus 2 hijas, si existen
    int devolver_todo(Edificio** array, int contador);

    //PRE: -
    //POST: Busca el nodo con el mismo nombre y lo cambia por el nuevo edificio
    void cambiar_edificio(Edificio* edificio);

    //PRE: -
    //POST: guarda el edificio a edificios.txt
    void guardar(std::ofstream & archivo);

    //PRE -
    //POST: recorre el arbol y va guardando los edificios en edificios.txt
    void modificar(std::ofstream & archivo);
};


#endif