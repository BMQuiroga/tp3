#include "grafomapa.h"
#include "mapa.h"
#include <iostream>
#include <fstream>
#include <string>


// GrafoMapa::GrafoMapa(Jugador* jugador) {
//     this->jugador = jugador;
//     generar_caminos();
// }


GrafoMapa::GrafoMapa(Jugador* jugador, Mapa* mapa) {
    this->jugador = jugador;
    this->mapa = mapa;
    this->filas = mapa->devolver_cantidad_filas();
    this->columnas = mapa->devolver_cantidad_columnas();
    generar_caminos();
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
    Casillero* casillero;

    for (int coord_x = 0; coord_x < filas; coord_x++) {
        for (int coord_y = 0; coord_y < columnas; coord_y++) {

            int posicion_inicial = this->mapa->devolver_casillero(coord_x, coord_y)->obtener_id();

            if (coord_y != 0) {
                casillero = this->mapa->devolver_casillero(coord_x, coord_y - 1);
                int posicion_final = casillero->obtener_id();
                peso = generar_peso(casillero);
                agregar_camino(posicion_inicial, posicion_final, peso);
            }

            if (coord_y != this->columnas - 1) {
                casillero = this->mapa->devolver_casillero(coord_x, coord_y + 1);
                int posicion_final = casillero->obtener_id();
                peso = generar_peso(casillero);
                agregar_camino(posicion_inicial, posicion_final, peso);
            }

            if (coord_x != 0) {
                casillero = this->mapa->devolver_casillero(coord_x - 1, coord_y);
                int posicion_final = casillero->obtener_id();
                peso = generar_peso(casillero);
                agregar_camino(posicion_inicial, posicion_final, peso);
            }

            if (coord_x != this->filas - 1) {
                casillero = this->mapa->devolver_casillero(coord_x + 1, coord_y);
                int posicion_final = casillero->obtener_id();
                peso = generar_peso(casillero);
                agregar_camino(posicion_inicial, posicion_final, peso);
            }
        }
    }
}


void GrafoMapa::agregar_camino(int posicion_inicial, int posicion_final, int peso) {
    this->matriz_adyacencia[posicion_inicial][posicion_final] = peso;
}


int GrafoMapa::calcular_costo(int origen, int destino) {
    return matriz_adyacencia[origen][destino];
}


int GrafoMapa::devolver_costo(int origen_x, int origen_y, int destino_x, int destino_y) {
    int casillero_origen = mapa->devolver_casillero(origen_x, origen_y)->obtener_id();
    int casillero_destino = mapa->devolver_casillero(destino_x, destino_y)->obtener_id();

    return this->calcular_costo(casillero_origen, casillero_destino);
}


ListaRecorrido* GrafoMapa::mover_jugador(int origen_x, int origen_y, int destino_x, int destino_y) {
    int casillero_origen = mapa->devolver_casillero(origen_x, origen_y)->obtener_id();
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


void GrafoMapa::mostrar_recorrido_en_mapa(ListaRecorrido* recorrido) {
    cout << "Recorrido (provisorio)" << endl;
    for (int coord_x = 0; coord_x < filas; coord_x++) {
        for (int coord_y = 0; coord_y < columnas; coord_y++) {
            string s(1,mapa->devolver_casillero(coord_x,coord_y)->devolver_tipo_camino());

            if (recorrido->contiene(mapa->devolver_casillero(coord_x,coord_y)->obtener_id())) {
                std::cout << "\"*\"";
            } else {
                std::cout << "\"" << s << "\"";
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
    }
    cout << endl;
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




void GrafoMapa::mostrar_matriz() {

    //son de prueba, no hacen falta para la version final

    cout << "Mapa" << endl;
    for (int coord_x = 0; coord_x < filas; coord_x++) {
        for (int coord_y = 0; coord_y < columnas; coord_y++) {
            string s(1,mapa->devolver_casillero(coord_x,coord_y)->devolver_tipo_camino());
            std::cout << "\"" << s << "\"";
            std::cout << " | ";
        }
        std::cout << std::endl;
    }
    cout << endl;

    cout << "Vertices" << endl;
    for (int coord_x = 0; coord_x < filas; coord_x++) {
        for (int coord_y = 0; coord_y < columnas; coord_y++) {
            if (mapa->devolver_casillero(coord_x,coord_y)->obtener_id() < 10 ) {
                std::cout << "\"" << std::to_string(mapa->devolver_casillero(coord_x,coord_y)->obtener_id()) << " " << "\"";
                std::cout << " | ";
            } else {
                std::cout << "\"" << std::to_string(mapa->devolver_casillero(coord_x,coord_y)->obtener_id()) << "\"";
                std::cout << " | ";
            }

        }
        std::cout << std::endl;
    }

    cout << endl;

    // cout << "Matriz de distancias" << endl;
    // for (int coord_x = 0; coord_x < filas * columnas; coord_x++) {
    //     for (int coord_y = 0; coord_y < filas * columnas; coord_y++) {
    //         if (matriz_adyacencia[coord_x][coord_y] == INFINITO) {
    //             std::cout << "\"" << " " << "\"";
    //             std::cout << " | ";
    //         } else {
    //             std::cout << "\"" << std::to_string(matriz_adyacencia[coord_x][coord_y]) << "\"";
    //             std::cout << " | ";
    //         }
    //     }
    //     std::cout << std::endl;
    // }

    // cout << endl;

    // cout << "Matriz de vertices" << endl;
    // for (int i = 0; i < filas * columnas; i++) {
    //     for (int j = 0; j < filas * columnas; j++) {
    //         if (i == j) {
    //             std::cout << "\"" << "-" << "\"";
    //             std::cout << " | ";
    //         } else {
    //             std::cout << "\"" << matriz_vertices[i][j] << "\"";
    //             std::cout << " | ";

    //         }
    //     }
    //     cout << endl;
    // }
}

