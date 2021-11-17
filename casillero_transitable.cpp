#include <iostream>
#include "casillero_transitable.h"

/*void CasilleroTransitable::recolectar_material(){
    //En esta linea le sumo la cantidad material a nuestro array de recursos disponibles
    this->cantidad_material=0;

}*/

void CasilleroTransitable::poner_material(Material mat){
    this->material = mat;

}

bool CasilleroTransitable::tiene_material_o_edificio(){
    return (this->material.devolver_nombre() != "0");
}

std::string CasilleroTransitable::devolver_material_o_edificio(){
    return this->material.devolver_nombre();
}

/*char CasilleroTransitable::devolver_tipo(){
    return this->tipo;
}*/

CasilleroTransitable::CasilleroTransitable(std::string camino){
    Material material;
    this->material = material;
    this->tipo = 'C';
    this->tipo_de_camino=camino;
}

void CasilleroTransitable::construir(Edificio edificio){

}

void CasilleroTransitable::recolectar_material(Jugador jugador){
    
}

void CasilleroTransitable::demoler(Jugador jugador){
    
}

//Casillero::~Casillero(){
//}

void CasilleroTransitable::cambiar_jugador(int numero){
    //this->jugador=numero;
}

int CasilleroTransitable::devolver_jugador(){
    //return this->jugador;
    return 0;
}