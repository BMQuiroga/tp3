#include <iostream>
#include "listamateriales.h"
#include <fstream>

ListaMateriales::ListaMateriales() {
    primero = 0;
    cantidad = 0;
    procesar_archivo_materiales();
}

bool ListaMateriales::vacia() {
    return (cantidad == 0);
}

void ListaMateriales::alta(Material d, int pos) {
    NodoMateriales* nuevo = new NodoMateriales(d);
    //std::cout << "Pido memoria en: " << nuevo << std::endl;
    NodoMateriales* siguiente = primero;

    if (pos == 1) {
        primero = nuevo;
    }
    else {
        NodoMateriales* anterior = obtener_nodo(pos - 1);
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
    //std::cout << "Libero memoria en: " << baja << std::endl;

    delete baja;
}

Material ListaMateriales::consulta(int pos) {
    NodoMateriales* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void ListaMateriales::destruir() {
    //std::cout<<"LLAMO DESTRUCTOR MATERIALES"<<std::endl;
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
        if(aux->obtener_dato().devolver_nombre()==nombre)
            return i;
        aux = aux->obtener_siguiente();
    }
    return -1;
}


void ListaMateriales::mostrar() {
    NodoMateriales* aux = primero;
    while (aux) {
        std::cout <<"Material: "<< aux->obtener_dato().devolver_nombre() << ", Cantidad: "<<aux->obtener_dato().devolver_cantidad()<<std::endl;
        aux = aux->obtener_siguiente();
    }
    std::cout<<"-------------------------------------------------"<<std::endl;
}

void ListaMateriales::procesar_archivo_materiales(){
    std::string nombre,numero;
    int num = 0;

    std::ifstream archivo("materiales.txt"); //abro el archivo modo lectura

    if(!archivo.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo materiales" <<std::endl;
    }else{
        while(archivo >> nombre){ //voy guardando hasta un espacio
            archivo>>numero;
            num=stoi(numero);
            Material material(nombre,num);
            //std::cout<<cantidad<<std::endl;
            this->alta(material,cantidad+1);
            
        }
    archivo.close();
    }
}


/*void ListaMateriales::buscar_indice(){
    NodoMateriales* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;



}*/

void ListaMateriales::reescribir_materiales(){
    std::ofstream archivo_materiales;
    archivo_materiales.open("materiales.txt");

    if(!archivo_materiales.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo materiales" <<std::endl;
    }else{
        for (int i=0;i<cantidad;i++){
            //std::cout<<this->consulta(i+1).devolver_nombre()<<std::endl;
            archivo_materiales<<this->consulta(i+1).devolver_nombre();
            archivo_materiales<<" ";
            archivo_materiales<<this->consulta(i+1).devolver_cantidad();
            archivo_materiales<<std::endl;
        }
    archivo_materiales.close();
    }
}

int ListaMateriales::devolver_cantidad(){
    return this->cantidad;
}