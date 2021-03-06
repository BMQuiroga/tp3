#include "ComprarAndypolis.h"
ComprarAndypolis::ComprarAndypolis(){
    this->nombre="ComprarAndypolis";
    this->andycoins_juntadas = 0;
    this->cantidad_andycoins_objetivo = 100000;
    this->cumplio = false;
}

void ComprarAndypolis::actualizar(int valor) {
    this->andycoins_juntadas += valor;
}

bool ComprarAndypolis::checkear() {
    if (this->andycoins_juntadas >= this->cantidad_andycoins_objetivo){
        this->cumplio = true;
    }
    return cumplio;
}


void ComprarAndypolis::mostrar(){
    cout << "Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida (las monedas gastadas también cuentan para este objetivo)" << endl;
    cout << "Monedas juntadas: " << calcular_progreso() << "/100000" << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}

int ComprarAndypolis::calcular_progreso(){
    return this->andycoins_juntadas;
}