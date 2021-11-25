#include "ramaedificios.h"

void RamaEdificios::asignar_nodo(Edificio edificio){
    if(edificio.devolver_nombre()>this->clave){
        if(!nodo_der){
            RamaEdificios nuevo(edificio);
            RamaEdificios *p=&nuevo;
            this->nodo_der=p;
        }
        else
            this->nodo_der->asignar_nodo(edificio);
    }
    else{
        if(!nodo_izq){
            RamaEdificios nuevo(edificio);
            RamaEdificios *p=&nuevo;
            this->nodo_izq=p;
        }
        else
            this->nodo_izq->asignar_nodo(edificio);
    }

}

Edificio RamaEdificios::buscar_edificio(std::string edificio){
    if(edificio>this->clave){
        this->nodo_der->buscar_edificio(edificio);
    }
    else if(edificio<this->clave){
        this->nodo_izq->buscar_edificio(edificio);
    }
    else
        return this->valor;
}
