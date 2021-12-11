#include <iostream>
#include "menu.h"
#include "menu_objeto.h"
#include "archivo.h"

using namespace std;


int main(){
    Archivo archivo;
    Utilidad util;

    ListaEdificios* edificios = new ListaEdificios;
    edificios->procesar_archivo_edificios();      

    ListaMateriales materiales1, materiales2;
    archivo.procesar_archivo_materiales(materiales1,materiales2);   //tuve que hacerlo asi porque sino perdia scope las variables y me devolvia 0 el primer puntero
    
    Mapa* mapa = archivo.procesar_archivo_mapa();

    Jugador* jugador1 = new Jugador(1,1,1, edificios, mapa);
    Jugador* jugador2 = new Jugador(2,2,2, edificios, mapa);
    std::cout << "aca" << std::endl;
    mapa->procesar_archivo_ubicaciones(edificios, jugador1, jugador2);
    std::cout << "aca" << std::endl;
    jugador1->asignar_lista_materiales(&materiales1);
    jugador2->asignar_lista_materiales(&materiales2);
    // Jugador jugador1(1,1,1, edificios, mapa);
    // Jugador jugador2(2,2,2, edificios, mapa);
    

    // jugador2.devolver_coordenada_x(materiales2);

    Menu menu(mapa, edificios, jugador1, jugador2);

    //ListaObjetivos vector_objetivos_completos1(jugador1, materiales1, edificios, mapa);
    //jugador1.asignar_objetivos_aleatorios(ListaObjetivos::obtener_objetivos_aleatorios())
    //jugador1.asignar_objetivos_aleatorios(vector_objetivos_completos1);
    //lista_objetivos1
    //lista_objetivos2
    //juegador1.asignar_objetivo(lista_objetivos)

    bool archivo_en_blanco = false;
    //bool archivo_en_blanco=mapa->procesar_archivo_ubicaciones(edificios,jugador1,jugador2);
    
    if(archivo_en_blanco)
        menu.partida(/*edificios,*mapa,jugador1,jugador2*/);
    else{
        int opcion_elegida;
        do{
            cout<< "Bienvenido a Andypolis :D !" << endl;
            cout << "Escriba una opcion" <<endl;
            menu.mostrar_menu();
            opcion_elegida = util.pedir_opcion();
            menu.procesar_opcion_menu(opcion_elegida);

        }while(opcion_elegida!=GUARDAR_Y_SALIR_MENU);
        
    }
    //}
        //guardar_archivo_materiales(materiales, tope_material);
        //guardar_archivo_edificios(edificios, tope_edificio);
    return 0;
}

