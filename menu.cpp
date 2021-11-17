#include "menu.h"
#include <iostream>
#include "mapa.h"
#include "listaedificios.h"
#include "listamateriales.h"
#include "mapa.h"
#include "jugador.h"



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

void procesar_opcion_menu(int opcion_elegida, ListaMateriales materiales, ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u){
    system(CLR_SCREEN);
    switch(opcion_elegida){
        case MODIFICAR_EDIFICIO:
            //no esta testeado
            modificar_datos_edificio(edificios);
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            mapa.listar_todos_los_edificios(edificios,j,u);
            break;
        case MOSTRAR_MAPA:
            mapa.mostrar_mapa(j,u);
            break;
        case COMENZAR_PARTIDA:
            partida(materiales,edificios,mapa,j,u);
            break;
        case GUARDAR_Y_SALIR_MENU:
            //falta
            break;
    }
}

void procesar_opcion_partida(int opcion_elegida, ListaEdificios edificios, Mapa mapa, Jugador jugador, Jugador rival){
    system(CLR_SCREEN);
    switch(opcion_elegida){
        case CONSTRUIR_EDIFICIO:
            mapa.construir(edificios,jugador); 
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mapa.listar_edificios_construidos(edificios,jugador);
            break;
        case DEMOLER_EDIFICIO:
            mapa.menu_demoler(jugador); //solo podes demoler tus edificios y le devuelve los materiales al jugador
            break;
        case ATACAR_EDIFICIO:
            //nueva
            break;
        case REPARAR_EDIFICIO:
            //nueva
            break;
        case COMPRAR_BOMBAS:
            jugador.comprar_bombas();
            break;
        case CONSULTAR_COORDENADA:
            //se queda igual
            break;
        case MOSTRAR_INVENTARIO:
            jugador.devolver_materiales()->mostrar();
            break;
        case MOSTRAR_OBJETIVOS:
            //nuevo
            break;
        case RECOLECTAR_RECURSOS:
            mapa.recolectar(jugador);
            break;
        case MOVERSE:
            //nueva
            break;
        case FINALIZAR_TURNO:
            //no hace nada
            break;
        case GUARDAR_Y_SALIR_PARTIDA:
            /*llamar a la funcion guardar
            guardar(materiales,edificios,mapa);
            cout<< "Gracias por el usar el programa" <<endl;
            cout<< ".....Adios....." << endl;
            system(CLR_SCREEN);
            cout<< endl;*/
            break;
        default:
        cout<< "Error: opcion invalida";
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

void partida(ListaMateriales materiales, ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u){
    int opcion=0;
    while(opcion!=GUARDAR_Y_SALIR_PARTIDA){
        while(opcion!=GUARDAR_Y_SALIR_PARTIDA && j.devolver_energia()!=0){
            mostrar_menu_partida();
            cin >> opcion;
            while(!es_opcion_valida(opcion,GUARDAR_Y_SALIR_PARTIDA)){
                cout<<"No es valida "<< endl;
                mostrar_menu_partida();
                cin >> opcion;
            }
            procesar_opcion_partida(opcion,materiales,edificios,mapa,j,u);
            //CHECKEAR SI TERMINO TODOS LOS OBJETIVOS
        }
        j.sumar_energia(20);
        opcion=corregir_opcion(opcion);
        while(opcion!=GUARDAR_Y_SALIR_PARTIDA && u.devolver_energia()!=0){
            mostrar_menu_partida();
            cin >> opcion;
            while(!es_opcion_valida(opcion,GUARDAR_Y_SALIR_PARTIDA)){
                cout<<"No es valida "<< endl;
                mostrar_menu_partida();
                cin >> opcion;
            }
            procesar_opcion_partida(opcion,materiales,edificios,mapa,u,j);
            //CHECKEAR SI TERMINO TODOS LOS OBJETIVOS
        }
        u.sumar_energia(20);
        //llamar lluvia recursos
        opcion=corregir_opcion(opcion);
    }
}

int corregir_opcion(int opcion){
    if (opcion!=GUARDAR_Y_SALIR_PARTIDA)
        return 1;
    return GUARDAR_Y_SALIR_PARTIDA;
}


void modificar_datos_edificio(ListaEdificios edificios) {
    // no probe si funciona, por ahi tiene algun error boludo
    std::string nombre;
    bool resultado = false;
    Edificio edificio;
    int indice = 0;

    cout << "Ingrese el nombre del edificio que quiere modificar o \"fin\" para cancelar: ";
    cin >> nombre;

    while (!resultado && nombre != "fin") {
        indice = edificios.buscar_indice(nombre);

        if (indice == -1) {
            cout << "No se encontro el edificio ingresado. Intente de nuevo: ";
            cin >> nombre;

        } else {
            edificio = edificios.consulta(indice);

            if (edificio.devolver_nombre() != "obelisco") {
                cout << "Se encontro el edificio " << edificio.devolver_nombre() << "." << endl;
                edificio.modificar_datos();
            } else {
                cout << "No se puede cambiar los datos del obelisco." << endl;
            }

            resultado = true;
        }
    }
}