//#include <string>
#include "casillero.h"
#include "material.h"
#ifndef CASILLEROTRANSITABLE_H
#define CASILLEROTRANSITABLE_H

class Casillero;

class Jugador;

class CasilleroTransitable : public Casillero{//Camino

private:
    Material* material;
    std::string tipo_de_camino;

public:
    //Pre:
    //Post: Crea un objeto, asignandole "C" al tipo
    CasilleroTransitable(std::string camino);
    
    //pre:
    //pos:
    ~CasilleroTransitable();

    //Pre:Recibe el nombre del material
    //Post:Asigna al atributo material el que le pasan
    void poner_material(Material* material);//Se usa en la lluvia de materiales

    //Pre:
    //Post: Devuelve true si hay material
    bool tiene_material_o_edificio();
    
    //Pre:
    //Post: No hace nada
    void construir(Edificio* edificio);
    
    //Pre:
    //Post: Devuelve el nombre del material
    std::string devolver_material_o_edificio();
    
    //Pre:
    //Post: No hace nada
    void recolectar_material(Jugador* jugador);

    //Pre:
    //Post: No hace nada
    void demoler(Jugador* jugador);

    //Pre:
    //Post: No hace nada
    int devolver_jugador();

    //Pre:
    //Post: No hace nada
    void cambiar_jugador(int numero);

    //Pre:
    //Post: No hace nada
    bool atacar();

    //Pre:
    //Post: No hace nada
    void reparar(Jugador* jugador);

    //Pre:
    //Post: Muestra "soy un casillero transitable" y si tiene algun material
    void mostrar();

    //pre: -
    //pos: devuelve el tipo de camino
    std::string devolver_tipo_camino();


    void liberar_memoria();
};

#endif 