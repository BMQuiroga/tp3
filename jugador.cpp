#include "jugador.h"
#include <iostream>

Jugador::Jugador(int x,int y,int numero, ListaEdificios edificios, ListaMateriales materiales, Mapa mapa){
    mover_gratis(x,y);
    this->energia=50;
    this->nombre=numero;
    this->asignar_objetivos(edificios, materiales, mapa, *this);
}

void Jugador::mover_gratis(int x, int y){
    this->coordenada_x=x;
    this->coordenada_y=y;
}

int Jugador::devolver_energia(){
    return this->energia;
}

void Jugador::comprar_bombas(){
    int indice=this->materiales.buscar_indice("andycoins");
    int cantidad_andycoins = this->materiales.consulta(indice).devolver_cantidad();
    int bombas=0;
    std::cout<<"Posee "<< cantidad_andycoins <<" andycoins, cuantas bombas desea comprar?"<<std::endl;
    std::cin>>bombas;

    while(bombas>cantidad_andycoins/100){ // falta el caso de que bombas sea string creo
        std::cout<<"No alcanzan las andycoins, inserte un numero valido"<<std::endl;
        std::cin>>bombas; 
    }

    this->actualizar_objetivo(OBJ_COMPRAR_ANDYPOLIS, bombas * 100);
    this->materiales.obtener_nodo(materiales.buscar_indice("bombas"))->obtener_dato().operator+(bombas);
    this->materiales.obtener_nodo(materiales.buscar_indice("andycoins"))->obtener_dato().operator-(bombas*100);
    this->energia-=5;

}

// ListaMateriales* Jugador::devolver_materiales(){
//     return this->materiales;
// }

ListaMateriales Jugador::devolver_materiales() {
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

void Jugador::asignar_lista_materiales(ListaMateriales materiales){
    this->materiales=materiales;
}

void Jugador::sumar_energia(int numero){
    this->energia+=numero;
}

void Jugador::restar_energia(int numero){
    this->energia-=numero;
}


void Jugador::asignar_objetivos(ListaEdificios edificios, ListaMateriales materiales, Mapa mapa, Jugador jugador) {
    int a=0;
    int b=0;
    int c=0;

    while (a==b || b==c || a==c){
        a=generador_de_numeros_aleatorios(1,11);
        b=generador_de_numeros_aleatorios(1,11);
        c=generador_de_numeros_aleatorios(1,11);
    }
    
    this->objetivo_1 = crear_objetivo(a, edificios, materiales, mapa, jugador);
    this->objetivo_2 = crear_objetivo(b, edificios, materiales, mapa, jugador);
    this->objetivo_3 = crear_objetivo(c, edificios, materiales, mapa, jugador);
    this->objetivo_principal = crear_objetivo(OBJ_OBELISCO, edificios, materiales, mapa, jugador);
}

Objetivo* Jugador::crear_objetivo(int numero_objetivo, ListaEdificios edificios, ListaMateriales materiales, Mapa mapa, Jugador jugador) {
    Objetivo* nuevo_objetivo;

    switch (numero_objetivo)
    {
    case OBJ_COMPRAR_ANDYPOLIS:
        nuevo_objetivo = new Comprar_Andypolis();
        break;
    case OBJ_CONSTRUCTOR:
        nuevo_objetivo = new Constructor(edificios, mapa, jugador);
        break;
    case OBJ_BOMBARDERO:
        nuevo_objetivo = new Bombardero();
        break;
    case OBJ_EDAD_PIEDRA:
        nuevo_objetivo = new Edad_De_Piedra(materiales);
        break;
    case OBJ_ENERGICO:
        nuevo_objetivo = new Energetico(jugador);
        break;
    case OBJ_LETRADO:
        nuevo_objetivo = new Letrado(edificios, mapa, jugador);
        break;
    case OBJ_MINERO:
        nuevo_objetivo = new Minero(edificios, mapa, jugador);
        break;
    case OBJ_CANSADO:
        nuevo_objetivo = new Cansado(jugador);
        break;
    case OBJ_ARMADO:
        nuevo_objetivo = new Armado(materiales);
        break;
    case OBJ_EXTREMISTA:
        nuevo_objetivo = new Extremista();
        break;
    case OBJ_OBELISCO:
        nuevo_objetivo = new Principal(mapa, jugador);
        break;
    default:
        break;
    }
}

void Jugador::actualizar_objetivo(int numero_objetivo, int valor) {
   
    if(this->objetivo_1->devolver_nombre() == LISTA_OBJETIVOS[numero_objetivo]) {
        this->objetivo_1->actualizar(valor);
    } else if(this->objetivo_2->devolver_nombre() == LISTA_OBJETIVOS[numero_objetivo]) {
        this->objetivo_2->actualizar(valor);
    } else if(this->objetivo_3->devolver_nombre() == LISTA_OBJETIVOS[numero_objetivo]) {
        this->objetivo_3->actualizar(valor);
    } else if(this->objetivo_principal->devolver_nombre() == LISTA_OBJETIVOS[numero_objetivo]) {
        this->objetivo_principal->actualizar(valor);
    }
}

