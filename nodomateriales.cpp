#include "nodomateriales.h"
#include "material.h"

//Constructor
NodoMateriales::NodoMateriales(Material* d) {
    dato = d;
    siguiente = 0;
}

void NodoMateriales::cambiar_dato(Material* d) {
    dato = d;
}

void NodoMateriales::cambiar_siguiente(NodoMateriales* pn) {
    siguiente = pn;
}

Material* NodoMateriales::obtener_dato() {
    return dato;
}

NodoMateriales* NodoMateriales::obtener_siguiente() {
    return siguiente;
}

void NodoMateriales::cambiar_cantidad(int d){
    this->dato->modificar_cantidad(d);
}

void NodoMateriales::sumar_cantidad(int d){
    this->dato->sumar_cantidad(d);
}

void NodoMateriales::restar_cantidad(int d){
    this->dato->sumar_cantidad(-d);
}