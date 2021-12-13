#include <iostream>
#include "listamateriales.h"
#include <fstream>

using namespace std;
ListaMateriales::ListaMateriales() {
    primero = 0;
    cantidad = 0;
}

ListaMateriales::~ListaMateriales() {
    destruir();
}

bool ListaMateriales::vacia() {
    return (cantidad == 0);
}

void ListaMateriales::alta(Material* d /*, int pos */) {
    NodoMateriales* nuevo = new NodoMateriales(d);
    NodoMateriales* siguiente = primero;

    if (cantidad == 0) {
        primero = nuevo;
    }
    else {
        NodoMateriales* anterior = obtener_nodo(cantidad - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
}

void ListaMateriales::baja(int pos) {
    NodoMateriales* baja = primero;
    if (pos == 1)
        primero = baja->obtener_siguiente();
    else {
        NodoMateriales* anterior = obtener_nodo(pos - 1);
        baja = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    cantidad--;
    baja->baja();
    delete baja;
    baja = NULL;
}

Material* ListaMateriales::consulta(int pos) {
    NodoMateriales* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void ListaMateriales::destruir() {
    while (! vacia())
        baja(1);
}

NodoMateriales* ListaMateriales::obtener_nodo(int pos) {
    NodoMateriales* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

int ListaMateriales::buscar_indice(std::string nombre){
    NodoMateriales* aux = primero;
    for (int i = 1; i < this->cantidad+1; i++){
        if(aux->obtener_dato()->devolver_nombre()==nombre)
            return i;
        aux = aux->obtener_siguiente();
    }
    return -1;
}


void ListaMateriales::mostrar() {
    NodoMateriales* aux = primero;
    
    while (aux) {
        std::cout <<"Material: "<< aux->obtener_dato()->devolver_nombre() << ", Cantidad: "<<aux->obtener_dato()->devolver_cantidad()<<std::endl;
        aux = aux->obtener_siguiente();
    }
    std::cout<<"-------------------------------------------------"<<std::endl;
}

int ListaMateriales::devolver_cantidad(){
    return this->cantidad;
}
