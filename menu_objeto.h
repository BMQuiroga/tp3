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
    void procesar_opcion_menu();
    void procesar_opcion_partida();
    void guardar();
    void partida();
    bool esta_terminado();
    






};




#endif