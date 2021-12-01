#include "grafomapa.h"
#include <iostream>
#include <fstream>
#include <string>


GrafoMapa::GrafoMapa(Jugador jugador) {
    this->jugador = jugador;

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