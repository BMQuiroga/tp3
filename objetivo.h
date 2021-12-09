
#ifndef TP3_2021_2C_OBJETIVO_H
#define TP3_2021_2C_OBJETIVO_H
//#ifndef OBJETIVO_H
//#define OBJETIVO_H
#include "arboledificios.h"
#include "listamateriales.h"
#include "jugador.h"
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
    std::string destripcion;
    int progreso;
    int objetivo;
public:
    std::string devolver_nombre();
    //virtual void mostrar() = 0;

    //comente para que compile, faltan declaraciones

    // virtual void mostrar_progreso() = 0;
    // virtual void mostrar_objetivo() = 0;
    // virtual bool checkear() = 0;
    // virtual int calcular_progreso() = 0;
    // virtual void actualizar(int valor)=0;

    void mostrar();
    bool checkear();
    int calcular_progreso();
    void actualizar(int valor);
    void actualizar(std::string nombre, int valor);

    virtual ~Objetivo() = default;
};

/*
class ComprarAndypolis : public Objetivo {
    public:
        ComprarAndypolis();
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};
*/
/*
class Edad_De_Piedra : public Objetivo {
    private:
        ListaMateriales materiales;
    public:
        Edad_De_Piedra(ListaMateriales materiales);
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};*/

/*
class Bombardero : public Objetivo {
    public:
        Bombardero();
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};*/

/*
class Energetico : public Objetivo {
    private:
        Jugador * jugador;
    public:
        Energetico(Jugador * jugador);
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};*/

/*
class Letrado : public Objetivo {
    private:
        ListaEdificios edificios; 
        Mapa * mapa;
        Jugador * jugador;
    public:
        Letrado(ListaEdificios edificios, Mapa * mapa, Jugador * jugador);
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};

class Minero : public Objetivo {
    private:
        ListaEdificios edificios; 
        Mapa * mapa;
        Jugador * jugador;
    public:
        Minero(ListaEdificios edificios, Mapa * mapa, Jugador * jugador);
        bool checkear();
        int calcular_progreso();
        void actualizar(int valor);
};

class Cansado : public Objetivo {
    private:
        Jugador * jugador;
    public:
        Cansado(Jugador * jugador);
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};

class Constructor : public Objetivo {
    private:
        ListaEdificios edificios;
        Mapa * mapa;
        Jugador * jugador;
    public:
        Constructor(ListaEdificios edificios, Mapa * mapa, Jugador * jugador);
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};

class Armado : public Objetivo {
    private:
        ListaMateriales materiales;
    public:
        Armado(ListaMateriales materiales);
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};

class Extremista : public Objetivo {
    public:
        Extremista();
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};
 */
/*
class Principal : public Objetivo {
    private:
        Mapa * mapa;
        Jugador * jugador;
    public:
        Principal(Mapa * mapa, Jugador * jugador);
        int calcular_progreso();
        bool checkear();
        void actualizar(int valor);
};
*/
#endif