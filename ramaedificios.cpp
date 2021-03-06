#include <iostream>
#include "ramaedificios.h"
#include "arboledificios.h"

RamaEdificios::RamaEdificios(Edificio*edificio){
    this -> valor = edificio;
    this -> clave = edificio->devolver_nombre();
    this->nodo_der = NULL;
    this->nodo_izq = NULL;
}

RamaEdificios::~RamaEdificios() {
    delete valor;
    valor = NULL;
}

void RamaEdificios::asignar_nodo(Edificio* edificio){
    if(edificio->devolver_nombre() > this->clave){
        if(!nodo_der){
            RamaEdificios *nuevo = new RamaEdificios(edificio);
            this -> nodo_der = nuevo;
        }
        else
            this -> nodo_der -> asignar_nodo(edificio);
    }
    else{
        if(!nodo_izq){
            RamaEdificios *nuevo = new RamaEdificios(edificio);
            this -> nodo_izq = nuevo;
        }
        else
            this -> nodo_izq -> asignar_nodo(edificio);
    }

}

Edificio* RamaEdificios::buscar_edificio(std::string edificio){
    if(edificio > this->clave){
        return(this->nodo_der->buscar_edificio(edificio));
    }
    else if(edificio < this->clave){
        return(this->nodo_izq->buscar_edificio(edificio));
    }
    else{
        if(edificio == this->clave)
            return valor;
        else{
            Edificio* aux = new Edificio("0",0,0,0,0);
            return aux;
        }
    }     
}

int RamaEdificios::contador_de_elementos(){
    if(!nodo_der && !nodo_izq)
        return 1;
    else if(!nodo_der)
        return 1 + nodo_izq->contador_de_elementos();
    else if(!nodo_izq)
        return 1 + nodo_der->contador_de_elementos();
    else
        return 1 + nodo_der->contador_de_elementos() + nodo_izq->contador_de_elementos();
}

bool RamaEdificios::es_valido(std::string nombre){
    if(nombre > this->clave){
        if(nodo_der)
            return(this->nodo_der->es_valido(nombre));
        else
            return false;
    }
    else if(nombre < this->clave){
        if(nodo_izq)
            return(this->nodo_izq->es_valido(nombre));
        else
            return false;
    }
    else{
        if(this->clave == nombre)
            return true;
        else
            return false;
    }
}


bool RamaEdificios::tiene_rama_der(){
    return(nodo_der);
}

bool RamaEdificios::tiene_rama_izq(){
    return(nodo_izq);
}

void RamaEdificios::destruir(){
    if(nodo_der){
        this->nodo_der->destruir();
        delete nodo_der;
    }
    if(nodo_izq){
        this->nodo_izq->destruir();
        delete nodo_izq;
    }
}

int RamaEdificios::devolver_todo(Edificio** array, int contador){
    array[contador] = this->valor;
    contador++;
    if(nodo_der)
        contador = this->nodo_der->devolver_todo(array,contador);
    if(nodo_izq)
        contador = this->nodo_izq->devolver_todo(array,contador);
    return contador;
    
}


void RamaEdificios::cambiar_edificio(Edificio* edificio){
    if(edificio->devolver_nombre() == this->clave){
        this->valor = edificio;
        this->clave = edificio->devolver_nombre();
    }
    else if(edificio->devolver_nombre() > this->clave){
        this->nodo_der->cambiar_edificio(edificio);
    }
    else if(edificio->devolver_nombre() < this->clave){
        this->nodo_izq->cambiar_edificio(edificio);
    }
}

void RamaEdificios::guardar(std::ofstream & archivo){
    archivo<<this->valor->devolver_nombre();
    archivo<<" ";
    archivo<<this->valor->devolver_piedra();
    archivo<<" ";
    archivo<<this->valor->devolver_madera();
    archivo<<" ";
    archivo<<this->valor->devolver_metal();
    archivo<<" ";
    archivo<<this->valor->devolver_maximos_permitidos();
    archivo<<std::endl;
}

void RamaEdificios::modificar(std::ofstream & archivo){
    guardar(archivo);
    if(nodo_der){
        this->nodo_der->modificar(archivo);
    }
    if(nodo_izq){
        this->nodo_izq->modificar(archivo);
    }
}

void RamaEdificios::liberar_memoria() {

}




