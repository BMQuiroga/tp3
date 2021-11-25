<<<<<<< HEAD
#include <iostream>
#include "ramaedificios.h"

RamaEdificios::RamaEdificios(Edificio edificio){
    this->valor=edificio;
    this->clave=edificio.devolver_nombre();
}

=======
#include "ramaedificios.h"

>>>>>>> 72129b45f466af1afec34c75921276dbf129cb61
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
<<<<<<< HEAD

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
=======
>>>>>>> 72129b45f466af1afec34c75921276dbf129cb61
