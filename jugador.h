#ifndef JUGADOR_H
#define JUGADOR_H
#include "listamateriales.h"
#include "arboledificios.h"
#include "objetivo.h"
//#include "listaObjetivos.h"
/*
#include "ComprarAndypolis.h"
#include "Armado.h"
#include "Bombardero.h"
#include "Cansado.h"
#include "Constructor.h"
#include "EdadDePiedra.h"
#include "Energetico.h"
#include "Extremista.h"
#include "Letrado.h"
#include "Minero.h"
#include "Obelisco.h"*/

class GrafoMapa;

class Jugador{

private:
    int nombre;
    ListaMateriales* materiales;
    GrafoMapa* grafo;
    int energia;
    int coordenada_x,coordenada_y;
    Objetivo* objetivo_1;
    Objetivo* objetivo_2;
    Objetivo* objetivo_3;
    Objetivo* objetivo_4;

public:
    Jugador() /*{}*/;
    Jugador(int x, int y, int numero, ListaEdificios* edificios, Mapa * mapa);
    ~Jugador();
    void mover_jugador(Mapa* mapa);
    void mover_gratis(int x, int y);
    void sumar_energia(int cantidad);
    void restar_energia(int cantidad);
    int devolver_energia();
    void mostrar_objetivos();
    void asignar_lista_materiales(ListaMateriales *materiales);
    void comprar_bombas();
    // ListaMateriales devolver_materiales();
    ListaMateriales* devolver_materiales();

    bool checkear_objetivos();
    int devolver_nombre();
    int devolver_coordenada_x();
    int devolver_coordenada_y();
    void asignar_objetivos(ListaEdificios* edificios, ListaMateriales* materiales, Mapa * mapa);

    //void asignar_objetivos_aleatorios(ListaObjetivos vector_objetivos);
    void actualizar_objetivo(int numero_objetivo, int valor);


    //bool ha_ganado();

    bool cumplio_objetivo_principal();

    //bool cumplio_objetivo_secundario();
    GrafoMapa* movimiento();

    void destruir();

    void actualizar_bombas_compradas(int cantidad);

    void actualizar_bombas_usadas();

    void actualizar_andycoins_juntadas(int cantidad);

private:
    void operacion_bombas(int valor);
    Objetivo* crear_objetivo(int numero_objetivo, ListaEdificios * edificios, Mapa * mapa);
    void crear_grafo(Mapa * mapa);
};






#endif