#include "objetivo.h"
#include "mapa.h"

const int OBJ_COMPRAR_ANDYPOLIS = 1;
const int OBJ_EDAD_PIEDRA = 2;
const int OBJ_BOMBARDERO = 3;
const int OBJ_ENERGICO = 4;
const int OBJ_LETRADO = 5;
const int OBJ_MINERO = 6;
const int OBJ_CANSADO = 7;
const int OBJ_CONSTRUCTOR = 8;
const int OBJ_ARMADO = 9;
const int OBJ_EXTREMISTA = 10;
const int OBJ_OBELISCO = 11;

std::string LISTA_OBJETIVOS [11] = { // NO CAMBIAR DE ORDEN
    "Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida",
    "Edad de piedra: tener en el inventario 50000 piedras",
    "Bombardero: haber usado 5 bombas.",
    "Energético: haber terminado un turno con 100 puntos de energía.",
    "Letrado: haber construido el máximo posible de escuelas.",
    "Minero: haber construido una mina de cada tipo.",
    "Cansado: terminar un turno con 0 de energía.",
    "Constructor: construir un edificio de cada tipo.",
    "Armado: tener 10 bombas en el inventario.",
    "Extremista: haber comprado 500 bombas en una partida."
    "Más alto que las nubes: construir el obelisco.",
};


void Objetivo::mostrar() {
    std::cout << this->nombre << " ------> ( " << calcular_progreso() << " / " << objetivo << " )" << std::endl;
}

std::string Objetivo::devolver_nombre() {
    return this->nombre;
}


Comprar_Andypolis::Comprar_Andypolis() {
    this->nombre = LISTA_OBJETIVOS[OBJ_COMPRAR_ANDYPOLIS];
    this->progreso = 0;
    this->objetivo = 100000;
}

Edad_De_Piedra::Edad_De_Piedra(ListaMateriales materiales) {
    this->nombre = LISTA_OBJETIVOS[OBJ_EDAD_PIEDRA];
    this->materiales = materiales;
    this->progreso = 0;
    this->objetivo = 50000;
}

Bombardero::Bombardero() {
    this->nombre = LISTA_OBJETIVOS[OBJ_BOMBARDERO];
    this->progreso = 0;
    this->objetivo = 5;
}

Energetico::Energetico(Jugador * jugador) {
    this->nombre = LISTA_OBJETIVOS[OBJ_ENERGICO];
    this->jugador = jugador;
    this->progreso = 0;
    this->objetivo = 100;
}

Cansado::Cansado(Jugador * jugador) {
    this->nombre = LISTA_OBJETIVOS[OBJ_CANSADO];
    this->jugador = jugador;
    this->progreso = 1;
    this->objetivo = 0;
}

Letrado::Letrado(ListaEdificios edificios, Mapa * mapa, Jugador * jugador) {
    //revisar: pasar el numero de escuela como parametro
    this->nombre = LISTA_OBJETIVOS[OBJ_LETRADO];
    this->edificios = edificios;
    this->mapa = mapa;
    this->jugador = jugador;
    this->progreso = 0;
    this->objetivo = edificios.consulta("escuela").devolver_maximos_permitidos();  // cambiar para arbol binario
}

Minero::Minero(ListaEdificios edificios, Mapa * mapa, Jugador * jugador) {
    int cantidad_minas = 2;     // hay dos tipos de mina por ahora
    this->nombre = LISTA_OBJETIVOS[OBJ_MINERO];
    this->edificios = edificios;
    this->mapa = mapa;
    this->jugador = jugador;
    this->progreso = 0;
    this->objetivo = cantidad_minas;
}

Constructor::Constructor(ListaEdificios edificios, Mapa * mapa, Jugador* jugador) {
    this->nombre = LISTA_OBJETIVOS[OBJ_CONSTRUCTOR];
    this->edificios = edificios;
    this->mapa = mapa;
    this->jugador = jugador;
    this->progreso = 0;
    this->objetivo = edificios.devolver_cantidad();   
}

Armado::Armado(ListaMateriales materiales) {
    this->nombre = LISTA_OBJETIVOS[OBJ_ARMADO];
    this->materiales = materiales;
    this->progreso = 0;
    this->objetivo = 10;
}

