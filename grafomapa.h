#ifndef GRAFOMAPA_H
#define GRAFOMAPA_H
#include "casillero_construible.h"
#include "casillero_inaccesible.h"
#include "casillero_transitable.h"
#include "listarecorrido.h"

using namespace std;

const int INFINITO = 999999;

class Jugador;

class GrafoMapa {
private:
    int filas;
    int columnas;
    int** matriz_adyacencia;
    int** matriz_vertices;
    Mapa* mapa;
    Jugador* jugador;

public:

    //pre: jugador con nombre asignado
    //pos: crea un GrafoMapa asociado con el jugador
    GrafoMapa(Jugador* jugador, Mapa* mapa);

    //Pre: -
    //Post: Destruye matrices creadas 
    ~GrafoMapa();
    
    //Pre: coordenadas validas
    //Post: verifica si el recorrido es valido
    bool es_recorrido_valido(int origen_x, int origen_y, int destino_x, int destino_y, int costo);

    //pre: 1 <= x < filas; 1 <= y < columnas
    //pos: devuelve el costo del camino
    int devolver_costo(int origen_x, int origen_y, int destino_x, int destino_y);

    //pre: 1 <= x < filas; 1 <= y < columnas
    //pos: devuelve los casilleros recorridos
    ListaRecorrido* mover_jugador(int origen_x, int origen_y, int destino_x, int destino_y);

private:
    //pre: 1 <= posicicion < filas * columnas, origen != destino
    //pos: devuelve vector con los nodos visitados (falta parte de devolver int*)
    ListaRecorrido* camino_minimo(int origen, int destino);

    //pre: 1 <= x < filas; 1 <= y < columnas
    //pos: agrega el camino si es valido o no 
    void agregar_camino(int origen_x, int origen_y, int destino_x, int destino_y);

    //pre: 1 <= posicicion < filas * columnas
    //pos: agrega a matriz_adyacencia el peso de ir de origen a destino
    void agregar_camino(int posicion_inicial, int posicion_final, int peso);

    //pre: -
    //pos: inicializa las matrices y usa Floyd para completarlas
    void generar_caminos();

    //pre: 
    //pos: devuelve un peso segun que sea casillero
    int generar_peso(Casillero* casillero);

    //pre: 1 <= posicicion < filas * columnas
    //pos: devuelve el costo del recorrido  
    int calcular_costo(int origen, int destino);

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

    //pre: -
    //pos: libera la memoria
    void liberar_memoria();
};

#endif