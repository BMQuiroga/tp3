#ifndef OBJETIVO_H
#define OBJETIVO_H
#include "arboledificios.h"
#include "listamateriales.h"
#include <iostream>

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
    void mostrar();
    virtual void mostrar_objetivo();
    virtual bool checkear() = 0;
    virtual int calcular_progreso() = 0;
    virtual void actualizar(int valor)=0;
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

#endif