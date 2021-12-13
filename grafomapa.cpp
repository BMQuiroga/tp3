#include "grafomapa.h"
#include "mapa.h"
#include <iostream>
#include <fstream>
#include <string>


GrafoMapa::GrafoMapa(Jugador* jugador, Mapa* mapa) {
    this->jugador = jugador;
    this->mapa = mapa;
    this->filas = mapa->devolver_cantidad_filas();
    this->columnas = mapa->devolver_cantidad_columnas();
    this->esta_inicializado = false;
}

GrafoMapa::~GrafoMapa(){
    if (esta_inicializado) 
        liberar_memoria();
}   


void GrafoMapa::generar_caminos() {
    this->esta_inicializado = true;
    inicializar_matriz_adyacencia();
    inicializar_caminos();
    inicializar_vertices();
    floyd();
}


void GrafoMapa::inicializar_vertices() {
    this->matriz_vertices = new int * [filas * columnas];

    for (int i = 0; i < filas * columnas; i++) {
        matriz_vertices[i] = new int [filas * columnas];
    }

    for (int i = 0; i < filas * columnas; i++) {
        for (int j = 0; j < filas * columnas; j++) {
            matriz_vertices[i][j] = j;
        }
    }
}


void GrafoMapa::inicializar_matriz_adyacencia() {
    int largo_matriz = filas * columnas;

    this->matriz_adyacencia = new int *[largo_matriz];

    for (int i = 0; i < largo_matriz; i++) {
        matriz_adyacencia[i] = new int [largo_matriz];
    }

    for (int i = 0; i < largo_matriz; i++) {
        for (int j = 0; j < largo_matriz; j++) {
            if (i == j) {
                matriz_adyacencia[i][j] = 0;
            } else {
                matriz_adyacencia[i][j] = INFINITO;
            }
        }
    }
}


bool GrafoMapa::es_recorrido_valido(int origen_x, int origen_y, int destino_x, int destino_y, int costo){
    bool es_valida = true;
    if (origen_x == destino_x && origen_y == destino_y)     es_valida = false;
    if (costo == INFINITO)                                  es_valida = false;
    return es_valida;
}


void GrafoMapa::inicializar_caminos() {
    for (int coord_x = 0; coord_x < filas; coord_x++) {
        for (int coord_y = 0; coord_y < columnas; coord_y++) {
            if (coord_y != 0)                   agregar_camino(coord_x, coord_y, coord_x, coord_y - 1);
            if (coord_y != this->columnas - 1)  agregar_camino(coord_x, coord_y, coord_x, coord_y + 1);
            if (coord_x != 0)                   agregar_camino(coord_x, coord_y, coord_x - 1, coord_y);
            if (coord_x != this->filas - 1)     agregar_camino(coord_x, coord_y, coord_x + 1, coord_y);
        }
    }
}


void GrafoMapa::agregar_camino(int origen_x, int origen_y, int destino_x, int destino_y) {
    Casillero* casillero_origen = this->mapa->devolver_casillero(origen_x, origen_y);
    Casillero* casillero_destino = this->mapa->devolver_casillero(destino_x, destino_y);

    int posicion_origen = casillero_origen->obtener_id();
    int posicion_final = casillero_destino->obtener_id();

    if(casillero_destino->devolver_tipo() == 'T' && casillero_destino->tiene_material_o_edificio()) {
        agregar_camino(posicion_origen, posicion_final, INFINITO);
    } else {
        int peso = generar_peso(casillero_destino);
        agregar_camino(posicion_origen, posicion_final, peso);
    }
}


void GrafoMapa::agregar_camino(int posicion_inicial, int posicion_final, int peso) {
    this->matriz_adyacencia[posicion_inicial][posicion_final] = peso;
}


int GrafoMapa::calcular_costo(int origen, int destino) {
    return matriz_adyacencia[origen][destino];
}


int GrafoMapa::devolver_costo(int origen_x, int origen_y, int destino_x, int destino_y) {
    generar_caminos();

    int casillero_origen =  mapa->devolver_casillero(origen_x, origen_y)->obtener_id();
    int casillero_destino = mapa->devolver_casillero(destino_x, destino_y)->obtener_id();

    return this->calcular_costo(casillero_origen, casillero_destino);
}


ListaRecorrido* GrafoMapa::mover_jugador(int origen_x, int origen_y, int destino_x, int destino_y) {
    int casillero_origen =  mapa->devolver_casillero(origen_x, origen_y)->obtener_id();
    int casillero_destino = mapa->devolver_casillero(destino_x, destino_y)->obtener_id();

    return this->camino_minimo(casillero_origen, casillero_destino);
}


ListaRecorrido* GrafoMapa::camino_minimo(int origen, int destino) {
    ListaRecorrido* recorrido = new ListaRecorrido;
    int casillero_actual = origen;

    recorrido->agregar(casillero_actual);

    while (casillero_actual != destino) {
        casillero_actual = matriz_vertices[casillero_actual][destino];
        recorrido->agregar(casillero_actual);
    }

    return recorrido;
}


int GrafoMapa::generar_peso(Casillero* casillero) {
    int peso = 0;
    if (casillero->devolver_tipo_camino() == 'C') {
        peso = 4;
    } else if (casillero->devolver_tipo_camino() == 'B') {
        peso = 0;
    } else if (casillero->devolver_tipo_camino() == 'M') {
        if (jugador->devolver_nombre() == 1) {
            peso = 5;
        } else {
            peso = 2;
        }
    } else if (casillero->devolver_tipo_camino() == 'L') {
        if (jugador->devolver_nombre() == 1) {
            peso = 2;
        } else {
            peso = 5;
        }
    } else if (casillero->devolver_tipo_camino() == 'T') {
        peso = 25;
    }
    return peso;
}


void GrafoMapa::floyd() {
    int cantidad_vertices = filas * columnas;

    for (int vertice = 0; vertice < cantidad_vertices; vertice++) {
        for (int origen = 0; origen < cantidad_vertices; origen++){
            for (int destino = 0; destino < cantidad_vertices; destino++) {

                int costo = matriz_adyacencia[origen][vertice] + matriz_adyacencia[vertice][destino];

                if (matriz_adyacencia[origen][destino] > costo) {
                    matriz_adyacencia[origen][destino] = costo;
                    matriz_vertices[origen][destino] = matriz_vertices[origen][vertice];
                } 
                else if (matriz_adyacencia[origen][destino] == INFINITO){
                    matriz_vertices[origen][destino] = -1;
                }
            }
        }
    }
}



void GrafoMapa::liberar_memoria() {
    int largo_matriz = filas * columnas;

    for (int i = 0; i < largo_matriz; i++) {
        delete [] matriz_vertices [i];
        delete [] matriz_adyacencia[i];
        matriz_vertices [i] = NULL;
        matriz_adyacencia [i] = NULL;
    }
    delete [] matriz_vertices;
    delete [] matriz_adyacencia;
    matriz_vertices = NULL;
    matriz_adyacencia = NULL;
}