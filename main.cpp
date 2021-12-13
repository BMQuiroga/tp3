#include <iostream>
#include "menu_objeto.h"
#include "archivo.h"
#include "utilidad.h"

using namespace std;


int main(){
    Archivo archivo;
    Utilidad util;

    ListaEdificios* edificios = new ListaEdificios;
    edificios->procesar_archivo_edificios();      

    ListaMateriales* materiales1 = new ListaMateriales; 
    ListaMateriales* materiales2 = new ListaMateriales;

    archivo.procesar_archivo_materiales(materiales1,materiales2);
    
    Mapa* mapa = archivo.procesar_archivo_mapa();

    Jugador* jugador1 = new Jugador(1,1,1, edificios, mapa);
    Jugador* jugador2 = new Jugador(2,2,2, edificios, mapa);
    mapa->procesar_archivo_ubicaciones(edificios, jugador1, jugador2);
    jugador1->asignar_lista_materiales(materiales1);
    jugador2->asignar_lista_materiales(materiales2);


    Menu menu(mapa, edificios, jugador1, jugador2);

    bool archivo_en_blanco=mapa->procesar_archivo_ubicaciones(edificios,jugador1,jugador2);

    menu.asignar_objetivos();
    
    if(archivo_en_blanco)
        menu.partida();
    else{
        int opcion_elegida;
        do{
            util.encuadrar("Bienvenido a Andypolis :D !");
            cout << endl;
            cout << "Escriba una opcion" <<endl;
            cout << endl;
            menu.mostrar_menu();
            opcion_elegida = util.pedir_opcion();
            menu.procesar_opcion_menu(opcion_elegida);

        }while(opcion_elegida!=GUARDAR_Y_SALIR_MENU);
        
    }
    menu.guardar();

    delete jugador1;
    delete jugador2;
    delete edificios;
    delete mapa;
    delete materiales1;
    delete materiales2;
    return 0;
}

