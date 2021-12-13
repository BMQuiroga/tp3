#include "Minero.h"
#include "mapa.h"
Minero::Minero(ListaEdificios * edificios, Mapa *mapa, Jugador *jugador) {
    this->cantidad_minas_necesarias = 0;
    this->existe_mina = false;
    this->existe_mina_oro = false;
    this->nombre = "Minero";
    this->cumplio = false;
    this->edificios = edificios;
    this->jugador = jugador;
    this->mapa = mapa;
    if(edificios->es_edificio_valido("mina")){
        existe_mina=true;
        cantidad_minas_necesarias++;
    }
    if(edificios->es_edificio_valido("mina oro")){
        existe_mina_oro=true; 
        cantidad_minas_necesarias++;
    }
}

void Minero::mostrar(){
    cout << "Minero: haber construido una mina de cada tipo. " << endl;
    cout << "Tipos de minas construidas: " << calcular_progreso() << "/" << cantidad_minas_necesarias << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}

bool Minero::checkear(){
    if (cantidad_minas_construidas==cantidad_minas_necesarias){
        this->cumplio = true;
    }
    return this->cumplio;
}

int Minero::calcular_progreso(){
    int contador = 0;
    if(this->mapa->edificios_construidos("mina",jugador)>=1 && existe_mina)
        contador++;
    if(this->mapa->edificios_construidos("mina oro",jugador)>=1 && existe_mina_oro)
        contador++;
    cantidad_minas_construidas = contador;
    return contador;
}

void Minero::actualizar(int valor){
    
}