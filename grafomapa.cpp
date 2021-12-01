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