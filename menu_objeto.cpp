#include <iostream>
#include "menu_objeto.h"
#include <fstream>

const int JUGADOR = 0;
const int RIVAL =   1;

using namespace std;

Menu::Menu(Mapa* mapa, ListaEdificios* edificios, Jugador* jugador1, Jugador* jugador2) {
    this->mapa = mapa;
    this->edificios = edificios;
    this->jugador1 = jugador1;
    this->jugador2 = jugador2;
}


void Menu::guardar(){
    // edificios.reescribir();
    // reescribir_materiales();
    // mapa.reescribir_ubicaciones(jugador1,jugador2);
    // edificios.destruir();
    // mapa.destruir();
    // jugador1.destruir();
    // jugador2.destruir();
}


void Menu::mostrar_menu(){
    cout << "1. Modificar edificio por nombre"<<endl;
    cout << "2. Listar todos los edificios"<<endl;
    cout << "3. Mostrar mapa"<<endl;
    cout << "4. Comenzar partida"<<endl;
    cout << "5. Guardar y salir"<<endl;
}


void Menu::mostrar_menu_partida(){
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
    cout << "13. Guardar y salir"<<endl;
}

void Menu::partida(/*ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u*/){
    int opcion = -1;

    Jugador** lista_jugadores = crear_cola_jugadores(jugador1, jugador2);

    while(opcion != GUARDAR_Y_SALIR_PARTIDA) {
        while  (opcion != GUARDAR_Y_SALIR_PARTIDA && 
                opcion != FINALIZAR_TURNO && 
                lista_jugadores[JUGADOR]->devolver_energia() != 0  && 
                !lista_jugadores[RIVAL]->ha_ganado()) {

            cout << "Es el turno del jugador numero " << lista_jugadores[JUGADOR]->devolver_nombre() << endl;  
            mostrar_menu_partida();
            opcion = utilidad.pedir_opcion();
            procesar_opcion_partida(opcion, lista_jugadores[JUGADOR], lista_jugadores[RIVAL]);
        }
        lista_jugadores[JUGADOR]->sumar_energia(20);
        // if(lista_jugadores[JUGADOR]->devolver_nombre()==2)
        //     mapa->llamar_lluvia(jugador1,jugador2);
        // if(checkear_si_gano(lista_jugadores[JUGADOR]))
        //     secuencia_victoria(lista_jugadores[JUGADOR]);
        cambiar_turno(lista_jugadores);
        utilidad.limpiar_pantalla();
        if (opcion != GUARDAR_Y_SALIR_PARTIDA) opcion = -1;
    }
    
    delete [] lista_jugadores; //poner en otro lado
}


Jugador** Menu::crear_cola_jugadores(Jugador *jugador1, Jugador* jugador2) {   
    Jugador ** lista_jugadores = new Jugador*[2];
    lista_jugadores[0] = jugador1;
    lista_jugadores[1] = jugador2;

    return lista_jugadores;
}

void Menu::cambiar_turno(Jugador** lista_jugadores) {
    Jugador* aux = lista_jugadores[0];
    lista_jugadores[0] = lista_jugadores[1];
    lista_jugadores[1] = aux;
}


void Menu::procesar_opcion_menu(int opcion_elegida){
    utilidad.limpiar_pantalla();
    switch(opcion_elegida){
        case MODIFICAR_EDIFICIO:
            //no esta testeado
            //modificar_datos_edificio(edificios);
            
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            mapa->listar_todos_los_edificios(edificios,jugador1,jugador2);
            break;
        case MOSTRAR_MAPA:
            mapa->mostrar_mapa(jugador1,jugador2);
            break;
        case COMENZAR_PARTIDA:
            partida();
            break;
        case GUARDAR_Y_SALIR_MENU:
            //falta
            break;
    }
    utilidad.pausa();
    utilidad.limpiar_pantalla();
}

