//#include <string>
#include "casillero.h"
#include "material.h"
#ifndef CASILLEROTRANSITABLE_H
#define CASILLEROTRANSITABLE_H

class CasilleroTransitable : public Casillero{//Camino

private:
    Material material;
    std::string tipo_de_camino;

public:
    ~CasilleroTransitable() {};
    //Pre:Recibe el nombre del material
    //Post:Asigna al atributo material el que le pasan
    void poner_material(Material material);//Se usa en la lluvia de materiales

    //Pre:
    //Post: Devuelve true si hay material
    bool tiene_material_o_edificio();
    
    //Pre:
    //Post: Crea un objeto, asignandole "C" al tipo
    CasilleroTransitable(std::string camino);
    

    //Pre:
    //Post: No hace nada
    void construir(Edificio edificio);
    
    //Pre:
    //Post: Devuelve el nombre del material
    std::string devolver_material_o_edificio();
    
    //Pre:
    //Post: No hace nada
    void recolectar_material(Jugador jugador);

    //Pre:
    //Post: No hace nada
    void demoler(Jugador jugador);

    int devolver_jugador();

    void cambiar_jugador(int numero);

    bool atacar();

    void reparar(Jugador jugador);


};

#endif 