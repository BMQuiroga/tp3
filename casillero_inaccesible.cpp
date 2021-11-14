#include <iostream>
#include "casillero_inaccesible.h"


CasilleroInaccesible::CasilleroInaccesible(){
    this->tipo = 'L';
}

bool CasilleroInaccesible::tiene_material_o_edificio(){
    return false;
}

std::string CasilleroInaccesible::devolver_material_o_edificio(){
    return "0";
}

void CasilleroInaccesible::poner_material(Material material){
    
}

void CasilleroInaccesible::construir(Edificio edificio){
    std::cout <<"No se puede construir en un lago"<<std::endl;
}

void CasilleroInaccesible::recolectar_material(ListaMateriales Materiales){
    
}

void CasilleroInaccesible::demoler(ListaMateriales Materiales){
    
}

Casillero::~Casillero(){
}

void CasilleroInaccesible::cambiar_jugador(int numero){
    //this->jugador=numero;
}

int CasilleroInaccesible::devolver_jugador(){
    //return this->jugador;
    return 0;
}