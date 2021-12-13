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
    this->energia = 2000;
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

/*
void Jugador::asignar_objetivos(ListaEdificios* edificios, Mapa * mapa) {
    int a=0;
    int b=0;
    int c=0;
    Utilidad util;

    while (a==b || b==c || a==c){
         a=util.generador_de_numeros_aleatorios(1,10);
         b=util.generador_de_numeros_aleatorios(1,10);
         c=util.generador_de_numeros_aleatorios(1,10);
    }
    std::cout << "aca" <<a<< std::endl;
    this->objetivo_2 = crear_objetivo(a, edificios, mapa);
    std::cout << "aca" <<b<< std::endl;
    this->objetivo_3 = crear_objetivo(b, edificios, mapa);
    std::cout << "aca" <<c<< std::endl;
    this->objetivo_4 = crear_objetivo(c, edificios, mapa);
    std::cout << "acaoleisco"<< std::endl;
    this->objetivo_1 = new Obelisco(edificios,mapa,this);
}
*/
/*
void Jugador::asignar_objetivos_aleatorios(ListaObjetivos vector_objetivos) {

    //this->objetivo_secundario = vector_objetivos;


}*/

/*
Objetivo* Jugador::crear_objetivo(int numero_objetivo, ListaEdificios * edificios, Mapa * mapa) {
    Objetivo* nuevo_objetivo=nullptr;
    switch (numero_objetivo){
    case OBJ_COMPRAR_ANDYPOLIS:
        nuevo_objetivo = new ComprarAndypolis();
        break;
    case OBJ_CONSTRUCTOR:
        nuevo_objetivo = new Constructor(edificios, mapa, this);
        break;
    case OBJ_BOMBARDERO:
        nuevo_objetivo = new Bombardero();
        break;
    case OBJ_EDAD_PIEDRA:
        nuevo_objetivo = new EdadDePiedra(this);
        break;
    case OBJ_ENERGICO:
        nuevo_objetivo = new Energetico(this);
        break;
    case OBJ_LETRADO:
        nuevo_objetivo = new Letrado(edificios, mapa, this);
        break;
    case OBJ_MINERO:
        nuevo_objetivo = new Minero(edificios, mapa, this);
        break;
    case OBJ_CANSADO:
        nuevo_objetivo = new Cansado(this);
        break;
    case OBJ_ARMADO:
        nuevo_objetivo = new Armado(this);
        break;
    case OBJ_EXTREMISTA:
        nuevo_objetivo = new Extremista();
        break;
    default:
        break;
    }
    return nuevo_objetivo;
}*/
/*
void Jugador::actualizar_objetivo(int numero_objetivo, int valor) {
   
    // if(this->objetivo_1->devolver_nombre() == LISTA_OBJETIVOS[numero_objetivo]) {
    //     this->objetivo_1->actualizar(valor);
    // } else if(this->objetivo_2->devolver_nombre() == LISTA_OBJETIVOS[numero_objetivo]) {
    //     this->objetivo_2->actualizar(valor);
    // } else if(this->objetivo_3->devolver_nombre() == LISTA_OBJETIVOS[numero_objetivo]) {
    //     this->objetivo_3->actualizar(valor);
    // } else if(this->objetivo_principal->devolver_nombre() == LISTA_OBJETIVOS[numero_objetivo]) {
    //     this->objetivo_principal->actualizar(valor);
    // }
}*/

/*
bool Jugador::ha_ganado(){

    bool gano = false;
    // if (cumplio_objetivo_principal()){
    //     gano = true;
    // } else if (cumplio_objetivo_secundario()){
    //     gano = true;
    // }

    return gano;
}

bool Jugador::cumplio_objetivo_principal() {

    return false;
}*/

/*
bool Jugador::cumplio_objetivo_secundario() {

    int i = 0;
    for (int j = 0; j < 3; ++j) {
        if (this->objetivo_secundario[j]->checkear()){
            i++;
        }
    }
    if (i >= 2)
        return true;
    else{
        return false;
    }
    //deberia hacer de la manera q una vez q se cumpla un objetivo secundario ya no lo chekea mas.
}
*/
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
    /*for (int i=0; i<3; i++){
        if(objetivo_secundario[i]->devolver_nombre()=="Extremista")
            objetivo_secundario[i]->actualizar(cantidad);
    }*/
    if (objetivo_2->devolver_nombre()=="Extremista")
        objetivo_2->actualizar(cantidad);
    else if (objetivo_3->devolver_nombre()=="Extremista")
        objetivo_3->actualizar(cantidad);
    else if (objetivo_4->devolver_nombre()=="Extremista")
        objetivo_4->actualizar(cantidad);
}

void Jugador::actualizar_bombas_usadas(){/*
    for (int i=0; i<3; i++){
        if(objetivo_secundario[i]->devolver_nombre()=="Bombardero")
            objetivo_secundario[i]->actualizar(1);
    }
    */
    if (objetivo_2->devolver_nombre()=="Bombardero")
        objetivo_2->actualizar(1);
    else if (objetivo_3->devolver_nombre()=="Bombardero")
        objetivo_3->actualizar(1);
    else if (objetivo_4->devolver_nombre()=="Bombardero")
        objetivo_4->actualizar(1);
}

void Jugador::actualizar_andycoins_juntadas(int cantidad){/*
    for (int i=0; i<3; i++){
        if(objetivo_secundario[i]->devolver_nombre()=="ComprarAndypolis")
            objetivo_secundario[i]->actualizar(cantidad);
    }*/
    if (objetivo_2->devolver_nombre()=="ComprarAndypolis")
        objetivo_2->actualizar(cantidad);
    else if (objetivo_3->devolver_nombre()=="ComprarAndypolis")
        objetivo_3->actualizar(cantidad);
    else if (objetivo_4->devolver_nombre()=="ComprarAndypolis")
        objetivo_4->actualizar(cantidad);
}

void Jugador::mostrar_objetivos(){/*
    this->objetivo_principal->mostrar();
    this->objetivo_secundario[0]->mostrar();
    this->objetivo_secundario[1]->mostrar();
    this->objetivo_secundario[2]->mostrar();

*/
    objetivo_1->mostrar();
    objetivo_2->mostrar();
    objetivo_3->mostrar();
    objetivo_4->mostrar();

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