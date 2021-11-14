#ifndef NODOEDIFICIOS_H
#define NODOEDIFICIOS_H
#include "edificio.h"


class NodoEdificios {
//Atributos
private:
    Edificio dato;
    NodoEdificios* siguiente;

//Metodos
public:
    //constructor
    //PRE:Recibe nombre, cant piedra, cant madera, cant metal y max permitidos de un edificio
    //POS:Crea el constructor, carga datos y el siguiente lo deja en nulo
    NodoEdificios(std::string nombre, int piedra, int madera, int metal, int maximos);

    //PRE:Recibe la clase Edificio
    //POS:Asigna d a dato
    void cambiar_dato(Edificio d);

    //PRE:Recibe un puntero a nodo(direccion)
    //POS: Asigna el puntero a siguiente
    void cambiar_siguiente(NodoEdificios* pn);

    //PRE:-
    //POS:Devuelve el dato
    Edificio obtener_dato();

    //PRE:-
    //POS:Devuelve el puntero del siguiente
    NodoEdificios* obtener_siguiente();
};


#endif