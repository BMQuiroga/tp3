#include "menu.h"
#include <iostream>
#include "mapa.h"
#include "listaedificios.h"
#include "listamateriales.h"
#include "mapa.h"



using namespace std;

void mostrar_menu(){
    cout << "1. Construir edificio por nombre"<<endl;
    cout << "2. Listar edificios construidos" <<endl;
    cout << "3. Listar todos los edificios"<<endl;
    cout << "4. Demoler un edificio por coordenada"<<endl;
    cout << "5. Mostrar mapa"<<endl;
    cout << "6. Consultar coordenada"<<endl;
    cout << "7. Mostrar inventario"<<endl;
    cout << "8. Recolectar recursos producidos"<<endl;
    cout << "9. Llamar lluvia de recursos"<<endl;
    cout << "10. Salir"<<endl;
}

void procesar_opcion(int opcion_elegida, ListaMateriales materiales, ListaEdificios edificios, Mapa mapa){
    system(CLR_SCREEN);
    switch(opcion_elegida){
        case CONSTRUIR_EDIFICIO:
            mapa.construir(edificios,materiales);
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mapa.listar_edificios_construidos(edificios);
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            mapa.listar_todos_los_edificios(edificios);
            break;
        case DEMOLER_EDIFICIO:
            mapa.menu_demoler(materiales);
            break;
        case MOSTRAR_MAPA:
            mapa.mostrar_mapa();
            break;
        case CONSULTAR_COORDENADA:
            mapa.menu_consultar_coordenada();
            break;
        case LISTAR_MATERIALES:
            materiales.mostrar();
            break;
        case RECOLECTAR_RECURSOS:
            mapa.recolectar(materiales);
            break;
        case LLUVIA_DE_RECURSOS:
            mapa.llamar_lluvia();
            break;
        case SALIR:
            guardar(materiales,edificios,mapa);
            cout<< "Gracias por el usar el programa" <<endl;
            cout<< ".....Adios....." << endl;
            system(CLR_SCREEN);
            cout<< endl;
            break;
        default:
        cout<< "Error: opcion invalida";
    }
}

bool es_opcion_valida(int elegida){
    return (elegida>= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}

void guardar(ListaMateriales materiales, ListaEdificios edificios, Mapa mapa){
    //REESCRIBIR ARCHIVOS
    materiales.reescribir_materiales();
    mapa.reescribir_ubicaciones();
    //DESTRUIR
    edificios.destruir();//teniamos un problema donde los destructores se activaban antes de salir, asi que hicimos destructores asi
    materiales.destruir();
    mapa.destruir();
}

int generador_de_numeros_aleatorios(int min, int max){
  return min + rand()%(max-min);
}