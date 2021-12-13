#include <iostream>
#include "edificio.h"


/*bool Edificio::se_puede_construir(int longitud_mapa_x, int longitud_mapa_y){//me tira error cuando llamo a la otra funcion desde aca, no se por que
    return (cantidad_construidos(longitud_mapa_x,longitud_mapa_y)>=maximos_permitidos);
}*/

/*int Edificio::cantidad_construidos(int longitud_mapa_x, int longitud_mapa_y, CasilleroConstruible mapa){
    int contador=0;
    for(int i=0;i<longitud_mapa_x;i++){
        for(int j=0;j<longitud_mapa_y;i++)
            if (mapa[i][j].mostrar_contenido==this->nombre)
                contador++;//mi idea es que mapa sea una matriz de casilleros



    }

    return contador;
}*/

//Toda la funcion va a tener que ir en el main

Edificio::Edificio(std::string nombre, int piedra, int madera, int metal, int max){
    this->nombre = nombre;
    this->cantidad_piedra = piedra;
    this->cantidad_madera = madera;
    this->cantidad_metal = metal;
    this->maximos_permitidos = max;
    /*
    if(nombre=="mina" ||  nombre=="fabrica")
        this->vida=2;
    else
        this->vida=1;*/
}

Edificio::~Edificio() {
    this->nombre = "";
}

std::string Edificio::devolver_nombre(){
    
    return this->nombre;
    
}

Edificio Edificio::operator=(Edificio construccion){
    /*this->nombre=construccion.nombre;
    this->cantidad_piedra=construccion.cantidad_piedra;
    this->cantidad_madera=construccion.cantidad_madera;
    this->cantidad_metal=construccion.cantidad_metal;
    this->maximos_permitidos=construccion.maximos_permitidos;*/
    return Edificio(construccion.nombre, construccion.cantidad_piedra, construccion.cantidad_madera, construccion.cantidad_metal,construccion.maximos_permitidos);
}

Edificio::Edificio() {
    this->nombre = "0";
    this->cantidad_piedra = 0;
    this->cantidad_madera = 0;
    this->cantidad_metal = 0;
    this->maximos_permitidos = 0;
}

void Edificio::cambiar_todo(std::string nombre, int piedra, int madera, int metal, int max){
    this->nombre = nombre;
    this->cantidad_piedra = piedra;
    this->cantidad_madera = madera;
    this->cantidad_metal = metal;
    this->maximos_permitidos = max;

    /*
    if(nombre=="mina" ||  nombre=="fabrica")
        this->vida=2;
    else
        this->vida=1;*/

}

int Edificio::devolver_piedra(){
    return this->cantidad_piedra;
}
int Edificio::devolver_madera(){
    return this->cantidad_madera;
}
int Edificio::devolver_metal(){
    return this->cantidad_metal;
}
int Edificio::devolver_maximos_permitidos(){
    return this->maximos_permitidos;
}

void Edificio::imprimir_brinda_materiales(){
    if(this->nombre == "mina")
        std::cout <<"Brinda 15 de piedra" <<std::endl;
    if(this->nombre == "aserradero")
        std::cout <<"Brinda 25 de madera" <<std::endl;
    if(this->nombre == "fabrica")
        std::cout <<"Brinda 40 de metal" <<std::endl;
    if(this->nombre == "escuela")
        std::cout <<"Brinda 25 andycoins" <<std::endl;
    if(this->nombre == "planta electrica")
        std::cout <<"Brinda 15 de energia" <<std::endl;
    if(this->nombre == "mina oro")
        std::cout <<"Brinda 50 andycoins" <<std::endl;    
}

void Edificio::modificar_datos() {
    int piedra=1, madera=1, metal=1, max=1;
    std::cout << "Ingrese los datos nuevos para el edificio: " << std::endl;
    std::cout << "Piedra necesaria para construir: Actual: " << this->devolver_piedra() << ", Nueva: "; std::cin >> piedra;
    while (piedra < 0 || piedra > 50000) {
        std::cout << "El valor debe estar entre 0 y 50000: ";  std::cin >> piedra; 
    }
    std::cout << "Madera necesaria para construir: Actual: " << this->devolver_madera() << ", Nueva: "; std::cin >> madera;
    while (madera < 0 || madera > 50000) {
        std::cout << "El valor debe estar entre 0 y 50000: ";  std::cin >> madera; 
    }
    std::cout << "Metal necesario para construir: Actual: " << this->devolver_metal() << ", Nuevo: "; std::cin >> metal;
    while (metal < 0 || metal > 50000) {
        std::cout << "El valor debe estar entre 0 y 50000: ";  std::cin >> metal; 
    }
    std::cout << "Maximos permitidos: Actuales: " << this->devolver_maximos_permitidos() << ", Nueva: "; std::cin >> max; 
    while (max < 0 || max > 50000) {
        std::cout << "El valor debe estar entre 0 y 50000: ";  std::cin >> max; 
    } 


    this->cambiar_todo(
        this->devolver_nombre(), 
        piedra, madera, metal, max
    );
}

/*
int Edificio::devolver_vida(){
    return this->vida;
}*/

/*
bool Edificio::restar_vida(int numero){
    this->vida-=numero;
    if(vida==0){
        std::cout<<"El "<<nombre<<" ha sido destruido"<<std::endl;
        cambiar_todo("0",0,0,0,0);
        return true;
    }
    else{
        std::cout<<"La "<<nombre<<" ha sido dañada"<<std::endl;
        return false;
    }

}*/