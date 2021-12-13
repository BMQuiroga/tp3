#include <iostream>
#include "menu_objeto.h"
#include <fstream>
#include "ComprarAndypolis.h"
#include "Armado.h"
#include "Bombardero.h"
#include "Cansado.h"
#include "Constructor.h"
#include "EdadDePiedra.h"
#include "Energetico.h"
#include "Extremista.h"
#include "Letrado.h"
#include "Minero.h"
#include "Obelisco.h"
//#include <cstdlib>
//#include <ctime>
//#include <cmath>
//#include <fstream>

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
    edificios->reescribir();
    reescribir_materiales();
    mapa->reescribir_ubicaciones(jugador1,jugador2);
}


void Menu::mostrar_menu(){
    cout << "1. Modificar edificio por nombre"<<endl;
    cout << "2. Listar todos los edificios"<<endl;
    cout << "3. Mostrar mapa"<<endl;
    cout << "4. Comenzar partida"<<endl;
    cout << "5. Guardar y salir"<<endl;
}


void Menu::mostrar_menu_partida(){
    cout << " 1. Construir edificio por nombre"<<endl;
    cout << " 2. Listar mis edificios construidos" <<endl;
    cout << " 3. Demoler un edificio por coordenada"<<endl;
    cout << " 4. Atacar un edificio por coordenada"<<endl;
    cout << " 5. Reparar un edificio por coordenada"<<endl;
    cout << " 6. Comprar bombas"<<endl;
    cout << " 7. Consultar coordenada"<<endl;
    cout << " 8. Mostrar inventario"<<endl;
    cout << " 9. Mostrar objetivos"<<endl;
    cout << "10. Recolectar recursos producidos"<<endl;
    cout << "11. Moverse a una coordenada"<<endl;
    cout << "12. Finalizar Turno"<<endl;
    cout << "13. Guardar y salir"<<endl;
}

void Menu::partida(/*ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u*/){
    int opcion = -1;

    Jugador** lista_jugadores = crear_cola_jugadores(jugador1, jugador2);

    while(opcion != GUARDAR_Y_SALIR_PARTIDA && !lista_jugadores[RIVAL]->checkear_objetivos()) {
        while  (opcion != GUARDAR_Y_SALIR_PARTIDA && 
                opcion != FINALIZAR_TURNO && 
                lista_jugadores[JUGADOR]->devolver_energia() != 0  && 
                !lista_jugadores[RIVAL]->checkear_objetivos()) {

            mostrar_resumen(lista_jugadores);
            mostrar_menu_partida();
            opcion = utilidad.pedir_opcion();
            procesar_opcion_partida(opcion, lista_jugadores[JUGADOR], lista_jugadores[RIVAL]);
        }
        lista_jugadores[JUGADOR]->sumar_energia(20);
        if(lista_jugadores[JUGADOR]->devolver_nombre()==2){
            mapa->llamar_lluvia(jugador1,jugador2);
            std::cout << "lluvia" << std::endl;
        }
        cambiar_turno(lista_jugadores);
        utilidad.limpiar_pantalla();
        if (opcion != GUARDAR_Y_SALIR_PARTIDA) opcion = -1;
    }
    
    if(lista_jugadores[RIVAL]->checkear_objetivos()){
        secuencia_victoria(lista_jugadores[RIVAL]);
        edificios->reescribir();
    }
    else{
        guardar();
    }
    
    delete [] lista_jugadores; //poner en otro lado
}

void Menu::mostrar_resumen(Jugador** lista_jugadores) {
    int numero = lista_jugadores[JUGADOR]->devolver_nombre();
    utilidad.encuadrar("Es el turno del jugador numero " + to_string(numero));
    cout << " Tienes " << lista_jugadores[JUGADOR]->devolver_energia() << " de energia" << endl;
    cout << " Posicion actual: (" << lista_jugadores[JUGADOR]->devolver_coordenada_x() << " ," << lista_jugadores[JUGADOR]->devolver_coordenada_y() << ")"<<std::endl;
    cout << endl;
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
            utilidad.encuadrar("MODIFICAR EDIFICIO");
            modificar_datos_edificio();
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            utilidad.encuadrar("LISTAR TODOS LOS EDIFICIOS");
            mapa->listar_todos_los_edificios(edificios,jugador1,jugador2);
            break;
        case MOSTRAR_MAPA:
            utilidad.encuadrar("MOSTRAR MAPA");
            mapa->mostrar_mapa(jugador1,jugador2);
            break;
        case COMENZAR_PARTIDA:
            partida();
            break;
        case GUARDAR_Y_SALIR_MENU:
            utilidad.encuadrar("GRACIAS POR JUGAR");
            break;
        default:
            cout << "Opcion fuera de rango." << endl;
            utilidad.linea();
            break;
    }
    utilidad.pausa();
    utilidad.limpiar_pantalla();
}

