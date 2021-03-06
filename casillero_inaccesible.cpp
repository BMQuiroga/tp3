#include <iostream>
#include "casillero_inaccesible.h"


CasilleroInaccesible::CasilleroInaccesible(){
    this->tipo = 'L';
    this->letra = 'L';
}

CasilleroInaccesible::~CasilleroInaccesible() {}

bool CasilleroInaccesible::tiene_material_o_edificio(){
    return false;
}

std::string CasilleroInaccesible::devolver_material_o_edificio(){
    return "0";
}

void CasilleroInaccesible::poner_material(Material* material){}

void CasilleroInaccesible::construir(Edificio* edificio){
    std::cout <<"No se puede construir en un lago"<<std::endl;
}

void CasilleroInaccesible::recolectar_material(Jugador* jugador){}

void CasilleroInaccesible::demoler(Jugador* jugador){}

void CasilleroInaccesible::cambiar_jugador(int numero){}

int CasilleroInaccesible::devolver_jugador(){
    return 0;
}

bool CasilleroInaccesible::atacar(){
    return false;
}

void CasilleroInaccesible::reparar(Jugador* jugador){}

void CasilleroInaccesible::mostrar(){
    std::cout<<"Soy un casillero intransitable y me encuentro vacio"<<std::endl;
}


void CasilleroInaccesible::liberar_memoria() {}