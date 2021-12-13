
#ifndef TP3_2021_2C_OBJETIVO_H
#define TP3_2021_2C_OBJETIVO_H
#include "arboledificios.h"
#include "listamateriales.h"
#include <iostream>


const int OBJ_COMPRAR_ANDYPOLIS = 1;
const int OBJ_EDAD_PIEDRA = 2;
const int OBJ_BOMBARDERO = 3;
const int OBJ_ENERGICO = 4;
const int OBJ_LETRADO = 5;
const int OBJ_MINERO = 6;
const int OBJ_CANSADO = 7;
const int OBJ_CONSTRUCTOR = 8;
const int OBJ_ARMADO = 9;
const int OBJ_EXTREMISTA = 10;
const int OBJ_OBELISCO = 11;
const int TOPE_OBJETIVOS = 10;

using namespace std;

class Jugador;
class Mapa;

class Objetivo{

protected:
    std::string nombre;
public:
    //PRE: -
    //POST: -
    Objetivo();

    //PRE: -
    //POST: -
    virtual ~Objetivo();

    //PRE: -
    //POST: devuelve el nombre del objetivo
    std::string devolver_nombre();

    //PRE: -
    //POST: muestra el objetivo y progreso
    virtual void mostrar() = 0;

    //PRE: -
    //POST: chequea que el objetivo se haya completado
    virtual bool checkear() = 0;

    //PRE: -
    //POST: calcula el progreso del objetivo
    virtual int calcular_progreso() = 0;

    //PRE: -
    //POST: actualiza el progreso del objetivo
    virtual void actualizar(int valor) = 0;

};

#endif