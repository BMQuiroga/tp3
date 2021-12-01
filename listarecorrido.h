#ifndef LISTARECORRIDO_H
#define LISTARECORRIDO_H

#include <iostream>

typedef int Dato;

class ListaRecorrido {
    
private:
    Dato* lista;
    int cantidad = 0;
public:
    ListaRecorrido();
    ~ListaRecorrido();
    void agregar(int dato);
    int devolver_cantidad();
    void mostrar();
    bool contiene(int dato);
private:
    void copiar(Dato* lista);
    void liberar_memoria();
};

#endif