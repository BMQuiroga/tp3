#include "jugador.h"
#include <iostream>
#include "grafomapa.h"
#include "utilidad.h"
#include "mapa.h"
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

Jugador::Jugador() {}

Jugador::Jugador(int x,int y,int numero, ListaEdificios* edificios, Mapa * mapa){
    //std::cout<<"Nombre"<<std::endl;
    mover_gratis(x,y);
    this->energia = 50;
    this->nombre = numero;
    this->crear_grafo(mapa);
    //this->asignar_objetivos(edificios, mapa);
}

Jugador::~Jugador() {
    delete grafo;
}

void Jugador::crear_grafo(Mapa * mapa) {
    this->grafo = new GrafoMapa(this, mapa);
}

void Jugador::mover_gratis(int x, int y){
    this->coordenada_x = x;
    this->coordenada_y = y;
}


void Jugador::mover_jugador(Mapa* mapa, Jugador* rival) {
    Utilidad util;
    int destino_x, destino_y;

    // ESTO ES UN WHILE HASTA QUE PONGA QUE QUIERE TERMINAR

    std::cout << "Ingrese el casillero de destino" << std::endl; 
    destino_x = mapa->pedir_fila();
    destino_y = mapa->pedir_columna();                          std::cout << std::endl;

    int costo = grafo->devolver_costo(this->coordenada_x, this->coordenada_y, destino_x, destino_y);
    
    bool recorrido_valido = (grafo->es_recorrido_valido(this->coordenada_x, this->coordenada_y, destino_x, destino_y, costo)) &&
                            (rival->devolver_coordenada_x() != destino_x && rival->devolver_coordenada_y() != destino_y); 

    if (recorrido_valido) {
        std::cout << "Hacer este recorrido cuesta " << costo << " de energia." << std::endl;
        std::cout << "Tenes " << devolver_energia() << " de energia." << std::endl;

        if (devolver_energia() >= costo) {
            if (util.pedir_confirmacion()) {
                ListaRecorrido* recorrido = grafo->mover_jugador(this->coordenada_x, this->coordenada_y, destino_x, destino_y);
                mapa->mostrar_recorrido(recorrido, this);
                restar_energia(costo);
                mover_gratis(destino_x, destino_y);
            } else {
                std::cout << "Operacion cancelada." << std::endl;
            }
        } else {
            std::cout << "No tenes energia suficiente." << std::endl;
        }
    } else {
        std::cout << "No podes moverte a la coordenada ingresada." << std::endl;
    }

    std::cout << std::endl; 
}


int Jugador::devolver_energia(){
    return this->energia;
}

void Jugador::comprar_bombas(){
    Utilidad util;
    int indice=this->materiales->buscar_indice("andycoins");
    int cantidad_andycoins = this->materiales->consulta(indice)->devolver_cantidad();
    std::string bombas;
    
    if (cantidad_andycoins / 100 >= 1) {
        std::cout<<"Posee "<< cantidad_andycoins <<" andycoins, cuantas bombas desea comprar?"<<std::endl;
        std::cin>>bombas;

        while(util.convertir_a_entero(bombas) > cantidad_andycoins / 100){ // falta el caso de que bombas sea string creo
            std::cout<<"No alcanzan las andycoins, inserte un numero valido: "<<std::endl;
            std::cin>>bombas; 
        }

        if(util.pedir_confirmacion()) {
            if (util.convertir_a_entero(bombas) == 1)   std::cout << "Compraste " << bombas << " bomba." << std::endl;
            else                                        std::cout << "Compraste " << bombas << " bombas" << std::endl;

            this->materiales->obtener_nodo(materiales->buscar_indice("bombas"))->obtener_dato()->operator+(util.convertir_a_entero(bombas));
            this->materiales->obtener_nodo(materiales->buscar_indice("andycoins"))->obtener_dato()->operator-(util.convertir_a_entero(bombas) * 100);
            actualizar_bombas_compradas(util.convertir_a_entero(bombas));    //tirA SEG FAULT
            this->energia-=5;
        } else {
            std::cout << "Compra cancelada" << std::endl;
        }
    } else {
        std::cout << "No tenes andycoins para comprar bombas." << endl;
    }
}


ListaMateriales* Jugador::devolver_materiales(){
    return this->materiales;
}



int Jugador::devolver_nombre(){
    return this->nombre;
}

