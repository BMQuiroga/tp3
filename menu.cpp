#include "menu.h"
#include <iostream>
#include "mapa.h"
#include "listaedificios.h"
#include "listamateriales.h"
#include "mapa.h"



using namespace std;

void mostrar_menu(){
    cout << "1. Modificar edificio por nombre"<<endl;
    cout << "2. Listar todos los edificios"<<endl;
    cout << "3. Mostrar mapa"<<endl;
    cout << "4. Comenzar partida"<<endl;
    cout << "5. Guardar y salír"<<endl;
}

void mostrar_menu_partida(){
    cout << "1. Construir edificio por nombre"<<endl;
    cout << "2. Listar mis edificios construidos" <<endl;
    cout << "3. Demoler un edificio por coordenada"<<endl;
    cout << "4. Atacar un edificio por coordenada"<<endl;
    cout << "5. Reparar un edificio por coordenada"<<endl;
    cout << "6. Comprar bombas"<<endl;
    cout << "7. Consultar coordenada"<<endl;
    cout << "8. Mostrar inventario"<<endl;
    cout << "9. Mostrar objetivos"<<endl;
    cout << "10. Recolectar recursos producidos"<<endl;
    cout << "11. Moverse a una coordenada"<<endl;
    cout << "12. Finalizar Turno"<<endl;
    cout << "13. Guardar y salír"<<endl;
}
void procesar_opcion_menu(int opcion_elegida, ListaMateriales materiales, ListaEdificios edificios, Mapa mapa){
    system(CLR_SCREEN);
    switch(opcion_elegida){
        case MODIFICAR_EDIFICIO:
            //mapa.construir(edificios,materiales);
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            //mapa.listar_edificios_construidos(edificios);
            break;
        case MOSTRAR_MAPA:
            //mapa.listar_todos_los_edificios(edificios);
            break;
        case COMENZAR_PARTIDA:
            //mapa.menu_demoler(materiales);
            break;
        case GUARDAR_Y_SALIR_MENU:
            //mapa.mostrar_mapa();
            break;
    }
}

void procesar_opcion_partida(int opcion_elegida, ListaMateriales materiales, ListaEdificios edificios, Mapa mapa){
    system(CLR_SCREEN);
    switch(opcion_elegida){
        case CONSTRUIR_EDIFICIO:
            mapa.construir(edificios,materiales);
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mapa.listar_edificios_construidos(edificios);
            break;
        case DEMOLER_EDIFICIO:
            mapa.listar_todos_los_edificios(edificios);
            break;
        case ATACAR_EDIFICIO:
            mapa.menu_demoler(materiales);
            break;
        case REPARAR_EDIFICIO:
            mapa.mostrar_mapa();
            break;
        case COMPRAR_BOMBAS:
            mapa.menu_consultar_coordenada();
            break;
        case CONSULTAR_COORDENADA:
            materiales.mostrar();
            break;
        case MOSTRAR_INVENTARIO:
            mapa.llamar_lluvia();
            break;
        case MOSTRAR_OBJETIVOS:
            mapa.llamar_lluvia();
            break;
        case RECOLECTAR_RECURSOS:
            mapa.llamar_lluvia();
            break;
        case MOVERSE:
            mapa.llamar_lluvia();
            break;
        case FINALIZAR_TURNO:
            mapa.llamar_lluvia();
            break;
        case GUARDAR_Y_SALIR_PARTIDA:
            mapa.llamar_lluvia();
            break;
        /*case SALIR:
            guardar(materiales,edificios,mapa);
            cout<< "Gracias por el usar el programa" <<endl;
            cout<< ".....Adios....." << endl;
            system(CLR_SCREEN);
            cout<< endl;
            break;
        default:
        cout<< "Error: opcion invalida";*/
    }
}

bool es_opcion_valida(int elegida, int maxima){
    return (elegida>=1 && elegida <= maxima);
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