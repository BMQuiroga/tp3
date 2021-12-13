

#ifndef TP3_2021_2C_CONSTRUCTOR_H
#define TP3_2021_2C_CONSTRUCTOR_H

#include "objetivo.h"

class Constructor : public Objetivo {
private:
    ListaEdificios * edificios;
    Mapa * mapa;
    Jugador * jugador;
    int edificios_construidos;
    int edificios_requeridos;
    /*
    int cantidad_yacimiento;
    int cantidad_mina;
    int cantidad_mina_oro;
    int cantidad_planta_electrica;
    int cantidad_fabrica;
    int cantidad_aserradero;
    int cantidad_escuela;
    int cantidad_casa;
    int cantidad_necesaria;
    */
    bool cumplio;
public:

    //Pre:-
    //Pos: Muestra por pantalla el objetivo, y si lo cumplio muestra que fue completado
    void mostrar();

   
    void mostrar_progreso();

    //Pre: Recibe la lista de edificios y el jugador de la partida
    //Pos: Inicializa los atributos
    Constructor(ListaEdificios *edificios, Jugador * jugador);

    //Pre:-
    //Pos:Retorna la cantidad de edificios construidos
    int calcular_progreso();

    //Pre:-
    //Pos: Devuelve true si la cant de edificios construidos== cant de edif requeridos
    bool checkear();

    //Pre:-
    //Pos: Actualiza los edificios construidos
    void actualizar();
    /*
    void actualizar_yacimiento(int valor);
    void actualizar_mina(int valor);
    void actualizar_mina_oro(int valor);
    void actualizar_planta_electrica(int valor);
    void actualizar_fabrica(int valor);
    void actualizar_aserradero(int valor);
    void actualizar_escuela(int valor);
    void actualizar_casa(int valor);
    */
};


#endif //TP3_2021_2C_CONSTRUCTOR_H
