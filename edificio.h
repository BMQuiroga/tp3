#include <string>
#include "material.h"
#include "listamateriales.h"

#ifndef EDIFICIOOBJ_H
#define EDIFICIOOBJ_H



class Edificio{

private:
    std::string nombre;
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maximos_permitidos;

public:

    //Pre:
    //Post:Crea un objeto edificio con nombre,cant de piedra, cant de madera, cant de metal y maximos permitidos por cada edificio.
    Edificio(std::string nombre, int piedra, int madera, int metal, int max);

    //Pre:-
    //Post:Crea un objeto edificio con nombre, cant piedra, cant madera, cant metal, maximos permitidos asignados en 0.
    Edificio();

    //pre: -
    //pos: destructor de edificio
    ~Edificio();

    //Pre:-
    //Post:Retorna el nombre del edificio
    std::string devolver_nombre();

    //Pre: Recibe el objeto construccion
    //Post:Devuelve el objeto cargado con nombre,cant piedra, cant madera, cant metal y maximos permitidos.
    Edificio operator=(Edificio construccion);

    //Pre:-
    //Post: Asigna nombre, piedra, madera, metal, max a los atributos respectivos de edificio
    void cambiar_todo(std::string nombre, int piedra, int madera, int metal, int max);

    //Pre:-
    //Post:Devuelve la cantidad de piedra del edificio
    int devolver_piedra();

    //Pre:-
    //Post:Devuelve la cantidad de madera del edificio
    int devolver_madera();

    //Pre:-
    //Post:Devuelve la cantidad de metal del edificio
    int devolver_metal();

    //Pre:-
    //Post:Devuelve los maximos permitidos del edificio
    int devolver_maximos_permitidos();

    //Pre:-
    //Post:Muestra por pantalla los materiales y la cant que produce la mina, el aserradero y la fabrica
    void imprimir_brinda_materiales();

    //Pre:-
    //Post:Pide datos nuevos y modifica el edificio en cuestion
    void modificar_datos();
};


#endif 