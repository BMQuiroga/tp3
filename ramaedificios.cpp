#include <iostream>
#include "ramaedificios.h"

RamaEdificios::RamaEdificios(Edificio edificio){
    this->valor=edificio;
    /*Edificio *edificio2=new Edificio;
    edificio2->cambiar_todo(
        edificio.devolver_nombre(),
        edificio.devolver_piedra(),
        edificio.devolver_madera(),
        edificio.devolver_metal(),
        edificio.devolver_maximos_permitidos());
    this->valor=edificio2;*/
    this->clave=edificio.devolver_nombre();
}

void RamaEdificios::asignar_nodo(Edificio edificio){
    if(edificio.devolver_nombre()>this->clave){
        if(!nodo_der){
            RamaEdificios *nuevo = new RamaEdificios(edificio);
            //RamaEdificios *p=&nuevo;
            this->nodo_der=nuevo;
        }
        else
            this->nodo_der->asignar_nodo(edificio);
    }
    else{
        if(!nodo_izq){
            RamaEdificios *nuevo = new RamaEdificios(edificio);
            //RamaEdificios *p=&nuevo;
            this->nodo_izq=nuevo;
        }
        else
            this->nodo_izq->asignar_nodo(edificio);
    }

}

Edificio RamaEdificios::buscar_edificio(std::string edificio){
    if(edificio>this->clave){
        return(this->nodo_der->buscar_edificio(edificio));
    }
    else if(edificio<this->clave){
        return(this->nodo_izq->buscar_edificio(edificio));
    }
    else
        return valor;
}

int RamaEdificios::contador_de_elementos(){
    if(!nodo_der && !nodo_izq)
        return 1;
    else if(!nodo_der)
        return 1+nodo_izq->contador_de_elementos();
    else if(!nodo_izq)
        return 1+nodo_der->contador_de_elementos();
    else
        return 1+nodo_der->contador_de_elementos()+nodo_izq->contador_de_elementos();
}

bool RamaEdificios::es_valido(std::string nombre){
    if(nombre>this->clave){
        if(nodo_der)
            return(this->nodo_der->es_valido(nombre));
        else
            return false;
    }
    else if(nombre<this->clave){
        if(nodo_izq)
            return(this->nodo_izq->es_valido(nombre));
        else
            return false;
    }
    else{
        if(this->clave==nombre)
            return true;
        else
            return false;
    }
}