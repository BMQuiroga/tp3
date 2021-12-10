#include <string>
#ifndef CASILLERO_H
#define CASILLERO_H
#include "listamateriales.h"
#include "arboledificios.h"
#include "jugador.h"



//class CasilleroConstruible;

//class CasilleroTransitable;

//class CasilleroInaccesible;

class Jugador;

class Casillero{

protected:

    int id;
    char tipo;
    char letra;
    
public:

    Casillero() {};
    // virtual ~Casillero()=0;
    // virtual ~Casillero() = 0;

    //Pre:
    //Post:Retorna el tipo de casillero
    char devolver_tipo();

    void setear_id(int id);

    int obtener_id();
    
    //Pre:
    //Post:Devuelve el nombre del material o edificio que se encuentre en el casillero
    virtual std::string devolver_material_o_edificio() = 0;

    //Pre:Recibe el nombre del material
    //Post:Asigna al atributo material el que le pasan
    virtual void poner_material(Material* material) = 0;//Se usa en la lluvia de materiales  

    //Pre:
    //Post:Chequea si en el casillero hay material o edificio
    virtual bool tiene_material_o_edificio() = 0;

    //Pre:Recibe el objeto edificio
    //Post:Asigna nombre, piedra, madera, metal, max a los atributos respectivos de edificio
    virtual void construir(Edificio* edificio) = 0;//Usado cuando se lee el archivo ubicacines y cuando se construye desde el menu
    
    //Pre:Recibe la lista de materiales cargada
    //Post:Suma los materiales producidos por la mina, aserradero y fabrica a la lista de materiales.
    virtual void recolectar_material(Jugador* jugador) = 0;

    //Pre::Recibe la lista de materiales cargada
    //Post:Realiza la destruccion, modificando la cantidad de materiales
    virtual void demoler(Jugador* jugador)=0;

    //Pre:
    //Post:Retorna el jugador que es el dueño del edificio
    virtual int devolver_jugador() = 0;

    //Pre:
    //Post:Cambia quien es el dueño del edificio
    virtual void cambiar_jugador(int numero) = 0;

    //Pre:
    //Post: Le resta 1 de vida al edificio, devuelve si lo destruyó
    virtual bool atacar() = 0;

    //Pre:
    //Post: Le suma 1 de vida al edificio, si tiene 2 de vida maxima
    virtual void reparar(Jugador* jugador) = 0;

    //Pre:
    //Post: muestra el tipo de casillero y si tiene_material_o_edificio()
    virtual void mostrar() = 0;

    char devolver_tipo_camino();
};


#endif 