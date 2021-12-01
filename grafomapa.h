#ifndef GRAFOMAPA_H
#define GRAFOMAPA_H
#include "casillero_construible.h"
#include "casillero_inaccesible.h"
#include "casillero_transitable.h"
#include "listarecorrido.h"

using namespace std;

const int INFINITO=999999;

class GrafoMapa {
private:
    int filas;
    int columnas;
    int** matriz_adyacencia;
    int** matriz_vertices;
    Casillero*** matriz;
    Jugador jugador;

public:
    //pre: jugador con nombre asignado
    //pos: crea un GrafoMapa asociado con el jugador
    GrafoMapa(Jugador jugador);

    //la dejamos aca?
    void procesar_archivo_mapa();

    //pre: 1 <= posicicion < filas * columnas
    //pos: agrega a matriz_adyacencia el peso de ir de origen a destino
    void agregar_camino(int posicion_inicial, int posicion_final, int peso);

    //pre: -
    //pos: inicializa las matrices y usa Floyd para completarlas
    void generar_caminos();

    //pre: 
    //pos: devuelve un peso segun que sea casillero
    int generar_peso(Casillero* casillero);

    //de prueba por ahora
    void mostrar_matriz();

    //pre: 1 <= posicicion < filas * columnas, origen != destino
    //pos: devuelve vector con los nodos visitados (falta parte de devolver int*)
    ListaRecorrido* camino_minimo(int origen, int destino);

    void mostrar_recorrido_en_mapa(ListaRecorrido* recorrido);
    
    //pre: 1 <= posicicion < filas * columnas
    //pos: devuelve el costo del recorrido  
    int devolver_costo(int origen, int destino);

private:
    //pre: -
    //pos: inicializa matriz adyacencia con diagonal en 0
    void inicializar_matriz_adyacencia();

    //pre: -
    //pos: llena la primera iteracion de matriz adyacencia con nodos contiguos y el resto con infinito
    void inicializar_caminos();

    //pre: -
    //pos: primera iteracion de matriz vertices
    void inicializar_vertices();

    //pre: -
    //pos: completa las matrices adyacencia y vertices usando el algoritmo de floyd
    void floyd();
};

#endif