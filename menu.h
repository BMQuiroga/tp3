#ifndef MENU_H
#define MENU_H
#include <iostream>
// #include "mapa.h"
// #include "arboledificios.h"
#include "listamateriales.h"
// #include "listaObjetivos.h"
// //#define CLR_SCREEN "clear"//PARA LINUX
// #define CLR_SCREEN "CLS"//PARA WINDOWS#
// #include "jugador.h"
// #include "utilidad.h"
// // #include "objetivo.h"
// //#include "arboledificios.h"



// //pre:-
// //post: Imprime por pantalla el menu
// void mostrar_menu();

// //pre:-
// //post: Realiza la opcion
// void procesar_opcion_menu(int opcion_elegida, /*ListaMateriales materiales,*/ ListaEdificios* edificios, Mapa* mapa, Jugador* j, Jugador* u);

// //pre:-
// //post: Devuelve true si la opcion ingresada por el usuario esta en el rango valido, si no devuelve false.
// bool es_opcion_valida(int elegida, int maxima);

// //pre: -
// //post: Devuelve un numero aleatorio entre los valores seleccionados (no incluye el max)
// int generador_de_numeros_aleatorios(int min, int max);

// //pre: -
// //post: libera la memoria dinamica y guarda los datos en los respectivos archivos
// void guardar(ListaMateriales* materiales, ListaEdificios* edificios, Mapa* mapa);

// //pre:-
// //post: Realiza la opcion
// void procesar_opcion_partida(int opcion_elegida, ListaMateriales* materiales, ListaEdificios* edificios, Mapa* mapa, Jugador* jugador, Jugador* rival);


// void modificar_datos_edificio(ListaEdificios* edificios);


// void mostrar_menu_partida();


// void partida(ListaEdificios* edificios, Mapa* mapa, Jugador* jugador1, Jugador* jugador2);


// int corregir_opcion(int opcion);


// bool esta_terminado(Jugador* jugador);

void procesar_archivo_materiales(ListaMateriales* j1, ListaMateriales* j2);

int diccionario_materiales(std::string material);

// void borrar_archivo_ubicaciones();

// void resetear_archivo_materiales(Jugador* jugador);


#endif 