
#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H

#include "casillero.h"
#include "edificio.h"
#include <string>
#include "material.h"
#include "listamateriales.h"
#include "arboledificios.h"

class Casillero;

class Jugador;

class CasilleroConstruible : public Casillero {//Terreno

private:
    Edificio* edificio; 
    int jugador;
    int vida;
    
public:
    
    //Pre:-
    //Post: Crea un objeto, asignando los atributos  
    CasilleroConstruible();

    //pre: -
    //pos: -
    ~CasilleroConstruible();
    
    //Pre: Recibe el objeto edificio
    //Post: Asigna nombre, piedra, madera, metal, max a edificio
    void construir(Edificio* edificio);//Usado cuando se lee el archivo ubicacines y cuando se construye desde el menu

    //Pre:
    //Post: Devuelve true si los max_permitidos es != 0   
    bool tiene_material_o_edificio();

    //Pre:
    //Post: Devuelve el nombre del edificio
    std::string devolver_material_o_edificio();

    //Pre: Recibe la lista de materiales
    //Post: Suma los materiales producidos por la mina, aserradero y fabrica a la lista de materiales.
    void recolectar_material(Jugador* jugador);

    //Pre: Recibe la lista de materiales
    //Post: Realiza la destruccion, modificando la cantidad de materiales   
    void demoler(Jugador* jugador);

    //Pre: -
    //Post: - 
    void poner_material(Material* material);

    //Pre:
    //Post:Retorna el jugador que es el dueño del edificio 
    int devolver_jugador();

    //Pre:
    //Post:Cambia quien es el dueño del edificio
    void cambiar_jugador(int numero);

    //Pre:
    //Post: Le resta 1 de vida al edificio, devuelve si lo destruyó
    bool atacar();

    //Pre:
    //Post: Le suma 1 de vida al edificio, si tiene 2 de vida maxima
    void reparar(Jugador* jugador);

    //Pre:
    //Post: muestra "soy un casillero construible" y si tiene_material_o_edificio()
    void mostrar();
};


#endif 