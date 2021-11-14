#include "casillero.h"
#ifndef CASILLEROINACCESIBLE_H
#define CASILLEROINACCESIBLE_H

class CasilleroInaccesible : public Casillero{//Lago
//Atributos
private:
    //no se me ocurrio nada para ponerle a este

//Metodos
public:
    //Pre:-
    //Post:Al objeto le asigno tipo L
    CasilleroInaccesible();

    //Pre:
    //Post: Devuelve false
    bool tiene_material_o_edificio();

    //Pre:
    //Post: No hace nada
    void poner_material(Material material);//Se usa en la lluvia de materiales
    
    //Pre:
    //Post: No hace nada
    std::string devolver_material_o_edificio();

    //Pre:
    //Post: Muestra por pantalla el mensaje que no se puede construir
    void construir(Edificio edificio);//Usado cuando se lee el archivo ubicacines y cuando se construye desde el menu

    //Pre:
    //Post: No hace nada
    void recolectar_material(ListaMateriales materiales);
    
    //Pre:
    //Post: No hace nada
    void demoler(ListaMateriales materiales);

    int devolver_jugador();

    void cambiar_jugador(int numero);
};




#endif 