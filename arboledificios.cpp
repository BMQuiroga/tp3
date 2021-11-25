#include "arboledificios.h"

ArbolEdificios::ArbolEdificios(Edificio edificio){
    RamaEdificios nuevo(edificio);
    RamaEdificios *p=&nuevo;
    this->raiz=p;
}

void ArbolEdificios::alta(std::string nombre, int piedra, int madera, int metal, int maximos){
    Edificio edificio(nombre,piedra,madera,metal,maximos);
    this->raiz->asignar_nodo(edificio);
}