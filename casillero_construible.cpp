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
}



std::string CasilleroConstruible::devolver_material_o_edificio(){
    return this->edificio.devolver_nombre();
}

void CasilleroConstruible::demoler(ListaMateriales materiales){
    this->edificio.demoler(materiales);
}

void CasilleroConstruible::recolectar_material(ListaMateriales materiales){
    int indice;
    if (this->edificio.devolver_nombre() == "mina"){
        indice=materiales.buscar_indice("piedra");
        materiales.obtener_nodo(indice)->sumar_cantidad(15);
        std::cout << "Recolectados 15 de piedra" << std::endl;
    }
    if (this->edificio.devolver_nombre() == "aserradero"){
        indice=materiales.buscar_indice("madera");
        materiales.obtener_nodo(indice)->sumar_cantidad(25);
        std::cout << "Recolectados 25 de madera" << std::endl;
    }
    if (this->edificio.devolver_nombre() == "fabrica"){
        indice=materiales.buscar_indice("metal");
        materiales.obtener_nodo(indice)->sumar_cantidad(40);
        std::cout << "Recolectados 40 de metal" << std::endl;

    }
}

/*char CasilleroConstruible::devolver_tipo(){
    return this->tipo;
}*/

bool CasilleroConstruible::tiene_material_o_edificio(){
    return (this->edificio.devolver_maximos_permitidos() != 0);
}

void CasilleroConstruible::poner_material(std::string material){
    
}

//Casillero::~Casillero(){
//}