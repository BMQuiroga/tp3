#include <iostream>
#include "casillero_transitable.h"
//#include "casillero.h"

/*void CasilleroTransitable::recolectar_material(){
    //En esta linea le sumo la cantidad material a nuestro array de recursos disponibles
    this->cantidad_material=0;

}*/

void CasilleroTransitable::poner_material(Material* mat){
    this->material = mat;
}

bool CasilleroTransitable::tiene_material_o_edificio(){
    return (this->material->devolver_nombre() != "0");
}

std::string CasilleroTransitable::devolver_material_o_edificio(){
    return this->material->devolver_nombre();
}

/*char CasilleroTransitable::devolver_tipo(){
    return this->tipo;
}*/

CasilleroTransitable::CasilleroTransitable(std::string camino){
    // Material* material; //revisar
    // this->material = material;
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
    delete material;
}

void CasilleroTransitable::construir(Edificio* edificio){

}

void CasilleroTransitable::recolectar_material(Jugador* jugador){
    std::string nombre = this->material->devolver_nombre();
    int cantidad = this->material->devolver_cantidad();
    material->borrar();
    jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice(nombre))->sumar_cantidad(cantidad);
    if(nombre=="andycoins")
        jugador->actualizar_andycoins_juntadas(cantidad);

}

void CasilleroTransitable::demoler(Jugador* jugador){
    
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