Extremista::Extremista() {
    this->nombre = LISTA_OBJETIVOS[OBJ_EXTREMISTA];
    this->progreso = 0;
    this->objetivo = 500;
}

Principal::Principal(Mapa* mapa, Jugador* jugador) {
    this->nombre = LISTA_OBJETIVOS[OBJ_OBELISCO];
    this->mapa = mapa;
    this->jugador = jugador;
    this->progreso = 0;
    this->objetivo = 1;
}


int Comprar_Andypolis::calcular_progreso() {
    return this->progreso;
}

int Bombardero::calcular_progreso() {
    return this->progreso;
}

int Letrado::calcular_progreso() {
    return (mapa->edificios_construidos("escuela", *jugador));
}

int Edad_De_Piedra::calcular_progreso() {
    int indice_piedra = materiales.buscar_indice("piedra");
    return materiales.consulta(indice_piedra).devolver_cantidad();
}

int Energetico::calcular_progreso() {
    return jugador->devolver_energia();
}

int Cansado::calcular_progreso() {
    return jugador->devolver_energia();
}

int Minero::calcular_progreso() {
    //no se me ocurrio otra cosa jaja
    int contador = 0;
    if (mapa->tiene_edificio("mina", *jugador)) {
        contador++;
    }
    if (mapa->tiene_edificio("mina oro", *jugador)) {
        contador++;
    }
    return contador;
}

int Armado::calcular_progreso() {
    int indice_piedra = materiales.buscar_indice("bombas");
    this->progreso = materiales.consulta(indice_piedra).devolver_cantidad();
    return this->progreso;
}

int Constructor::calcular_progreso() {
    int contador = 0;
    bool resultado = true;
    std::string nombre;
    Edificio* array_edificios = edificios.devolver_todo();
    for (int i = 0; i < edificios.devolver_cantidad(); i++) {
        nombre = array_edificios[i].devolver_nombre();
        resultado = mapa->tiene_edificio(nombre, *jugador);   
        if (resultado) {
            contador++;
        }
    }
    return contador;
}

int Principal::calcular_progreso() {
    return mapa->tiene_edificio("obelisco", *jugador);    //0 si false; 1 si true
}

int Extremista::calcular_progreso() {
    return this->progreso;
}



void Comprar_Andypolis::actualizar(int valor){
    // valor es andycoins gastados o recogidos (basicamente cualquier tipo de operacion)
    this->progreso += valor;
}
void Bombardero::actualizar(int valor){
    // valor es bombas usadas en el momento
    this->progreso += valor;
}

void Extremista::actualizar(int valor){
    //valor es cantidad de bombas compradas en una sola compra
    this->progreso += valor;
}



void Edad_De_Piedra::actualizar(int valor){}

void Energetico::actualizar(int valor){}

void Letrado::actualizar(int valor){}

void Minero::actualizar(int valor){}

void Constructor::actualizar(int valor){}

void Cansado::actualizar(int valor){}

void Armado::actualizar(int valor){}

void Principal::actualizar(int valor){}


bool Comprar_Andypolis::checkear(){
    return (this->calcular_progreso() >= this->objetivo);
}

bool Edad_De_Piedra::checkear(){
    return (this->calcular_progreso() >= this->objetivo);
}

bool Bombardero::checkear(){
    return (this->calcular_progreso() >= this->objetivo);
}

bool Energetico::checkear(){
    return (this->calcular_progreso() >= this->objetivo);
}

bool Letrado::checkear(){
    return (this->calcular_progreso() == this->objetivo);
}

bool Minero::checkear(){
    return (this->calcular_progreso() == this->objetivo);
}

bool Cansado::checkear(){
    return (this->calcular_progreso() == this->objetivo);
}

bool Armado::checkear() {
    return (this->calcular_progreso() >= this->objetivo);
}

bool Extremista::checkear(){
    return (this->calcular_progreso() >= this->objetivo);
}

bool Principal::checkear(){
    return (this->calcular_progreso() == this->objetivo);
}   

bool Constructor::checkear(){
    return (this->calcular_progreso() == this->objetivo);
}
