#include "jugador.h"
#include <iostream>

Jugador::Jugador(int x,int y,int numero){
    mover_gratis(x,y);
    this->energia=50;
    this->nombre=numero;
    
    int a=0;
    int b=0;
    int c=0;

    while (a==b || b==c || a==c){
        a=generador_de_numeros_aleatorios(1,11);
        b=generador_de_numeros_aleatorios(1,11);
        c=generador_de_numeros_aleatorios(1,11);
    }
    
    this->objetivo_1=Objetivo(a);
    this->objetivo_2=Objetivo(b);
    this->objetivo_3=Objetivo(c);
    this->objetivo_principal=Objetivo(11);

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

// ListaMateriales* Jugador::devolver_materiales(){
//     return this->materiales;
// }

ListaMateriales Jugador::devolver_materiales() {
    return this->materiales;
}

int Jugador::devolver_nombre(){
    return this->nombre;
}

int Jugador::devolver_coordenada_x(){
    return this->coordenada_x;
}

int Jugador::devolver_coordenada_y(){
    return this->coordenada_y;
}

bool Jugador::checkear_objetivos(){
    return((objetivo_1->checkear() && objetivo_2->checkear()) ||
           (objetivo_2->checkear() && objetivo_3->checkear()) ||
           (objetivo_1->checkear() && objetivo_3->checkear()) ||
           (objetivo_principal->checkear()));
}