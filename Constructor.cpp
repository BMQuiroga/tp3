//
// Created by ydsas on 4/12/2021.
//

#include "Constructor.h"
#include <iostream>
#include "mapa.h"

Constructor::Constructor(ListaEdificios *edificios, Mapa * mapa,Jugador *jugador) {

    this->nombre="Constructor";
    this->edificios = edificios;
    this->mapa = mapa;
    /*
    this->cantidad_yacimiento = 0;
    this->cantidad_mina = 0;
    this->cantidad_mina_oro = 0;
    this->cantidad_planta_electrica = 0;
    this->cantidad_fabrica = 0;
    this->cantidad_aserradero = 0;
    this->cantidad_escuela = 0;
    this->cantidad_casa = 0;
    this->cantidad_necesaria = 1;*/
    this->cumplio = false;
    this->edificios_requeridos=edificios->devolver_cantidad();
    this->edificios_construidos=0;

}

void Constructor::mostrar(){
    int numero = calcular_progreso();
    std::cout << "Constructor: construir un edificio de cada tipo. " << std::endl;
    std::cout << "Edificios construidos: " << numero << "/" << edificios_requeridos << std::endl;
    if(checkear())
        std::cout << "Este objetivo ha sido completado" << std::endl;
}

bool Constructor::checkear() {
    //if (this->cantidad_yacimiento >= this->cantidad_necesaria && this->cantidad_mina >= this->cantidad_necesaria && this->cantidad_mina_oro >= this->cantidad_necesaria && this->cantidad_planta_electrica >= this->cantidad_necesaria && this->cantidad_fabrica >= this->cantidad_necesaria && this->cantidad_aserradero >= this->cantidad_necesaria && this->cantidad_escuela >= this->cantidad_necesaria && this->cantidad_casa >= this->cantidad_necesaria){
    if (edificios_construidos == edificios_requeridos) 
        this->cumplio = true;
    
    return cumplio;
}
/*
void Constructor::actualizar(string nombre, int valor) {
    if (nombre == "yacimiento")
        actualizar_yacimiento(valor);
    else if (nombre == "mina")
        actualizar_mina(valor);
    else if (nombre == "mina oro")
        actualizar_mina_oro(valor);
    else if (nombre == "planta electrica")
        actualizar_planta_electrica(valor);
    else if (nombre == "fabrica")
        actualizar_fabrica(valor);
    else if (nombre == "aserradero")
        actualizar_aserradero(valor);
    else if (nombre == "escuela")
        actualizar_escuela(valor);
    else if (nombre == "casa")
        actualizar_casa(valor);

}*/
/*
void Constructor::actualizar_aserradero(int valor) {
    this->cantidad_aserradero += valor;
}

void Constructor::actualizar_yacimiento(int valor) {
    this->cantidad_yacimiento += valor;
}

void Constructor::actualizar_mina(int valor) {
    this->cantidad_mina += valor;
}

void Constructor::actualizar_mina_oro(int valor) {
    this->cantidad_mina_oro += valor;
}

void Constructor::actualizar_planta_electrica(int valor) {
    this->cantidad_planta_electrica += valor;
}

void Constructor::actualizar_fabrica(int valor) {
    this->cantidad_fabrica += valor;
}

void Constructor::actualizar_escuela(int valor) {
    this->cantidad_escuela += valor;
}

void  Constructor::actualizar_casa(int valor) {
    this->cantidad_casa += valor;
}
*/
/*
void Constructor::mostrar_progreso() {
    cout << "Cantidad construidas de: " << endl;
    cout<< "Yacimiento: " << this->cantidad_yacimiento << endl;
    cout << "Mina: " << this->cantidad_mina << endl;
    cout << "Mina oro: " << this->cantidad_mina_oro << endl;
    cout << "Planta electrica: " << this->cantidad_planta_electrica << endl;
    cout << "Fabrica: " << this->cantidad_fabrica << endl;
    cout << "Aserradero: " << this->cantidad_aserradero << endl;
    cout << "Escuela: " << this->cantidad_escuela << endl;
    cout << "Casa: " << this->cantidad_casa << endl;
}*/


int Constructor::calcular_progreso(){
    int contador = 0;
    bool resultado = true;
    std::string nombre;
    Edificio** array_edificios = edificios->devolver_todo();
    for (int i = 0; i < edificios->devolver_cantidad()-1; i++) {
        nombre = array_edificios[i]->devolver_nombre();
        resultado = mapa->tiene_edificio(nombre, jugador);   
        if (resultado) {
            contador++;
        }
    }
    edificios_construidos = contador;
    return contador;
}

void Constructor::actualizar(int valor){
    calcular_progreso();
}