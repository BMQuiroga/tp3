#ifndef MENU_H
#define MENU_H
#include "mapa.h"
#include "listaedificios.h"
#include "listamateriales.h"
//#define CLR_SCREEN "clear"//PARA LINUX
#define CLR_SCREEN "CLS"//PARA WINDOWS#
#include "jugador.h"
#include "objetivo.h"
//#include "arboledificios.h"

const int MODIFICAR_EDIFICIO = 1;
const int LISTAR_TODOS_LOS_EDIFICIOS = 2;
const int MOSTRAR_MAPA = 3;
const int COMENZAR_PARTIDA = 4;
const int GUARDAR_Y_SALIR_MENU = 5;

const int CONSTRUIR_EDIFICIO = 1;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int DEMOLER_EDIFICIO = 3;
const int ATACAR_EDIFICIO = 4;
const int REPARAR_EDIFICIO = 5;
const int COMPRAR_BOMBAS = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS = 10;
const int MOVERSE = 11;
const int FINALIZAR_TURNO = 12;
const int GUARDAR_Y_SALIR_PARTIDA = 13;



//pre:-
//post: Imprime por pantalla el menu
void mostrar_menu();

//pre:-
//post: Realiza la opcion
void procesar_opcion_menu(int opcion_elegida, ListaMateriales materiales, ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u);

//pre:-
//post: Devuelve true si la opcion ingresada por el usuario esta en el rango valido, si no devuelve false.
bool es_opcion_valida(int elegida, int maxima);

//pre: -
//post: Devuelve un numero aleatorio entre los valores seleccionados (no incluye el max)
int generador_de_numeros_aleatorios(int min, int max);

//pre: -
//post: libera la memoria dinamica y guarda los datos en los respectivos archivos
void guardar(ListaMateriales materiales, ListaEdificios edificios, Mapa mapa);

//pre:-
//post: Realiza la opcion
void procesar_opcion_partida(int opcion_elegida, ListaMateriales materiales, ListaEdificios edificios, Mapa mapa, Jugador jugador, Jugador rival);


void modificar_datos_edificio(ListaEdificios edificios);


void mostrar_menu_partida();



void partida(ListaEdificios edificios, Mapa mapa, Jugador jugador1, Jugador jugador2);



int corregir_opcion(int opcion);


#endif 