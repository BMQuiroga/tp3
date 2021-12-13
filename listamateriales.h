#ifndef LISTAMATERIALES_H
#define LISTAMATERIALES_H

#include "nodomateriales.h"
#include <string>

class ListaMateriales {

private:
    NodoMateriales* primero;
    int cantidad;
public:

    //PRE: -
    //POS: tope = 0
    ListaMateriales();

    //pre: -
    //pos: -
    ~ListaMateriales();

    //PRE: 1 <= pos <= cantidad + 1
    //POS: agrega d arriba de la pila e incrementa tope en 1
    void alta(Material* d /*, int pos */);

    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba
    Material* consulta(int pos);

    //pre: -
    //pos: destruye los punteros
    void destruir();

    //PRE: -
    //POS: muestra todos los materiales y sus cantidades
    void mostrar();

    //PRE: -
    //POS: devuelve el indice del material
    int buscar_indice(std::string nombre);

    //PRE: -
    //POS: reescribe el archivo materiales.txt
    //void reescribir_materiales();


    //PRE: posicion valida
    //POS: devuelve el puntero al nodo de una posicion
    NodoMateriales* obtener_nodo(int pos);

    //PRE: -
    //POS: devuelve la cantidad de elementos
    int devolver_cantidad();

private:
    
    //PRE: -
    //POS: contruye la lista en base a materiales.txt
    //void procesar_archivo_materiales();

    
    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba y decrementa tope
    void baja(int pos);


    //PRE: -
    //POS: devuelve true si la pila esta vacia, false si no
    bool vacia();

};



#endif 