#include "menu.h"
#include <iostream>
#include "mapa.h"
#include "arboledificios.h"
#include "listamateriales.h"
#include "mapa.h"
#include "jugador.h"
#include <fstream>


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

void procesar_opcion_menu(int opcion_elegida, /* ListaMateriales materiales, */ ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u){
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
            partida(edificios,mapa,j,u);
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
            mapa.construir(edificios,jugador,rival); 
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mapa.listar_edificios_construidos(edificios,jugador);
            break;
        case DEMOLER_EDIFICIO:
            mapa.menu_demoler(edificios,jugador); //solo podes demoler tus edificios y le devuelve los materiales al jugador
            break;
        case ATACAR_EDIFICIO:
            mapa.menu_atacar(jugador,rival);
            break;
        case REPARAR_EDIFICIO:
            mapa.menu_reparar(jugador);
            break;
        case COMPRAR_BOMBAS:
            jugador.comprar_bombas();
            break; 
        case CONSULTAR_COORDENADA:
            //se queda igual
            mapa.menu_consultar_coordenada();
            break;
        case MOSTRAR_INVENTARIO:
            // jugador.devolver_materiales()->mostrar();
            jugador.devolver_materiales().mostrar();
            break;
        case MOSTRAR_OBJETIVOS:
            //nuevo
            break;
        case RECOLECTAR_RECURSOS:
            mapa.recolectar(jugador);
            break;
        case MOVERSE:
            mapa.mover_jugador(jugador);
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

/*
void guardar(ListaMateriales materiales, ListaEdificios edificios, Mapa mapa){
    //REESCRIBIR ARCHIVOS
    materiales.reescribir_materiales();
    mapa.reescribir_ubicaciones();
    //DESTRUIR
    edificios.destruir();//teniamos un problema donde los destructores se activaban antes de salir, asi que hicimos destructores asi
    materiales.destruir();
    mapa.destruir();
}
*/

int generador_de_numeros_aleatorios(int min, int max){
    return min + rand()%(max+1-min);
}

void partida(ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u){
    int opcion=0;
    while(opcion!=GUARDAR_Y_SALIR_PARTIDA){
        while(opcion!=GUARDAR_Y_SALIR_PARTIDA && j.devolver_energia()!=0 && !u.ha_ganado()){
            mostrar_menu_partida();
            cin >> opcion;
            while(!es_opcion_valida(opcion,GUARDAR_Y_SALIR_PARTIDA)){
                cout<<"No es valida "<< endl;
                mostrar_menu_partida();
                cin >> opcion;
            }
            procesar_opcion_partida(opcion,edificios,mapa,j,u);
            //CHECKEAR SI TERMINO TODOS LOS OBJETIVOS
        }
        j.sumar_energia(20);
        opcion=corregir_opcion(opcion);
        while(opcion!=GUARDAR_Y_SALIR_PARTIDA && u.devolver_energia()!=0 && !j.ha_ganado()){
            mostrar_menu_partida();
            cin >> opcion;
            while(!es_opcion_valida(opcion,GUARDAR_Y_SALIR_PARTIDA)){
                cout<<"No es valida "<< endl;
                mostrar_menu_partida();
                cin >> opcion;
            }
            procesar_opcion_partida(opcion,edificios,mapa,u,j);
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
        edificio = edificios.consulta(nombre);

        if (edificio.devolver_maximos_permitidos()==0) {
            cout << "No se encontro el edificio ingresado. Intente de nuevo: ";
            cin >> nombre;

        } else {
            
            if (edificio.devolver_nombre() != "obelisco") {
                cout << "Se encontro el edificio " << edificio.devolver_nombre() << "." << endl;
                edificio.modificar_datos();
                edificios.cambiar_nodo(edificio);
            } else {
                cout << "No se puede cambiar los datos del obelisco." << endl;
            }

            resultado = true;
        }
    }
}

int diccionario_materiales(std::string material){
    if (material=="andycoin")
        return 250;
    if (material=="piedra")
        return 100;
    else
        return 50;
}

void procesar_archivo_materiales(ListaMateriales& j1, ListaMateriales& j2){
    std::string nombre,numero1,numero2;
    int num1 = 0, num2 = 0;

    std::ifstream archivo("materiales.txt"); //abro el archivo modo lectura

    if(!archivo.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo materiales" <<std::endl;
    }else{
        while(getline(archivo, nombre, ' ')) {
            getline(archivo, numero1, ' ');
            getline(archivo, numero2);
            Material material1(nombre,stoi(numero1));
            Material material2(nombre,stoi(numero2));
            j1.alta(material1);
            j2.alta(material2);
        }
    
    archivo.close();
    }
}