void Menu::procesar_opcion_partida(int opcion_elegida, Jugador* jugador, Jugador* rival){
    utilidad.limpiar_pantalla();
    switch(opcion_elegida){
        case CONSTRUIR_EDIFICIO:
            cout << "CONSTRUIR EDIFICIO POR NOMBRE" << endl;
            cout << "---------------------------------" << endl;
            mapa->construir(edificios,jugador,rival); 
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            cout << "LISTAR EDIFICIOS CONSTRUIDOS" << endl;
            cout << "---------------------------------" << endl;
            mapa->listar_edificios_construidos(edificios,jugador);
            break;
        case DEMOLER_EDIFICIO:
            cout << "DEMOLER EDIFICIO POR COORDENADAS" << endl;
            cout << "---------------------------------" << endl;
            mapa->menu_demoler(edificios,jugador);
            break;
        case ATACAR_EDIFICIO:
            cout << "ATACAR EDIFICIO POR COORDENADA" << endl;
            cout << "---------------------------------" << endl;
            mapa->menu_atacar(jugador,rival);
            break;
        case REPARAR_EDIFICIO:
            cout << "REPARAR EDIFICIO POR COORDENADA" << endl;
            cout << "---------------------------------" << endl;
            mapa->menu_reparar(jugador);
            break;
        case COMPRAR_BOMBAS:
            cout << "COMPRAR BOMBAS" << endl;
            cout << "---------------------------------" << endl;
            jugador->comprar_bombas();
            break; 
        case CONSULTAR_COORDENADA:
            cout << "CONSULTAR COORDENADA" << endl;
            cout << "---------------------------------" << endl;
            mapa->menu_consultar_coordenada();
            break;
        case MOSTRAR_INVENTARIO:
            cout << "MOSTRAR INVENTARIO" << endl;
            cout << "---------------------------------" << endl;
            jugador->devolver_materiales()->mostrar();
            break;
        case MOSTRAR_OBJETIVOS:
            cout << "MOSTRAR OBJETIVOS" << endl;
            cout << "---------------------------------" << endl;
            jugador->mostrar_objetivos();
            break;
        case RECOLECTAR_RECURSOS:
            cout << "RECOLECTAR RECURSOS" << endl;
            cout << "---------------------------------" << endl;
            mapa->recolectar(jugador);
            break;
        case MOVERSE:
            cout << "MOVER JUGADOR" << endl;
            cout << "---------------------------------" << endl;
            jugador->mover_jugador(mapa);
            break;
        case FINALIZAR_TURNO:
            cout << "CAMBIO DE TURNO" << endl;
            cout << "---------------------------------" << endl;
            cout << "Le toca al jugador numero " << rival->devolver_nombre() << "." << endl;
            //no hace nada
            break;
        case GUARDAR_Y_SALIR_PARTIDA:
            guardar();
            break;
        default:
            cout<< "Error: opcion invalida";
            break;
    }
    utilidad.pausa();    
    utilidad.limpiar_pantalla();
}

void Menu::reescribir_materiales(){
    ofstream archivo_materiales;
    archivo_materiales.open("materiales.txt");

    if(!archivo_materiales.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo materiales" <<std::endl;
    }else{
        for (int i=0 ; i<this->jugador1->devolver_materiales()->devolver_cantidad() ; i++){
            //std::cout<<this->consulta(i+1).devolver_nombre()<<std::endl;
            archivo_materiales<<this->jugador1->devolver_materiales()->consulta(i+1)->devolver_nombre();
            archivo_materiales<<" ";
            archivo_materiales<<this->jugador1->devolver_materiales()->consulta(i+1)->devolver_cantidad();
            archivo_materiales<<" ";
            archivo_materiales<<this->jugador2->devolver_materiales()->consulta(i+1)->devolver_cantidad();
            archivo_materiales<<std::endl;
        }
    archivo_materiales.close();
    }
}

bool Menu::checkear_si_gano(Jugador* jugador){
    return ( (mapa->tiene_edificio("obelisco",jugador)) || (jugador->cumplio_objetivo_secundario()) );
}

void Menu::secuencia_victoria(Jugador* jugador){
    std::cout << "El jugador " << jugador->devolver_nombre() << " ha ganado el partido" << endl;
    // borrar_archivo_ubicaciones();
    // resetear_archivo_materiales(jugador);
}