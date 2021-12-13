#ifndef NODOMATERIALES_H
#define NODOMATERIALES_H
#include "material.h"


class NodoMateriales {
//Atributos
private:
    Material* dato;
    NodoMateriales* siguiente;

//Metodos
public:
    //constructor
    //PRE:Recibe la clase Material
    //POS:Crea el constructor y el siguiente lo deja en nulo
    NodoMateriales(Material* d);

    // ~NodoMateriales();

    //PRE:-
    //POS:Asigna d a dato
    void cambiar_dato(Material* d);

    //PRE:Recibe un puntero a nodo(direccion)
    //POS:Asigna el puntero a siguiente
    void cambiar_siguiente(NodoMateriales* pn);

    //PRE:-
    //POS:Devuelve el dato
    Material* obtener_dato();

    //PRE:-
    //POS:Devuelve el puntero del siguiente
    NodoMateriales* obtener_siguiente();

    //PRE: -
    //POS: Cambia la cantidad del material del nodo
    void cambiar_cantidad(int d);

    //PRE: -
    //POS: A la cantidad del material, le suma un numero
    void sumar_cantidad(int d);

    //PRE: -
    //POS: A la cantidad del material, le resta un numero
    void restar_cantidad(int d);

    //PRE: -
    //POS: da de baja el nodo
    void baja();
};


#endif