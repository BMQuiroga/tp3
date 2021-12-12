#include "listarecorrido.h"

ListaRecorrido::ListaRecorrido() {
    this->cantidad = 0;
}

int ListaRecorrido::devolver_cantidad() {
    return this->cantidad;
}

void ListaRecorrido::copiar(Dato* lista) {
    for (int i = 0; i < this->devolver_cantidad(); i++) {
        lista[i] = this->lista[i];
    }
}

void ListaRecorrido::agregar(Dato dato) {
    int cantidad = this->devolver_cantidad();
    Dato* lista_copia = new Dato [cantidad + 1];

    copiar(lista_copia);
    lista_copia[cantidad] = dato;

    if (devolver_cantidad() != 0) {
        liberar_memoria();
    }

    this->lista = lista_copia;
    this->cantidad++;
}

void ListaRecorrido::mostrar() {
    for (int i = 0; i < devolver_cantidad(); i++) {
        std::cout << lista[i] << "->";
    }
    std::cout << std::endl;
}

bool ListaRecorrido::contiene(Dato dato) {
    int contador = 0;
    bool resultado = false;
    while(contador < this->devolver_cantidad() && !resultado) {
        if (this->lista[contador] == dato) {
            resultado = true;
        }
        contador++;
    }
    return resultado;
}

void ListaRecorrido::liberar_memoria() {
    delete [] lista;
}

ListaRecorrido::~ListaRecorrido() {
    liberar_memoria();
}

