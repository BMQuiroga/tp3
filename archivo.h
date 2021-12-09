#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include "mapa.h"

class Archivo {
public:
    Archivo() {};
    Mapa* procesar_archivo_mapa();
    void procesar_archivo_materiales(ListaMateriales& jugador1, ListaMateriales& jugador2);

private:
    void leer_archivo(ifstream &archivo, std::string path);
    void cerrar_archivo(ifstream &archivo);
    Casillero* asignar_casillero(char letra);

};

#endif