#include "grafomapa.h"
#include <iostream>
#include <fstream>
#include <string>


GrafoMapa::GrafoMapa(Jugador jugador) {
    this->jugador = jugador;
    procesar_archivo_mapa();
    generar_caminos();
    mostrar_matriz();
}

void GrafoMapa::generar_caminos() {
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

int GrafoMapa::devolver_costo(int origen, int destino) {
    return matriz_adyacencia[origen][destino];
}

ListaRecorrido* GrafoMapa::camino_minimo(int origen, int destino) {
    ListaRecorrido* recorrido = new ListaRecorrido;
    int casillero_actual = origen;

    recorrido->agregar(casillero_actual);

    while (casillero_actual != destino) {
        casillero_actual = matriz_vertices[casillero_actual][destino];
        recorrido->agregar(casillero_actual);
    }

    recorrido->mostrar();   //sacar
    cout << "Coste: " << devolver_costo(origen, destino) << endl; //poner en otro lado usando devolver_costo()

    mostrar_recorrido_en_mapa(recorrido);

    return recorrido;
}

int GrafoMapa::generar_peso(Casillero* casillero) {
    int peso = 0;
    if (casillero->devolver_tipo_camino() == 'C') {
        peso = 4;
    } else if (casillero->devolver_tipo_camino() == 'B') {
        peso = 0;
    } else if (casillero->devolver_tipo_camino() == 'M') {
        if (jugador.devolver_nombre() == 1) {
            peso = 5;
        } else {
            peso = 2;
        }
    } else if (casillero->devolver_tipo_camino() == 'L') {
        if (jugador.devolver_nombre() == 1) {
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

void GrafoMapa::agregar_camino(int posicion_inicial, int posicion_final, int peso) {
    this->matriz_adyacencia[posicion_inicial][posicion_final] = peso;
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


void GrafoMapa::inicializar_caminos() {
    int peso;

    for (int coord_x = 0; coord_x < filas; coord_x++) {
        for (int coord_y = 0; coord_y < columnas; coord_y++) {
            int posicion_inicial = matriz[coord_x][coord_y]->obtener_id();

            if (coord_y != 0) {
                int posicion_final = matriz[coord_x][coord_y - 1]->obtener_id();
                peso = generar_peso(matriz[coord_x][coord_y - 1]);
                agregar_camino(posicion_inicial, posicion_final, peso);
            }

            if (coord_y != this->columnas - 1) {
                int posicion_final = matriz[coord_x][coord_y + 1]->obtener_id();
                peso = generar_peso(matriz[coord_x][coord_y + 1]);
                agregar_camino(posicion_inicial, posicion_final, peso);
            }

            if (coord_x != 0) {
                int posicion_final = matriz[coord_x - 1][coord_y]->obtener_id();
                peso = generar_peso(matriz[coord_x - 1][coord_y]);
                agregar_camino(posicion_inicial, posicion_final, peso);
            }

            if (coord_x != this->filas - 1) {
                int posicion_final = matriz[coord_x + 1][coord_y]->obtener_id();
                peso = generar_peso(matriz[coord_x + 1][coord_y]);
                agregar_camino(posicion_inicial, posicion_final, peso);
            }
        }
    }
}