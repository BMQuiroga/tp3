#include <iostream>
#include "nodoedificios.h"
#include "edificio.h"

//Constructor
NodoEdificios::NodoEdificios(std::string nombre, int piedra, int madera, int metal, int maximos) {
    dato = Edificio();
    dato.cambiar_todo(nombre,piedra,madera,metal,maximos);
    //std::cout<<"dada de alta "<<nombre<<std::endl;
    siguiente = 0;
}

void NodoEdificios::cambiar_dato(Edificio d) {
    dato = d;
}

void NodoEdificios::cambiar_siguiente(NodoEdificios* pn) {
    siguiente = pn;
}

Edificio NodoEdificios::obtener_dato() {
    return dato;
}

NodoEdificios* NodoEdificios::obtener_siguiente() {
    return siguiente;
}