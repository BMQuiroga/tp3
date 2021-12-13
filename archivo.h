#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include "mapa.h"

class Archivo {
public:
    //pre:
    //pos:
    Archivo();

    //pre: -
    //pos: devuelve un mapa cargado con los casilleros
    Mapa* procesar_archivo_mapa();

    //pre: -
    //pos: carga los materiales de los jugadores
    void procesar_archivo_materiales(ListaMateriales* jugador1, ListaMateriales* jugador2);

private:
    //pre:
    //pos: abre el archivo en modo lectura
    void leer_archivo(ifstream &archivo, std::string path);

    //pre: -
    //pos: cierra el archivo
    void cerrar_archivo(ifstream &archivo);

    //pre: -
    //pos: devuelve el tipo de casillero
    Casillero* asignar_casillero(char letra);

};

#endif