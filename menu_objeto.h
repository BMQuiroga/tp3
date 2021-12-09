#ifndef MENU_OBJETO_H
#define MENU_OBJETO_H

#include "menu.h"

class Menu{
private:
    Jugador jugador1;
    Jugador jugador2;
    Mapa mapa;
    ListaEdificios edificios;

public:
    Menu(Mapa mapa, ListaEdificios edificios, Jugador jugador1, Jugador jugador2);
    void mostrar_menu();
    void mostrar_menu_partida();
    void procesar_opcion_menu(int opcion_elegida);
    void procesar_opcion_partida(int opcion_elegida, Jugador jugador, Jugador rival);
    void guardar();
    void partida();
    void reescribir_materiales();
    Jugador* crear_cola_jugadores(Jugador jugador1, Jugador jugador2);
    void cambiar_turno(Jugador* lista_jugadores);
    bool checkear_si_gano(Jugador jugador);
    void secuencia_victoria(Jugador jugador);
    
};




#endif