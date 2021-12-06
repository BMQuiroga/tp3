#include <iostream>
#include "menu.h"
#include "ideas1.h"

using namespace std;


int main(){
    ListaEdificios edificios;
    Mapa* mapa = new Mapa(edificios);
    // Mapa mapa(edificios);

    Jugador jugador1(1,1,1, edificios, mapa);
    Jugador jugador2(2,2,2, edificios, mapa);
    
    ListaMateriales materiales1;
    ListaMateriales materiales2;

    // procesar_archivo_materiales(jugador1,jugador2);
    procesar_archivo_materiales(materiales1,materiales2);   //tuve que hacerlo asi porque sino perdia scope las variables y me devolvia 0 el primer puntero

    jugador1.asignar_lista_materiales(materiales1);
    jugador2.asignar_lista_materiales(materiales2);


    

    //lista_objetivos1
    //lista_objetivos2
    //juegador1.asignar_objetivo(lista_objetivos)

    bool archivo_en_blanco = false;
    // bool archivo_en_blanco=mapa.procesar_archivo_ubicaciones(edificios,jugador1,jugador2);
    
    if(archivo_en_blanco)
        partida(edificios,*mapa,jugador1,jugador2);
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
            // procesar_opcion_menu(opcion_elegida,materiales,edificios,mapa,jugador1,jugador2);
            procesar_opcion_menu(opcion_elegida, edificios, *mapa, jugador1, jugador2);

        }while(opcion_elegida!=GUARDAR_Y_SALIR_MENU);
        
    }
    //}
        //guardar_archivo_materiales(materiales, tope_material);
        //guardar_archivo_edificios(edificios, tope_edificio);
    return 0;
}

