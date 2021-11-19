#ifndef MAPA_H
#define MAPA_H

#include "casillero_construible.h"
#include "casillero_transitable.h"
#include "casillero_inaccesible.h"
#include "edificio.h"
#include "material.h"
#include "listaedificios.h"
#include "listamateriales.h"
#include "jugador.h"
#include <string>


class Mapa{

//Atributos
private:
    int coordenada_x,coordenada_y;
    //CasilleroConstruible **matriz_terreno=nullptr;
    //CasilleroTransitable **matriz_camino=nullptr;
    //Casillero **matriz = new Casillero*[50];//=nullptr;
    //Casillero **matriz;
    Casillero ***matriz;

//Metodos
public:

    //Pre: Recibe la lista de edificios.
    //Post: Procesa los archivos mapa.txt y ubicaciones.txt
    Mapa(ListaEdificios edificios);

    //Pre: Recibe la cantidad de filas y la cant de columnas
    //Post: Pide memoria para cada casillero de la matriz
    void definir(int coordenada_x,int coordenada_y);

    //Pre: Recibe la lista de materiales
    //Post: Recolecta los materiales que produjeron los edifcios construidos
    void recolectar(Jugador jugador);

    //Pre:
    //Post:
    void graficar();

    //Pre:
    //Post:Para la cantidad de materiales genera numeros random 
    //     piedra(entre 1 y 2)
    //     madera(entre 0 y 1)
    //     metal(entre 2 y 4)
    void llamar_lluvia();

    //Pre:-
    //Post:Muestra por pantalla el mapa con su tipo de casillero
    void mostrar_mapa(Jugador jugador1, Jugador jugador2);

    //Pre:Recibe la lista de edificios y materiales
    //Post:Solicita al usuario el nombre del edificio que desea construir, y si es valida y no esta ninguno de los jugadores en el caasillero pide las coordenadas
    void construir(ListaEdificios edificios,Jugador jugador,Jugador rival);

    //Pre:NO LA USAMOS(LA TENEMOS COMENTADA EN EL .CPP)
    //Post:
    int devolver_indice_edificios(Edificio edificios[],std::string nombre);

    //Pre:NO LA USAMOS(LA TENEMOS COMENTADA EN EL .CPP)
    //Post:
    int devolver_indice_materiales(Material materiales[],std::string nombre);

    //Pre: Recibe una lista de edificios
    //Post:Muestra por pantalla los edificios con cant>0, el nombre, cant construida y sus coordenadas
    void listar_edificios_construidos(ListaEdificios edificios, Jugador jugadores);

    //Pre:-
    //Post:Solicita al usuario que ingrese las coordenadas, y muestra lo que hay en esa posicion
    void menu_consultar_coordenada();

    //Pre:Recibe la lista de materiales
    //Post:Solicita al usuario que ingrese las coordenadas y si es valido lo destruye
    void menu_demoler(ListaEdificios edificios, Jugador jugador);

    //Pre:Recibe las lista de edificios
    //Post:Muestra por pantalla todos los edificios(nombre, cuanto material se requiere, cant construidos y cuantos se pueden construir)
    void listar_todos_los_edificios(ListaEdificios edificios, Jugador jugador1, Jugador jugador2);

    //Pre:-
    //Post:Libera memoria 
    void destruir();

    //Pre:-
    //Post:Guarda los cambios en ubicaciones.txt
    void reescribir_ubicaciones();

    void menu_atacar(Jugador jugador, Jugador rival);

    void menu_reparar(Jugador jugador);

private:
    
    //Pre:-
    //Post:Verifica que exista el archivo mapa.txt y los carga en una matriz
    void procesar_archivo_mapa();

    //Pre:Recibe la lista de edificios
    //Post:Verifica que exista el archivo ubicaciones.txt y los carga en una matriz
    //void procesar_archivo_ubicaciones(ListaEdificios edificios);

    //Pre: Recibe la cantidad aleatoria y el nombre del material
    //Post:posiciona en forma aleatoria el material en el tipo de casillero Camino
    void lluvia(int cantidad, std::string material);

    //Pre:Recibe 2 coordenadas y la lista de materiales
    //Post:Evalua si hay edificio para demoler, destruyendolo y sumando la mitad de los materiales
    void demoler(ListaEdificios edificios, int coord_x,int coord_y,Jugador jugador);

    //Pre: Recibe coordenadas
    //Post: imprime un caracter, usado en la funcion mostrar mapa
    void mostrar_mapa_edificios_y_materiales(int coord_x, int coord_y, Jugador jugador1, Jugador jugador2);

    //Pre:Recibe la lista de edificios, materiales y el nombre del edificio
    //Post:Verifica que haya la cantidad suficiente de materiales para poder construir
    bool se_puede_construir(ListaEdificios edificios,std::string nombre,Jugador jugador);

    //Pre:Recibe la lista de edificios y materiales,el nombre del edifiio y el posicion del edificio
    //Post:Resta la cantidad de materiales que se usara en la construccion
    void realizar_construccion(ListaEdificios edificios,int coord_x, int coord_y, std::string nombre, int indice_edificio, Jugador jugador);

    //Pre:Recibe el nombre del edificio
    //Post:Devuelve las coordanas del nombre ingresado
    void mostrar_coordenadas(std::string nombre,Jugador jugador);

     //Pre:Recibe 2 coordenadas 
    //Post:Muestra por pantalla el nombre, tipo de casillero y si se encuentra vacio o no
    void consultar_coordenadas(int coordenada_x,int coordenada_y);
    
    bool procesar_archivo_ubicaciones(ListaEdificios edificios,Jugador j, Jugador u);

    //Pre:Recibe el nombre del edificio
    //Post:Devuelve la cantidad de edificios construidos
    int edificios_construidos(std::string nombre, Jugador jugador);

    bool casillero_ocupado(Jugador jugador, int coord_x, int coord_y);
};


#endif 