void Menu::procesar_opcion_partida(int opcion_elegida, Jugador* jugador, Jugador* rival){
    utilidad.limpiar_pantalla();
    switch(opcion_elegida){
        case CONSTRUIR_EDIFICIO:
            utilidad.encuadrar("CONSTRUIR EDIFICIO POR NOMBRE");
            mapa->construir(edificios,jugador,rival); 
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            utilidad.encuadrar("LISTAR EDIFICIOS CONSTRUIDOS");
            mapa->listar_edificios_construidos(edificios,jugador);
            break;
        case DEMOLER_EDIFICIO:
            utilidad.encuadrar("DEMOLER EDIFICIO POR COORDENADAS");
            mapa->menu_demoler(edificios,jugador);
            break;
        case ATACAR_EDIFICIO:
            utilidad.encuadrar("ATACAR EDIFICIO POR COORDENADA");
            mapa->menu_atacar(jugador,rival);
            break;
        case REPARAR_EDIFICIO:
            utilidad.encuadrar("REPARAR EDIFICIO POR COORDENADA");
            mapa->menu_reparar(jugador);
            break;
        case COMPRAR_BOMBAS:
            utilidad.encuadrar("COMPRAR BOMBAS");
            jugador->comprar_bombas();
            break; 
        case CONSULTAR_COORDENADA:
            utilidad.encuadrar("CONSULTAR COORDENADA");
            mapa->menu_consultar_coordenada();
            break;
        case MOSTRAR_INVENTARIO:
            utilidad.encuadrar("MOSTRAR INVENTARIO");
            jugador->devolver_materiales()->mostrar();
            break;
        case MOSTRAR_OBJETIVOS:
            utilidad.encuadrar("MOSTRAR OBJETIVOS");
            jugador->mostrar_objetivos();
            break;
        case RECOLECTAR_RECURSOS:
            utilidad.encuadrar("RECOLECTAR RECURSOS");
            mapa->recolectar(jugador);
            break;
        case MOVERSE:
            utilidad.encuadrar("MOVER JUGADOR");
            jugador->mover_jugador(mapa, rival);
            break;
        case FINALIZAR_TURNO:
            utilidad.encuadrar("CAMBIO DE TURNO");
            cout << "Le toca al jugador numero " << rival->devolver_nombre() << "." << endl;
            //no hace nada
            break;
        case GUARDAR_Y_SALIR_PARTIDA:
            //guardar();
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
/*
bool Menu::checkear_si_gano(Jugador* jugador){
    return ( (mapa->tiene_edificio("obelisco",jugador)) || (jugador->cumplio_objetivo_secundario()) );
}*/

void Menu::secuencia_victoria(Jugador* jugador){
    std::cout << "El jugador " << jugador->devolver_nombre() << " ha ganado el partido" << endl;
    borrar_archivo_ubicaciones();
    resetear_archivo_materiales();
}

void Menu::modificar_datos_edificio(){
    std::string nombre;
    bool resultado = false;
    Edificio * edificio;
    //int indice = 0;

    cout << "Ingrese el nombre del edificio que quiere modificar o \"fin\" para cancelar: ";
    cin >> nombre;

    while (!resultado && nombre != "fin") {
        if (!edificios->es_edificio_valido(nombre)) {
            cout << "No se encontro el edificio ingresado. Intente de nuevo: ";
            cin >> nombre;

        } else {

            if (nombre != "obelisco") {
                edificio = edificios->consulta(nombre);
                cout << "Se encontro el edificio " << edificio->devolver_nombre() << "." << endl;
                edificio->modificar_datos();
                //edificios.cambiar_nodo(edificio);
            } else {
                cout << "No se puede cambiar los datos del obelisco." << endl;
            }

            resultado = true;
        }
    }
 }

 void Menu::asignar_objetivos() {
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    Utilidad util;
    //srand(time(0));
    while (a==b || b==c || a==c || d==e || e==f || f==d ){
         a=util.generador_de_numeros_aleatorios(1,10);
         b=util.generador_de_numeros_aleatorios(1,10);
         c=util.generador_de_numeros_aleatorios(1,10);
         d=util.generador_de_numeros_aleatorios(1,10);
         e=util.generador_de_numeros_aleatorios(1,10);
         f=util.generador_de_numeros_aleatorios(1,10);
    }
    jugador1->asignar_objetivo_1(new Obelisco(edificios,mapa,jugador1));
    jugador1->asignar_objetivo_2(crear_objetivo(a,1));
    jugador1->asignar_objetivo_3(crear_objetivo(b,1));
    jugador1->asignar_objetivo_4(crear_objetivo(c,1));
    jugador2->asignar_objetivo_1(new Obelisco(edificios,mapa,jugador2));
    jugador2->asignar_objetivo_2(crear_objetivo(d,2));
    jugador2->asignar_objetivo_3(crear_objetivo(e,2));
    jugador2->asignar_objetivo_4(crear_objetivo(f,2));
}

Objetivo* Menu::crear_objetivo(int numero, int numero_jugador) {
    Objetivo* nuevo_objetivo=nullptr;
    switch (numero){
    case OBJ_COMPRAR_ANDYPOLIS:
        
        nuevo_objetivo = new ComprarAndypolis();
        break;
    case OBJ_CONSTRUCTOR:
        if(numero_jugador==1)
            nuevo_objetivo = new Constructor(edificios, mapa, jugador1);
        else
            nuevo_objetivo = new Constructor(edificios, mapa, jugador2);
        break;
    case OBJ_BOMBARDERO:
        nuevo_objetivo = new Bombardero();
        break;
    case OBJ_EDAD_PIEDRA:
        if(numero_jugador==1)
            nuevo_objetivo = new EdadDePiedra(jugador1);
        else
            nuevo_objetivo = new EdadDePiedra(jugador2);
        break;
    case OBJ_ENERGICO:
        if(numero_jugador==1)
            nuevo_objetivo = new Energetico(jugador1);
        else
            nuevo_objetivo = new Energetico(jugador2);
        break;
    case OBJ_LETRADO:
        if(numero_jugador==1)
            nuevo_objetivo = new Letrado(edificios, mapa, jugador1);
        else
            nuevo_objetivo = new Letrado(edificios, mapa, jugador2);
        break;
    case OBJ_MINERO:
        if(numero_jugador==1)
            nuevo_objetivo = new Minero(edificios, mapa, jugador1);
        else
            nuevo_objetivo = new Minero(edificios, mapa, jugador2);
        break;
    case OBJ_CANSADO:
        if(numero_jugador==1)
            nuevo_objetivo = new Cansado(jugador1);
        else
            nuevo_objetivo =  new Cansado(jugador2);
        break;
    case OBJ_ARMADO:
        if(numero_jugador==1)
            nuevo_objetivo = new Armado(jugador1);
        else
            nuevo_objetivo = new Armado(jugador2);
        break;
    case OBJ_EXTREMISTA:
        nuevo_objetivo = new Extremista();
        break;
    default:
        break;
    }
    return nuevo_objetivo;
}

void Menu::borrar_archivo_ubicaciones(){
    std::ofstream archivo;
    archivo.open("ubicaciones.txt");

    archivo << "1 (" << jugador1->devolver_coordenada_x() << ", " << jugador1->devolver_coordenada_y() << ")" << std::endl;
    archivo << "2 (" << jugador2->devolver_coordenada_x() << ", " << jugador2->devolver_coordenada_y() << ")" << std::endl;
    archivo.close();
}

void Menu::resetear_archivo_materiales(){
    std::ofstream archivo;
    archivo.open("materiales.txt");

    //jugador1->devolver_materiales()->devolver_cantidad()
    for (int i=0;i<jugador1->devolver_materiales()->devolver_cantidad();i++)
        archivo << jugador1->devolver_materiales()->consulta(i+1)->devolver_nombre() << " 0 0" << std::endl;
    archivo.close();
}