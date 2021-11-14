#include <string>
#ifndef CASILLERO_H
#define CASILLERO_H
#include "listaedificios.h"
#include "listamateriales.h"


class Casillero{

protected:
    char tipo;

public:
    //Pre:
    //Post:Retorna el tipo de casillero
    char devolver_tipo();

    virtual ~Casillero()=0;

    //Pre:
    //Post:Si el casillero es construible devuelve el nombre del edificio
    //     Si el casillero es transitable devuelve el nombre del material 
    virtual std::string devolver_material_o_edificio()=0;

    //Pre:Recibe el nombre del material
    //Post:Asigna al atributo material el que le pasan
    virtual void poner_material(Material material)=0;//Se usa en la lluvia de materiales  

    //Pre:
    //Post:Si el casillero es construible devuelve true si el max_permitido!=0
    //     Si el casillero es transitable devuelve true si hay algun material  
    virtual bool tiene_material_o_edificio()=0;

    //Pre:Recibe el objeto edificio
    //Post:Si el casillero es construible asigna nombre, piedra, madera, metal, max a los atributos respectivos de edificio
    virtual void construir(Edificio edificio)=0;//Usado cuando se lee el archivo ubicacines y cuando se construye desde el menu
    
    //Pre:Recibe la lista de materiales cargada
    //Post:Suma los materiales producidos por la mina, aserradero y fabrica a la lista de materiales.
    virtual void recolectar_material(ListaMateriales materiales)=0;

    //Pre::Recibe la lista de materiales cargada
    //Post:Realiza la destruccion, modificando la cantidad de materiales
    virtual void demoler(ListaMateriales materiales)=0;

    virtual int devolver_jugador();

    virtual void cambiar_jugador(int numero);
};


#endif 