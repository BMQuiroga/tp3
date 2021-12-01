#include <iostream>
#include "arboledificios.h"
#include <fstream>

ArbolEdificios::ArbolEdificios(Edificio edificio){
    RamaEdificios *rama = new RamaEdificios(edificio);
    //RamaEdificios nuevo(edificio);
    //RamaEdificios *p=&nuevo;
    this->raiz=rama;
}

void ArbolEdificios::alta(std::string nombre, int piedra, int madera, int metal, int maximos){
    Edificio edificio(nombre,piedra,madera,metal,maximos);
    this->raiz->asignar_nodo(edificio);
}

Edificio ArbolEdificios::consulta(std::string edificio){
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
    int piedra,madera,metal,max;
    std::ifstream archivo_edificios("edificios.txt",std::ios::in);
    if(!archivo_edificios)
        std::cout<<"El archivo no se abrio correctamente"<<std::endl;
    else{
        while(archivo_edificios>>nombre){
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
            //std::cout<<nombre<<" "<<piedra<<" "<<madera<<" "<<metal<<" "<<max<<std::endl;
            //edificio.mostrar();
            alta(nombre,piedra,madera,metal,max);
            
            
        }
    }
    archivo_edificios.close();
}

bool ArbolEdificios::es_edificio_valido(std::string nombre){
    return(this->raiz->es_valido(nombre));
}

