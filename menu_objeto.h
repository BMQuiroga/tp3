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
    void mostrar_menu();
    void mostrar_menu_partida();
    void procesar_opcion_menu(int opcion_elegida);
    void procesar_opcion_partida(int opcion_elegida, Jugador jugador, Jugador rival);
    void guardar();
    void partida(ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u);
    void reescribir_materiales();
    






};




#endif