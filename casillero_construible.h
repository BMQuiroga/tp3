
#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H

#include "casillero.h"
#include "edificio.h"
#include <string>
#include "material.h"
#include "listamateriales.h"
#include "listaedificios.h"


class CasilleroConstruible : public Casillero{//Terreno

private:
    Edificio edificio;
    int jugador;
    
public:
    //Pre: Recibe el objeto edificio
    //Post: Asigna nombre, piedra, madera, metal, max a edificio
    void construir(Edificio edificio);//Usado cuando se lee el archivo ubicacines y cuando se construye desde el menu
    
    //Pre:-
    //Post: Crea un objeto, asignando los atributos  
    CasilleroConstruible();

    //Pre:
    //Post: Devuelve true si los max_permitidos es != 0   
    bool tiene_material_o_edificio();

    //Pre:
    //Post: Devuelve el nombre del edificio
    std::string devolver_material_o_edificio();

    //Pre: Recibe la lista de materiales
    //Post: Suma los materiales producidos por la mina, aserradero y fabrica a la lista de materiales.
    void recolectar_material(Jugador jugador);

    //Pre: Recibe la lista de materiales
    //Post: Realiza la destruccion, modificando la cantidad de materiales   
    void demoler(Jugador jugador);

    //Pre: -
    //Post: - 
    void poner_material(Material material);

    int devolver_jugador();

    void cambiar_jugador(int numero);
};


#endif 