#include <iostream>
#include "casillero_construible.h"
#include "listaedificios.h"

void CasilleroConstruible::construir(Edificio edificio){
    //this->edificio=edificio;
    this->edificio.cambiar_todo(
    edificio.devolver_nombre(),
    edificio.devolver_piedra(),
    edificio.devolver_madera(),
    edificio.devolver_metal(),
    edificio.devolver_maximos_permitidos()
    );
}

CasilleroConstruible::CasilleroConstruible(){
    this->edificio = Edificio();
    this->tipo = 'T';
    this->jugador=0;
}



std::string CasilleroConstruible::devolver_material_o_edificio(){
    return this->edificio.devolver_nombre();
}

void CasilleroConstruible::demoler(Jugador jugador){
    this->edificio.demoler(jugador);
}

void CasilleroConstruible::recolectar_material(Jugador jugador){
    int indice;
    // if (this->edificio.devolver_nombre() == "mina"){
    //     indice=jugador.devolver_materiales()->buscar_indice("piedra");
    //     jugador.devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(15);
    //     std::cout << "Recolectados 15 de piedra" << std::endl;
    // }
    // if (this->edificio.devolver_nombre() == "aserradero"){
    //     indice=jugador.devolver_materiales()->buscar_indice("madera");
    //     jugador.devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(25);
    //     std::cout << "Recolectados 25 de madera" << std::endl;
    // }
    // if (this->edificio.devolver_nombre() == "fabrica"){
    //     indice=jugador.devolver_materiales()->buscar_indice("metal");
    //     jugador.devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(40);
    //     std::cout << "Recolectados 40 de metal" << std::endl;
    // }
    // if (this->edificio.devolver_nombre() == "escuela"){
    //     indice=jugador.devolver_materiales()->buscar_indice("andycoins");
    //     jugador.devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(25);
    //     std::cout << "Recolectados 25 andycoins" << std::endl;
    // }
    // if (this->edificio.devolver_nombre() == "planta electrica"){
    //     jugador.sumar_energia(15);
    //     std::cout << "Recolectados 15 de energia" << std::endl;
    // }
    // if (this->edificio.devolver_nombre() == "mina oro"){
    //     indice=jugador.devolver_materiales()->buscar_indice("andycoins");
    //     jugador.devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(50);
    //     std::cout << "Recolectados 50 andycoins" << std::endl;
    // }
    
    if (this->edificio.devolver_nombre() == "mina"){
        indice=jugador.devolver_materiales().buscar_indice("piedra");
        jugador.devolver_materiales().obtener_nodo(indice)->sumar_cantidad(15);
        std::cout << "Recolectados 15 de piedra" << std::endl;
    }
    if (this->edificio.devolver_nombre() == "aserradero"){
        indice=jugador.devolver_materiales().buscar_indice("madera");
        jugador.devolver_materiales().obtener_nodo(indice)->sumar_cantidad(25);
        std::cout << "Recolectados 25 de madera" << std::endl;
    }
    if (this->edificio.devolver_nombre() == "fabrica"){
        indice=jugador.devolver_materiales().buscar_indice("metal");
        jugador.devolver_materiales().obtener_nodo(indice)->sumar_cantidad(40);
        std::cout << "Recolectados 40 de metal" << std::endl;
    }
    if (this->edificio.devolver_nombre() == "escuela"){
        indice=jugador.devolver_materiales().buscar_indice("andycoins");
        jugador.devolver_materiales().obtener_nodo(indice)->sumar_cantidad(25);
        std::cout << "Recolectados 25 andycoins" << std::endl;
    }
    if (this->edificio.devolver_nombre() == "planta electrica"){
        jugador.sumar_energia(15);
        std::cout << "Recolectados 15 de energia" << std::endl;
    }
    if (this->edificio.devolver_nombre() == "mina oro"){
        indice=jugador.devolver_materiales().buscar_indice("andycoins");
        jugador.devolver_materiales().obtener_nodo(indice)->sumar_cantidad(50);
        std::cout << "Recolectados 50 andycoins" << std::endl;
    }
}

/*char CasilleroConstruible::devolver_tipo(){
    return this->tipo;
}*/

bool CasilleroConstruible::tiene_material_o_edificio(){
    return (this->edificio.devolver_maximos_permitidos() != 0);
}

void CasilleroConstruible::poner_material(Material material){
    
}

//Casillero::~Casillero(){
//}

void CasilleroConstruible::cambiar_jugador(int numero){
    this->jugador=numero;
}

int CasilleroConstruible::devolver_jugador(){
    return this->jugador;
}

bool CasilleroConstruible::atacar(){
    return (this->edificio.restar_vida(1));
}

void CasilleroConstruible::reparar(Jugador jugador){
    bool hay_piedra;
    bool hay_madera;
    bool hay_metal;
    int piedra=(this->edificio.devolver_piedra())/4;
    int madera=(this->edificio.devolver_madera())/4;
    int metal=(this->edificio.devolver_metal())/4;
    if(this->edificio.devolver_vida()==1){
        if(jugador.devolver_energia()>=25){
            hay_piedra=(piedra<=jugador.devolver_materiales().consulta(jugador.devolver_materiales().buscar_indice("piedra")).devolver_cantidad());
            hay_madera=(madera<=jugador.devolver_materiales().consulta(jugador.devolver_materiales().buscar_indice("madera")).devolver_cantidad());
            hay_metal=(metal<=jugador.devolver_materiales().consulta(jugador.devolver_materiales().buscar_indice("metal")).devolver_cantidad());
            if(hay_piedra && hay_madera && hay_metal){
                this->edificio.restar_vida(-1);
                jugador.devolver_materiales().obtener_nodo(jugador.devolver_materiales().buscar_indice("piedra"))->restar_cantidad(piedra);
                jugador.devolver_materiales().obtener_nodo(jugador.devolver_materiales().buscar_indice("madera"))->restar_cantidad(madera);
                jugador.devolver_materiales().obtener_nodo(jugador.devolver_materiales().buscar_indice("metal"))->restar_cantidad(metal);
            }
            else
                std::cout<<"No alcanzan los materiales para reparar el edificio!"<<std::endl;
        }
        else
            std::cout<<"No tienes energia suficiente!"<<std::endl;
    }
    else
        std::cout<<"Ese edificio no está dañado!"<<std::endl;
}