int Jugador::devolver_coordenada_x(){
    return this->coordenada_x;
}

int Jugador::devolver_coordenada_y(){
    return this->coordenada_y;
}

/*bool Jugador::checkear_objetivos(){
    return((objetivo_1->checkear() && objetivo_2->checkear()) ||
           (objetivo_2->checkear() && objetivo_3->checkear()) ||
           (objetivo_1->checkear() && objetivo_3->checkear()) ||
           (objetivo_principal->checkear()));
}*/

void Jugador::asignar_lista_materiales(ListaMateriales *materiales){
    this->materiales = materiales;
}

void Jugador::sumar_energia(int numero){
    this->energia+=numero;
}

void Jugador::restar_energia(int numero){
    this->energia-=numero;
}

void Jugador::destruir(){
    this->materiales->destruir();
    //ACA SE DESTRUYEN LOS OBJETIVOS EN MEMORIA DINAMICA
    //YES SIR
    delete this->objetivo_1;
    delete this->objetivo_2;
    delete this->objetivo_3;
    delete this->objetivo_4;
}


void Jugador::actualizar_bombas_compradas(int cantidad){
    //std::cout << objetivo_2->devolver_nombre() << objetivo_3->devolver_nombre() << objetivo_4->devolver_nombre() << std::endl;
    if (objetivo_2->devolver_nombre()=="Extremista")
        objetivo_2->actualizar(cantidad);
    else if (objetivo_3->devolver_nombre()=="Extremista")
        objetivo_3->actualizar(cantidad);
    else if (objetivo_4->devolver_nombre()=="Extremista")
        objetivo_4->actualizar(cantidad);
}

void Jugador::actualizar_bombas_usadas(){
    //std::cout << objetivo_2->devolver_nombre() << objetivo_3->devolver_nombre() << objetivo_4->devolver_nombre() << std::endl;
    if (objetivo_2->devolver_nombre()=="Bombardero")
        objetivo_2->actualizar(1);
    else if (objetivo_3->devolver_nombre()=="Bombardero")
        objetivo_3->actualizar(1);
    else if (objetivo_4->devolver_nombre()=="Bombardero")
        objetivo_4->actualizar(1);
}

void Jugador::actualizar_andycoins_juntadas(int cantidad){
    //std::cout << objetivo_2->devolver_nombre() << objetivo_3->devolver_nombre() << objetivo_4->devolver_nombre() << std::endl;
    if (objetivo_2->devolver_nombre()=="ComprarAndypolis")
        objetivo_2->actualizar(cantidad);
    else if (objetivo_3->devolver_nombre()=="ComprarAndypolis")
        objetivo_3->actualizar(cantidad);
    else if (objetivo_4->devolver_nombre()=="ComprarAndypolis")
        objetivo_4->actualizar(cantidad);
}

void Jugador::mostrar_objetivos(){
    std::cout<<"---------------------------------------"<<std::endl;
    objetivo_1->mostrar();
    std::cout<<"---------------------------------------"<<std::endl;
    objetivo_2->mostrar();
    std::cout<<"---------------------------------------"<<std::endl;
    objetivo_3->mostrar();
    std::cout<<"---------------------------------------"<<std::endl;
    objetivo_4->mostrar();
    std::cout<<"---------------------------------------"<<std::endl;

}

bool Jugador::checkear_objetivos(){
    objetivo_1->calcular_progreso();
    objetivo_2->calcular_progreso();
    objetivo_3->calcular_progreso();
    objetivo_4->calcular_progreso();
    bool obj1, obj2, obj3, obj4;
    obj1=objetivo_1->checkear();
    obj2=objetivo_2->checkear();
    obj3=objetivo_3->checkear();
    obj4=objetivo_4->checkear();
    return( obj1 || (obj2 && obj3) || (obj2 && obj4) || (obj3 && obj4) );
}

void Jugador::asignar_objetivo_1(Objetivo * objetivo){
    this->objetivo_1 = objetivo;
}

void Jugador::asignar_objetivo_2(Objetivo * objetivo){
    this->objetivo_2 = objetivo;
}

void Jugador::asignar_objetivo_3(Objetivo * objetivo){
    this->objetivo_3 = objetivo;
}

void Jugador::asignar_objetivo_4(Objetivo * objetivo){
    this->objetivo_4 = objetivo;
}