#include <iostream>
#include "arboledificios.h"
#include <fstream>

ArbolEdificios::ArbolEdificios(){
    this->raiz = NULL;
}

ArbolEdificios::~ArbolEdificios() {
    destruir();
}

void ArbolEdificios::alta(std::string nombre, int piedra, int madera, int metal, int maximos){
    Edificio* edificio = new Edificio(nombre,piedra,madera,metal,maximos);
    this->raiz->asignar_nodo(edificio);
}

Edificio* ArbolEdificios::consulta(std::string edificio){
    return(this->raiz->buscar_edificio(edificio));

}

int ArbolEdificios::devolver_cantidad(){
    if(this->raiz){
        return this->raiz->contador_de_elementos();
    }
    else
        return 0;

}

void ArbolEdificios::procesar_archivo_edificios(){
    std::string numero,nombre;
    int piedra,madera,metal,max,contador=0;
    std::ifstream archivo_edificios("edificios.txt",std::ios::in);
    if(!archivo_edificios)
        std::cout<<"El archivo no se abrio correctamente"<<std::endl;
    else{
        while(archivo_edificios>>nombre){
            contador++;
            if (nombre=="planta"){
                archivo_edificios>>nombre;
                nombre="planta electrica";
            }
            archivo_edificios>>numero;
            if(numero=="oro"){
                archivo_edificios>>numero;
                nombre="mina oro";
            }
            piedra=stoi(numero);
            archivo_edificios>>numero;
            madera=stoi(numero);
            archivo_edificios>>numero;
            metal=stoi(numero);
            archivo_edificios>>numero;
            max=stoi(numero);

            if(contador!=1)
                alta(nombre,piedra,madera,metal,max);
            else{
                Edificio* edificio = new Edificio(nombre,piedra,madera,metal,max);
                this->raiz= new RamaEdificios(edificio);
            }
        }
    }
    archivo_edificios.close();
}

bool ArbolEdificios::es_edificio_valido(std::string nombre){
    return(this->raiz->es_valido(nombre));
}

void ArbolEdificios::destruir(){
    this->raiz->destruir();
    delete this->raiz;
    this->raiz = NULL;
}

Edificio** ArbolEdificios::devolver_todo(){
    Edificio** array = new Edificio *[devolver_cantidad()];//esto no pierde memoria?
    this->raiz->devolver_todo(array,0);
    return array;
}

void ArbolEdificios::cambiar_nodo(Edificio* edificio){
    this->raiz->cambiar_edificio(edificio);
}

void ArbolEdificios::reescribir(){
    std::ofstream archivo;
    archivo.open("edificios.txt");

    if(archivo.is_open()){
        this->raiz->modificar(archivo);
    }
}

