#include <iostream>
#include "menu.h"

using namespace std;


int main(){
    ListaEdificios edificios;
    ListaMateriales materiales;
    Mapa mapa(edificios);
    //construir los 2 jugadores
    //pasar los 2 jugadores por procesar_archivo_materiales que esta en ideas1.cpp
    //if (ubicaciones=false){partida()}
    int opcion_elegida;
    do{
        cout<< "Bienvenido a Andypolis :D !" << endl;
        cout << "Escriba una opcion" <<endl;
        mostrar_menu();
        cin >> opcion_elegida;
        while(!es_opcion_valida(opcion_elegida,5)){
            cout<<"No es valida "<< endl;
            mostrar_menu();
            cin >> opcion_elegida;

        }
        //procesar_opcion_menu(opcion_elegida,materiales,edificios,mapa,jugador1,jugador2);
    }while(opcion_elegida!=GUARDAR_Y_SALIR_MENU);
    //}
    //guardar_archivo_materiales(materiales, tope_material);
    //guardar_archivo_edificios(edificios, tope_edificio);
    return 0;
}

