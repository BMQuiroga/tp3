#ifndef RAMAEDIFICIOS_H
#define RAMAEDIFICIOS_H

#include <iostream>
#include "listaedificios.h"


class RamaEdificios{

private:
    std::string clave;
    Edificio valor;
    RamaEdificios* nodo_izq;
    RamaEdificios* nodo_der;

public:

    RamaEdificios(Edificio edificio);

    Edificio buscar_edificio(std::string edificio);

    void asignar_nodo(/*RamaEdificios* rama,*/ Edificio edificio);

    int contador_de_elementos();

    bool es_valido(std::string nombre);
<<<<<<< HEAD

    bool tiene_rama_izq();

    bool tiene_rama_der();

    void destruir();
=======
>>>>>>> 7d8d9be111d3f26c3315c7f7681bd8ef5653e4e9

};


#endif