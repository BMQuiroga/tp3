#ifndef LISTAEDIFICIOS_H
#define LISTAEDIFICIOS_H

#include "nodoedificios.h"


class ListaEdificios {
    
private:
    NodoEdificios* primero;
    int cantidad;

public:
    //Constructor
    //PRE: -
    //POS: tope = 0
    ListaEdificios();

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

    
private:
    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba y decrementa tope
    void baja(int pos);


    //PRE: -
    //POS: devuelve true si la pila esta vacia, false si no
    bool vacia();

    //PRE -
    //POST: obtiene el nodo en una posicion
    NodoEdificios* obtener_nodo(int pos);

    //PRE: -
    //POS: carga la lista con los datos del archivo edificios
    void procesar_archivo_edificios();

};



#endif