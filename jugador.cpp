#include "jugador.h"
#include <iostream>
#include "grafomapa.h"
#include "utilidad.h"
#include "mapa.h"

Jugador::Jugador() {}

Jugador::Jugador(int x,int y,int numero, ListaEdificios* edificios, Mapa * mapa){
    //std::cout<<"Nombre"<<std::endl;
    mover_gratis(x,y);
    this->energia = 2000;
    this->nombre = numero;
    this->crear_grafo(mapa);
    this->asignar_objetivos(edificios, materiales, mapa, this);
}

Jugador::~Jugador() {
    // delete grafo;
}

void Jugador::crear_grafo(Mapa * mapa) {
    this->grafo = new GrafoMapa(this, mapa);
}

void Jugador::mover_gratis(int x, int y){
    this->coordenada_x = x;
    this->coordenada_y = y;
}


void Jugador::mover_jugador(Mapa* mapa) {
    Utilidad util;
    int destino_x, destino_y;

    // ESTO ES UN WHILE HASTA QUE PONGA QUE QUIERE TERMINAR

    std::cout << "Ingrese el casillero de destino" << std::endl; 
    destino_x = mapa->pedir_fila();
    destino_y = mapa->pedir_columna();                          std::cout << std::endl;

    int costo = grafo->devolver_costo(this->coordenada_x, this->coordenada_y, destino_x, destino_y);
    bool recorrido_valido = grafo->es_recorrido_valido(this->coordenada_x, this->coordenada_y, destino_x, destino_y, costo);

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

        // this->actualizar_objetivo(OBJ_COMPRAR_ANDYPOLIS, bombas * 100);
        this->materiales->obtener_nodo(materiales->buscar_indice("bombas"))->obtener_dato()->operator+(util.convertir_a_entero(bombas));
        this->materiales->obtener_nodo(materiales->buscar_indice("andycoins"))->obtener_dato()->operator-(util.convertir_a_entero(bombas) * 100);
        //actualizar_bombas_compradas(bombas);    //tirA SEG FAULT
        this->energia-=5;
    } else {
        std::cout << "Compra cancelada" << std::endl;
    }


}


// void Jugador::operacion_bombas(int valor) {
//     this->materiales->obtener_nodo(materiales->buscar_indice("bombas"))->obtener_dato().operator+(valor);

// }

GrafoMapa* Jugador::movimiento() {
    return grafo;
}

ListaMateriales* Jugador::devolver_materiales(){
    return this->materiales;
}

// ListaMateriales Jugador::devolver_materiales() {
//     return this->materiales;
// }

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


void Jugador::asignar_objetivos(ListaEdificios* edificios, ListaMateriales* materiales, Mapa * mapa, Jugador* jugador) {
    //int a=0;
    //int b=0;
    //int c=0;

    //while (a==b || b==c || a==c){
    //     a=generador_de_numeros_aleatorios(1,10);
    //     b=generador_de_numeros_aleatorios(1,10);
    //     c=generador_de_numeros_aleatorios(1,10);
    // }
    
    // this->objetivo_1 = crear_objetivo(a, edificios, materiales, mapa, jugador);
    // this->objetivo_2 = crear_objetivo(b, edificios, materiales, mapa, jugador);
    // this->objetivo_3 = crear_objetivo(c, edificios, materiales, mapa, jugador);
    // this->objetivo_principal = crear_objetivo(OBJ_OBELISCO, edificios, materiales, mapa, jugador);
}


void Jugador::asignar_objetivos_aleatorios(ListaObjetivos vector_objetivos) {

    //this->objetivo_secundario = vector_objetivos;


}


// Objetivo* Jugador::crear_objetivo(int numero_objetivo, ListaEdificios edificios, ListaMateriales materiales, Mapa * mapa, Jugador jugador) {
//     Objetivo** nuevo_objetivo = new Objetivo*;
//     return nuevo_objetivo; // hay que cambiarlo, es para que no tire warning
//     // switch (numero_objetivo)
//     // {
//     // case OBJ_COMPRAR_ANDYPOLIS:
//     //     nuevo_objetivo = new Comprar_Andypolis();
//     //     break;
//     // case OBJ_CONSTRUCTOR:
//     //     nuevo_objetivo = new Constructor(edificios, mapa, jugador);
//     //     break;
//     // case OBJ_BOMBARDERO:
//     //     nuevo_objetivo = new Bombardero();
//     //     break;
//     // case OBJ_EDAD_PIEDRA:
//     //     nuevo_objetivo = new Edad_De_Piedra(materiales);
//     //     break;
//     // case OBJ_ENERGICO:
//     //     nuevo_objetivo = new Energetico(jugador);
//     //     break;
//     // case OBJ_LETRADO:
//     //     nuevo_objetivo = new Letrado(edificios, mapa, jugador);
//     //     break;
//     // case OBJ_MINERO:
//     //     nuevo_objetivo = new Minero(edificios, mapa, jugador);
//     //     break;
//     // case OBJ_CANSADO:
//     //     nuevo_objetivo = new Cansado(jugador);
//     //     break;
//     // case OBJ_ARMADO:
//     //     nuevo_objetivo = new Armado(materiales);
//     //     break;
//     // case OBJ_EXTREMISTA:
//     //     nuevo_objetivo = new Extremista();
//     //     break;
//     // case OBJ_OBELISCO:
//     //     nuevo_objetivo = new Principal(mapa, jugador);
//     //     break;
//     // default:
//     //     break;
//     // }
// }

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
}


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
}

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

void Jugador::destruir(){
    this->materiales->destruir();
    //ACA SE DESTRUYEN LOS OBJETIVOS EN MEMORIA DINAMICA
}


void Jugador::actualizar_bombas_compradas(int cantidad){
    for (int i=0; i<3; i++){
        if(objetivo_secundario[i]->devolver_nombre()=="Extremista")
            objetivo_secundario[i]->actualizar(cantidad);
    }

}

void Jugador::actualizar_bombas_usadas(){
    for (int i=0; i<3; i++){
        if(objetivo_secundario[i]->devolver_nombre()=="Bombardero")
            objetivo_secundario[i]->actualizar(1);
    }

}

void Jugador::actualizar_andycoins_juntadas(int cantidad){
    for (int i=0; i<3; i++){
        if(objetivo_secundario[i]->devolver_nombre()=="ComprarAndypolis")
            objetivo_secundario[i]->actualizar(cantidad);
    }
}

void Jugador::mostrar_objetivos(){
    this->objetivo_principal->mostrar();
    this->objetivo_secundario[0]->mostrar();
    this->objetivo_secundario[1]->mostrar();
    this->objetivo_secundario[2]->mostrar();


}