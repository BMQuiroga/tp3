#include "menu.h"
#include "jugador.h"
#include "ideas1.h"
#include <iostream>
#include <fstream>

//NO ADAPTADO A EDIFICIOS COMO ARBOL BINARIO
//ES UN DESASTRE DE 65 LINEAS
bool Mapa::procesar_archivo_ubicaciones(ListaEdificios edificios,Jugador j, Jugador u){
    std::string nombre;
    int coord_x;
    int coord_y;
    std::string aux;
    bool archivo_en_blanco;
    std::ifstream archivo_ubicaciones("ubicaciones.txt",std::ios::in);
    if(!archivo_ubicaciones)
        return true;
    else{
        while((archivo_ubicaciones>>nombre)){//no puedo poner el and porque esta condicion no es un bool, asi que va con breaks
            archivo_en_blanco=false;
            if (nombre=="1"){
                getline(archivo_ubicaciones,aux,'(');
                archivo_ubicaciones>>aux;
                coord_x=stoi(aux);
                archivo_ubicaciones>>aux;
                coord_y=stoi(aux);
                j.mover_gratis(coord_x,coord_y);
                break;
            }
            getline(archivo_ubicaciones,aux,'(');
            archivo_ubicaciones>>aux;
            coord_x=stoi(aux);
            archivo_ubicaciones>>aux;
            coord_y=stoi(aux);
            Material material(nombre,diccionario_materiales(nombre));
            matriz[coord_x][coord_y]->poner_material(material);
        }
        while (archivo_ubicaciones>>nombre){
            if (nombre=="planta"){
                archivo_ubicaciones>>nombre;
                nombre="planta electrica";
            }
            if (nombre=="2"){
                getline(archivo_ubicaciones,aux,'(');
                archivo_ubicaciones>>aux;
                coord_x=stoi(aux);
                archivo_ubicaciones>>aux;
                coord_y=stoi(aux);
                u.mover_gratis(coord_x,coord_y);
                break;
            }
            getline(archivo_ubicaciones,aux,'(');
            if (aux=="oro ("){
                nombre="mina oro";
            }
            archivo_ubicaciones>>aux;
            coord_x=stoi(aux);
            archivo_ubicaciones>>aux;
            coord_y=stoi(aux);
            int indice=edificios.buscar_indice(nombre);
            matriz[coord_x][coord_y]->construir(edificios.consulta(indice));
            matriz[coord_x][coord_y]->cambiar_jugador(1);
        }
        while (archivo_ubicaciones>>nombre){
            if (nombre=="planta"){
                archivo_ubicaciones>>nombre;
                nombre="planta electrica";
            }
            getline(archivo_ubicaciones,aux,'(');
            if (aux=="oro ("){
                nombre="mina oro";
            }
            archivo_ubicaciones>>aux;
            coord_x=stoi(aux);
            archivo_ubicaciones>>aux;
            coord_y=stoi(aux);
            int indice=edificios.buscar_indice(nombre);
            matriz[coord_x][coord_y]->construir(edificios.consulta(indice));
            matriz[coord_x][coord_y]->cambiar_jugador(2);
        }
    archivo_ubicaciones.close();
    }
    return archivo_en_blanco;
}

int diccionario_materiales(std::string material){
    if (material=="andycoin")
        return 250;
    if (material=="piedra")
        return 100;
    else
        return 50;
}

void procesar_archivo_materiales(Jugador j, Jugador u){
    std::string nombre,numero1,numero2;
    int num1 = 0, num2 = 0;

    ListaMateriales materiales1;
    ListaMateriales materiales2;

    std::ifstream archivo("materiales.txt"); //abro el archivo modo lectura

    if(!archivo.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo materiales" <<std::endl;
    }else{
        while(archivo >> nombre){ //voy guardando hasta un espacio
            archivo>>numero1;
            num1=stoi(numero1);
            archivo>>numero2;
            num2=stoi(numero2);
            Material material1(nombre,num1);
            Material material2(nombre,num2);
            materiales1.alta(material1,materiales1.devolver_cantidad());
            materiales2.alta(material2,materiales2.devolver_cantidad());
        }
    archivo.close();
    j.asignar_lista_materiales(materiales1);
    u.asignar_lista_materiales(materiales2);
    }
}

