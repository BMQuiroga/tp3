#include <iostream>
#include "listaedificios.h"
#include <fstream>

ListaEdificios::ListaEdificios() {
    primero = 0;
    cantidad = 0;
    procesar_archivo_edificios();
}


bool ListaEdificios::vacia() {
    return (cantidad == 0);
}

int ListaEdificios::devolver_cantidad(){
    return this->cantidad;
}

void ListaEdificios::alta(std::string nombre, int piedra, int madera, int metal, int maximos, int pos) {
    //d.mostrar();
    NodoEdificios* nuevo = new NodoEdificios(nombre,piedra,madera,metal,maximos);
    //nuevo->obtener_dato().mostrar();
    //std::cout << "Pido memoria en: " << nuevo << std::endl;
    NodoEdificios* siguiente = primero;
    
    if (pos == 1) {
        primero = nuevo;
    }
    else {
        NodoEdificios* anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
}

void ListaEdificios::baja(int pos) {
    NodoEdificios* baja = primero;
    if (pos == 1)
        primero = baja->obtener_siguiente();
    else {
        NodoEdificios* anterior = obtener_nodo(pos - 1);
        baja = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    cantidad--;
    //std::cout << "Libero memoria en: " << baja << std::endl;

    delete baja;
}

Edificio ListaEdificios::consulta(int pos) {
    NodoEdificios* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void ListaEdificios::destruir() {
    while (! vacia())
        baja(1);
}

NodoEdificios* ListaEdificios::obtener_nodo(int pos) {
    NodoEdificios* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

int ListaEdificios::buscar_indice(std::string nombre){
    NodoEdificios* aux = primero;
    for (int i = 1; i < this->cantidad+1; i++){
        if(aux->obtener_dato().devolver_nombre()==nombre)
            return i;
        aux = aux->obtener_siguiente();
    }
    return -1;
}
/*void ListaEdificios::mostrar() {
    NodoEdificios* aux = primero;
    while (aux) {
        std::cout << aux->obtener_dato() << " - ";
        aux = aux->obtener_siguiente();
    }
}*/

void ListaEdificios::procesar_archivo_edificios(){
    std::string numero,nombre;
    int piedra,madera,metal,max;
    std::ifstream archivo_edificios("edificios.txt",std::ios::in);
    if(!archivo_edificios)
        std::cout<<"El archivo no se abrio correctamente"<<std::endl;
    else{
        while(archivo_edificios>>nombre){
            if (nombre=="planta"){
                archivo_edificios>>nombre;
                nombre="planta electrica";
            }
            archivo_edificios>>numero;
            piedra=stoi(numero);
            archivo_edificios>>numero;
            madera=stoi(numero);
            archivo_edificios>>numero;
            metal=stoi(numero);
            archivo_edificios>>numero;
            max=stoi(numero);
            //std::cout<<nombre<<" "<<piedra<<" "<<madera<<" "<<metal<<" "<<max<<std::endl;
            //edificio.mostrar();
            alta(nombre,piedra,madera,metal,max,cantidad+1);
            
            
        }
    }
    archivo_edificios.close();
}




