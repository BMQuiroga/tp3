#include <iostream>
#include "menu_objeto.h"
#include <fstream>


void Menu::guardar(){
    //edificios.reescribir();
    reescribir_materiales();
    mapa.reescribir_ubicaciones(jugador1,jugador2);
    edificios.destruir();
    mapa.destruir();
    jugador1.destruir();
    jugador2.destruir();
}


void Menu::mostrar_menu(){
    cout << "1. Modificar edificio por nombre"<<endl;
    cout << "2. Listar todos los edificios"<<endl;
    cout << "3. Mostrar mapa"<<endl;
    cout << "4. Comenzar partida"<<endl;
    cout << "5. Guardar y salír"<<endl;
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
    cout << "13. Guardar y salír"<<endl;
}

void Menu::partida(ListaEdificios edificios, Mapa mapa, Jugador j, Jugador u){
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
            procesar_opcion_partida(opcion,j,u);
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
            procesar_opcion_partida(opcion,u,j);
            //CHECKEAR SI TERMINO TODOS LOS OBJETIVOS
        }
        u.sumar_energia(20);
        //llamar lluvia recursos
        opcion=corregir_opcion(opcion);
    }


}

void Menu::procesar_opcion_menu(int opcion_elegida){
    system(CLR_SCREEN);
    switch(opcion_elegida){
        case MODIFICAR_EDIFICIO:
            //no esta testeado
            modificar_datos_edificio(edificios);
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            mapa.listar_todos_los_edificios(edificios,jugador1,jugador2);
            break;
        case MOSTRAR_MAPA:
            mapa.mostrar_mapa(jugador1,jugador2);
            break;
        case COMENZAR_PARTIDA:
            partida(edificios,mapa,jugador1,jugador2);
            break;
        case GUARDAR_Y_SALIR_MENU:
            //falta
            break;
    }

}

void Menu::procesar_opcion_partida(int opcion_elegida, Jugador jugador, Jugador rival){
    system(CLR_SCREEN);
    switch(opcion_elegida){
        case CONSTRUIR_EDIFICIO:
            mapa.construir(edificios,jugador,rival); 
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mapa.listar_edificios_construidos(edificios,jugador);
            break;
        case DEMOLER_EDIFICIO:
            mapa.menu_demoler(edificios,jugador);
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
            mapa.menu_consultar_coordenada();
            break;
        case MOSTRAR_INVENTARIO:
            jugador.devolver_materiales().mostrar();
            break;
        case MOSTRAR_OBJETIVOS:
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
            guardar();
            break;
        default:
        cout<< "Error: opcion invalida";
    }
}

void Menu::reescribir_materiales(){
    ofstream archivo_materiales;
    archivo_materiales.open("materiales.txt");

    if(!archivo_materiales.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo materiales" <<std::endl;
    }else{
        for (int i=0 ; i<this->jugador1.devolver_materiales().devolver_cantidad() ; i++){
            //std::cout<<this->consulta(i+1).devolver_nombre()<<std::endl;
            archivo_materiales<<this->jugador1.devolver_materiales().consulta(i+1).devolver_nombre();
            archivo_materiales<<" ";
            archivo_materiales<<this->jugador1.devolver_materiales().consulta(i+1).devolver_cantidad();
            archivo_materiales<<" ";
            archivo_materiales<<this->jugador2.devolver_materiales().consulta(i+1).devolver_cantidad();
            archivo_materiales<<std::endl;
        }
    archivo_materiales.close();
    }
}
