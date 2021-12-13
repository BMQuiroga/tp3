#ifndef LISTARECORRIDO_H
#define LISTARECORRIDO_H

#include <iostream>

typedef int Dato;

class ListaRecorrido {
    
private:
    Dato* lista;
    int cantidad = 0;
public:
    //pre: -
    //pos: -
    ListaRecorrido();

    //pre: -
    //pos: -
    ~ListaRecorrido();

    //pre: dato valido
    //pos: agrega el dato a la lista
    void agregar(Dato dato);

    //pre: -
    //pos: devuelve la cantidad de elementos de la lista
    int devolver_cantidad();

    //pre: -
    //pos: muestra los nodos recorridos
    void mostrar();

    //pre: -
    //pos: verifica si dato esta dentro de la lista
    bool contiene(Dato dato);
private:
    //pre: -
    //pos: copia la lista del objeto con la lista pasada por parametro
    void copiar(Dato* lista);

    //pre: -
    //pos: libera la memoria
    void liberar_memoria();
};

#endif