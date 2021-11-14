#ifndef MENU_H
#define MENU_H
#include "mapa.h"
#include "listaedificios.h"
#include "listamateriales.h"
//#define CLR_SCREEN "clear"//PARA LINUX
#define CLR_SCREEN "CLS"//PARA WINDOWS


const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 10;


const int CONSTRUIR_EDIFICIO = 1;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int LISTAR_TODOS_LOS_EDIFICIOS= 3;
const int DEMOLER_EDIFICIO= 4;
const int MOSTRAR_MAPA =5;
const int CONSULTAR_COORDENADA= 6;
const int LISTAR_MATERIALES = 7;
const int RECOLECTAR_RECURSOS= 8;
const int LLUVIA_DE_RECURSOS= 9;
const int SALIR = 10;

//pre:-
//post: Imprime por pantalla el menu
void mostrar_menu();

//pre:-
//post: Realiza la opcion
void procesar_opcion(int opcion_elegida, ListaMateriales materiales, ListaEdificios edificios, Mapa mapa);

//pre:-
//post: Devuelve true si la opcion ingresada por el usuario esta en el rango valido, si no devuelve false.
bool es_opcion_valida(int elegida);

//pre: -
//post: Devuelve un numero aleatorio entre los valores seleccionados (no incluye el max)
int generador_de_numeros_aleatorios(int min, int max);

//pre: -
//post: libera la memoria dinamica y guarda los datos en los respectivos archivos
void guardar(ListaMateriales materiales, ListaEdificios edificios, Mapa mapa);
#endif 