#ifndef JUGADOR_H
#define JUGADOR_H
#include "listamateriales.h"
#include "arboledificios.h"
#include "objetivo.h"

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
    //pre: -
    //pos: constructor vacio de jugador
    Jugador();

    //pre: edificios y mapa ya cargados
    //pos: constructor de jugador
    Jugador(int x, int y, int numero, ListaEdificios* edificios, Mapa * mapa);

    //pre: -
    //pos: destructor de jugador
    ~Jugador();

    //pre: mapa valido
    //pos: mueve el jugador usando el camino minimo
    void mover_jugador(Mapa* mapa, Jugador* rival);

    //pre: 0 <= x < filas;  0 <= y < columnas 
    //pos: cambia las coordenadas del jugador
    void mover_gratis(int x, int y);

    //pre: - 
    //pos: suma energia al jugador
    void sumar_energia(int cantidad);

    //pre: - 
    //pos: resta energia al jugador
    void restar_energia(int cantidad);
    
    //pre: - 
    //pos: devuelve la energia del jugador
    int devolver_energia();
    
    //pre: - 
    //pos: muestra los objetivos del jugador
    void mostrar_objetivos();

    //pre: ListaMateriales ya cargada
    //pos: asigna la lista de materiales a jugador
    void asignar_lista_materiales(ListaMateriales *materiales);
    
    //pre: - 
    //pos: compra bombas para usar
    void comprar_bombas();

    //pre: - 
    //pos: devuelve un puntero a lista de materiales
    ListaMateriales* devolver_materiales();

    //pre: - 
    //pos: verifica que el jugador haya completado los objetivos
    bool checkear_objetivos();

    //pre: - 
    //pos: devuelve el nombre del jugador
    int devolver_nombre();

    //pre: - 
    //pos: devuelve la coordenada x del jugador
    int devolver_coordenada_x();
    
    //pre: - 
    //pos: devuelve la coordenada y del jugador
    int devolver_coordenada_y();

    //void asignar_objetivos_aleatorios(ListaObjetivos vector_objetivos);
    //void actualizar_objetivo(int numero_objetivo, int valor);

    //pre: -
    //pos: actualiza la cantidad de bombas para Extremista
    void actualizar_bombas_compradas(int cantidad);

    //pre: -
    //pos: actualiza la cantidad de bombas para Bombardero
    void actualizar_bombas_usadas();

    //pre: -
    //pos: actualiza la cantidad de monedas para Comprar Andypolis
    void actualizar_andycoins_juntadas(int cantidad);

    //pre: -
    //pos: actualiza el objetivo 1
    void asignar_objetivo_1(Objetivo * objetivo);

    //pre: -
    //pos: actualiza el objetivo 2
    void asignar_objetivo_2(Objetivo * objetivo);

    //pre: -
    //pos: actualiza el objetivo 3
    void asignar_objetivo_3(Objetivo * objetivo);

    //pre: -
    //pos: actualiza el objetivo 4
    void asignar_objetivo_4(Objetivo * objetivo);

private:

    //pre: mapa valido
    //pos: inicializa el Grafo
    void crear_grafo(Mapa * mapa);
};






#endif