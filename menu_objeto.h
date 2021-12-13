#ifndef MENU_OBJETO_H
#define MENU_OBJETO_H
#include "mapa.h"
#include "arboledificios.h"
#include "listamateriales.h"
#include "jugador.h"
#include "utilidad.h"

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

class Menu{
private:
    Utilidad utilidad;
    Jugador* jugador1;
    Jugador* jugador2;
    Mapa* mapa;
    ListaEdificios* edificios;

public:
    //Pre: mapa, edificio y jugadores ya cargados
    //Post: Menu principal del juego
    Menu(Mapa* mapa, ListaEdificios* edificios, Jugador* jugador1, Jugador* jugador2);

    //Pre: -
    //Post: muestra el primer menu del juego
    void mostrar_menu();
    
    //Pre: -
    //Post: muestra el menu del turno
    void mostrar_menu_partida();

    //Pre: 1 <= opcion <= 5
    //Post: procesa la opcion ingresada por el usuario
    void procesar_opcion_menu(int opcion_elegida);

    //Pre: 1 <= opcion <= 13
    //Post: procesa la opcion ingresada por el usuario
    void procesar_opcion_partida(int opcion_elegida, Jugador *jugador, Jugador *rival);

    //Pre: -
    //Post: guarda la partida 
    void guardar();

    //Pre: -
    //Post: escenario principal del juego
    void partida();

    //Pre: -
    //Post: reescribe el archivo materiales con los datos de la partida
    void reescribir_materiales();

    //Pre: jugadores creados
    //Post: crea una cola de jugadores asignar turnos
    Jugador** crear_cola_jugadores(Jugador *jugador1, Jugador *jugador2);

    //Pre: -
    //Post: cambia el turno de los jugadores
    void cambiar_turno(Jugador** lista_jugadores);

    //pre: -
    //pos: comienza proceso de reescribir los archivos
    void secuencia_victoria(Jugador* jugador);

    //pre: -
    //pos: modifica los valores iniciales de los edificios
    void modificar_datos_edificio();
    
    //pre: -
    //pos: asigna los objetivos a los jugadores
    void asignar_objetivos();

    //pre: -
    //pos: devuelve un objetivo 
    Objetivo* crear_objetivo(int numero_objetivo, int numero_jugador);

    //pre: -
    //pos: escribe las coordenadas de los jugadores
    void borrar_archivo_ubicaciones();

    //pre: -
    //pos: escribe el archivo ubicaciones con materiales
    void resetear_archivo_materiales();

    //pre: -
    //pos: mensaje que resume tus estadisticas
    void mostrar_resumen(Jugador** cola);
};




#endif