#include <iostream>
#include "casillero_transitable.h"

void CasilleroTransitable::poner_material(Material* mat){
    delete material;
    this->material = mat;
}

bool CasilleroTransitable::tiene_material_o_edificio(){
    return (this->material->devolver_nombre() != "0");
}

std::string CasilleroTransitable::devolver_material_o_edificio(){
    return this->material->devolver_nombre();
}

CasilleroTransitable::CasilleroTransitable(std::string camino){
    this->material = new Material; 
    this->tipo = 'C';
    this->tipo_de_camino=camino;

    if (camino == "Camino") {
        this->letra = 'C';
    } else if (camino == "Betun") {
        this->letra = 'B';
    } else if (camino == "Muelle") {
        this->letra = 'M';
    }
}

CasilleroTransitable::~CasilleroTransitable() {
    liberar_memoria();
}

void CasilleroTransitable::construir(Edificio* edificio){}

void CasilleroTransitable::recolectar_material(Jugador* jugador){
    std::string nombre = this->material->devolver_nombre();
    int cantidad = this->material->devolver_cantidad();
    this->material->borrar();
    int indice = jugador->devolver_materiales()->buscar_indice(nombre);
    if (indice!= -1 )
        jugador->devolver_materiales()->consulta(indice)->sumar_cantidad(cantidad);
    if(nombre=="andycoins")
        jugador->actualizar_andycoins_juntadas(cantidad);    
}

void CasilleroTransitable::demoler(Jugador* jugador){}


void CasilleroTransitable::cambiar_jugador(int numero){}

int CasilleroTransitable::devolver_jugador(){
    return 0;
}

bool CasilleroTransitable::atacar(){
    return false;
}

void CasilleroTransitable::reparar(Jugador* jugador){
    
}

void CasilleroTransitable::mostrar(){
    if (tiene_material_o_edificio()){
        std::cout<<"Soy un casillero transitable y no me encuentro vacio"<<std::endl;
        std::cout<<"Soy un(a) "<< devolver_material_o_edificio() <<" y me encuentro en el casillero consultado"<<std::endl;
    }
    else if (!tiene_material_o_edificio())
        std::cout<<"Soy un casillero transitable y me encuentro vacio"<<std::endl;
}

void CasilleroTransitable::liberar_memoria() {
    delete material;
    material = NULL;
}