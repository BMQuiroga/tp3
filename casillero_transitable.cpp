#include <iostream>
#include "casillero_transitable.h"

/*void CasilleroTransitable::recolectar_material(){
    //En esta linea le sumo la cantidad material a nuestro array de recursos disponibles
    this->cantidad_material=0;

}*/

void CasilleroTransitable::poner_material(std::string material){
    this->material = material;

}

bool CasilleroTransitable::tiene_material_o_edificio(){
    return (this->material != "0");
}

std::string CasilleroTransitable::devolver_material_o_edificio(){
    return this->material;
}

/*char CasilleroTransitable::devolver_tipo(){
    return this->tipo;
}*/

CasilleroTransitable::CasilleroTransitable(){
    this->material = "0";
    this->tipo = 'C';
}

void CasilleroTransitable::construir(Edificio edificio){

}

void CasilleroTransitable::recolectar_material(ListaMateriales Materiales){
    
}

void CasilleroTransitable::demoler(ListaMateriales Materiales){
    
}

//Casillero::~Casillero(){
//}