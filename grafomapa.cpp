#include "grafomapa.h"

GrafoMapa::GrafoMapa(Jugador jugador) {
    this->jugador = jugador;

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