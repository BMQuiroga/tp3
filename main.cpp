#include <iostream>
#include "menu.h"
#include "ideas1.h"

using namespace std;


int main(){
    ListaEdificios edificios;
    Mapa mapa(edificios);
    // Jugador jugador1(1,1,1);
    // Jugador jugador2(2,2,2);
    //std::cout<<"supera mapa y edificios"<<std::endl;
    Jugador jugador1(1,1,1,edificios, &mapa);
    Jugador jugador2(2,2,2, edificios, &mapa);
    //std::cout<<"creados jugadores"<<std::endl;
    procesar_archivo_materiales(jugador1,jugador2);
    bool archivo_en_blanco=mapa.procesar_archivo_ubicaciones(edificios,jugador1,jugador2);
    
    if(archivo_en_blanco)
        partida(edificios,mapa,jugador1,jugador2);
    else{
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
        
    }
    //}
        //guardar_archivo_materiales(materiales, tope_material);
        //guardar_archivo_edificios(edificios, tope_edificio);
    return 0;
}

