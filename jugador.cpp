#include "jugador.h"
#include <iostream>

Jugador::Jugador(int x,int y,int numero){
    mover_gratis(x,y);
    this->energia=50;
    this->nombre=numero;
    asignar_objetivos();
}

void Jugador::mover_gratis(int x, int y){
    this->coordenada_x=x;
    this->coordenada_y=y;
}

int Jugador::devolver_energia(){
    return this->energia;
}

void Jugador::comprar_bombas(){
    int indice=this->materiales.buscar_indice("andycoins");
    int cantidad_andycoins = this->materiales.consulta(indice).devolver_cantidad();
    int bombas=0;
    std::cout<<"Posee "<< cantidad_andycoins <<" andycoins, cuantas bombas desea comprar?"<<std::endl;
    std::cin>>bombas;

    while(bombas>cantidad_andycoins/100){
        std::cout<<"No alcanzan las andycoins, inserte un numero valido"<<std::endl;
        std::cin>>bombas;
    }

    this->materiales.obtener_nodo(materiales.buscar_indice("bombas"))->obtener_dato().operator+(bombas);
    this->materiales.obtener_nodo(materiales.buscar_indice("andycoins"))->obtener_dato().operator-(bombas*100);
    this->energia-=5;

}

ListaMateriales* Jugador::devolver_materiales(){
    return this->materiales;
}

int Jugador::devolver_nombre(){
    return this->nombre;
}