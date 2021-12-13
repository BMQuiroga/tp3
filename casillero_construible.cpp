#include <iostream>
#include "casillero_construible.h"
#include "arboledificios.h"
//#include "casillero.h"

void CasilleroConstruible::construir(Edificio* edificio_nuevo){
    //this->edificio=edificio;
    //std::cout << edificio_nuevo->devolver_nombre() << "Edificio" << std::endl;

    if (jugador == 0 && this->edificio->devolver_nombre() == "0") {
        delete edificio;
    }

    this->edificio = edificio_nuevo;
    /*this -> edificio->cambiar_todo(
                edificio_nuevo->devolver_nombre(),
                edificio_nuevo->devolver_piedra(),
                edificio_nuevo->devolver_madera(),
                edificio_nuevo->devolver_metal(),
                edificio_nuevo->devolver_maximos_permitidos()
            );*/
    std::string nombre = this->edificio->devolver_nombre();
    if(nombre=="mina" ||  nombre=="fabrica")
        this->vida=2;
    else
        this->vida=1;
}

CasilleroConstruible::CasilleroConstruible(){
    //Edificio edificio_vacio;
    this->edificio = new Edificio;//&edificio_vacio;
    this->tipo = 'T';
    this->jugador=0;
    this->letra = 'T';
}

CasilleroConstruible::~CasilleroConstruible() {
    liberar_memoria();
}


std::string CasilleroConstruible::devolver_material_o_edificio(){
    return this->edificio->devolver_nombre();
}

void CasilleroConstruible::demoler(Jugador* jugador){
    jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("piedra"))->sumar_cantidad(this->edificio->devolver_piedra()/2);
    jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("madera"))->sumar_cantidad(this->edificio->devolver_madera()/2);
    jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("metal"))->sumar_cantidad(this->edificio->devolver_metal()/2);

    Edificio* nuevo_edificio = new Edificio;
    this->edificio = nuevo_edificio;
}

void CasilleroConstruible::recolectar_material(Jugador* jugador){
    int indice;
    if (this->edificio->devolver_nombre() == "mina"){
        indice = jugador->devolver_materiales()->buscar_indice("piedra");
        jugador->devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(15);
        std::cout << "Recolectados 15 de piedra" << std::endl;
    }
    if (this->edificio->devolver_nombre() == "aserradero"){
        indice = jugador->devolver_materiales()->buscar_indice("madera");
        jugador->devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(25);
        std::cout << "Recolectados 25 de madera" << std::endl;
    }
    if (this->edificio->devolver_nombre() == "fabrica"){
        indice = jugador->devolver_materiales()->buscar_indice("metal");
        jugador->devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(40);
        std::cout << "Recolectados 40 de metal" << std::endl;
    }
    if (this->edificio->devolver_nombre() == "escuela"){
        indice = jugador->devolver_materiales()->buscar_indice("andycoins");
        jugador->devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(25);
        jugador->actualizar_andycoins_juntadas(25);
        std::cout << "Recolectados 25 andycoins" << std::endl;
    }
    if (this->edificio->devolver_nombre() == "planta electrica"){
        jugador->sumar_energia(15);
        std::cout << "Recolectados 15 de energia" << std::endl;
    }
    if (this->edificio->devolver_nombre() == "mina oro"){
        indice = jugador->devolver_materiales()->buscar_indice("andycoins");
        jugador->devolver_materiales()->obtener_nodo(indice)->sumar_cantidad(50);
        jugador->actualizar_andycoins_juntadas(50);
        std::cout << "Recolectados 50 andycoins" << std::endl;
    }
}

/*char CasilleroConstruible::devolver_tipo(){
    return this->tipo;
}*/

bool CasilleroConstruible::tiene_material_o_edificio(){
    return (this->edificio->devolver_maximos_permitidos() != 0);
}

void CasilleroConstruible::poner_material(Material* material){
    
}

//Casillero::~Casillero(){
//}

void CasilleroConstruible::cambiar_jugador(int numero){
    this->jugador = numero;
}

int CasilleroConstruible::devolver_jugador(){
    return this->jugador;
}

bool CasilleroConstruible::atacar(){
    this->vida-=1;
    if(vida==0){
        std::cout<<"El "<< this->edificio->devolver_nombre() <<" ha sido destruido"<<std::endl;
        this->edificio = new Edificio;
        return true;
    }
    else{
        std::cout<<"La "<< this->edificio->devolver_nombre() <<" ha sido dañada"<<std::endl;
        return false;
    }
}

void CasilleroConstruible::reparar(Jugador* jugador){
    bool hay_piedra;
    bool hay_madera;
    bool hay_metal;
    int piedra = (this->edificio->devolver_piedra())/4;
    int madera = (this->edificio->devolver_madera())/4;
    int metal = (this->edificio->devolver_metal())/4;
    if(this->vida == 1){
        if(jugador->devolver_energia() >= 25){
            hay_piedra = (piedra <= jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("piedra"))->devolver_cantidad());
            hay_madera = (madera <= jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("madera"))->devolver_cantidad());
            hay_metal = (metal <= jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("metal"))->devolver_cantidad());
            if(hay_piedra && hay_madera && hay_metal){
                this->vida=2;            //creo q esta mal
                jugador->devolver_materiales()->obtener_nodo(jugador->devolver_materiales()->buscar_indice("piedra"))->restar_cantidad(piedra);
                jugador->devolver_materiales()->obtener_nodo(jugador->devolver_materiales()->buscar_indice("madera"))->restar_cantidad(madera);
                jugador->devolver_materiales()->obtener_nodo(jugador->devolver_materiales()->buscar_indice("metal"))->restar_cantidad(metal);
                jugador->restar_energia(25);
                std::cout << "La " << this->edificio->devolver_nombre() << " ha sido reparada satisfactoriamente" << std::endl;
            }
            else
                std::cout <<"No alcanzan los materiales para reparar el edificio!"<<std::endl;
        }
        else
            std::cout <<"No tienes energia suficiente!"<<std::endl;
    }
    else
        std::cout <<"Ese edificio no está dañado!"<<std::endl;
}
/*
Casillero::~Casillero(){

}*/

void CasilleroConstruible::mostrar(){
    if (tiene_material_o_edificio()){
        std::cout <<"Soy un casillero construible y no me encuentro vacio" <<std::endl;
        std::cout <<"Soy un(a) "<<devolver_material_o_edificio()<<" y me encuentro en el casillero consultado" <<std::endl;
        std::cout <<"Soy un edificio del jugador "<<devolver_jugador() <<std::endl;
    }
    else if (!tiene_material_o_edificio())
        std::cout <<"Soy un casillero construible y me encuentro vacio" <<std::endl;
}

void CasilleroConstruible::liberar_memoria() {
    if (jugador == 0) {
        delete edificio;
        edificio = NULL;
    }
}