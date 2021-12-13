#include "Energetico.h"
#include "jugador.h"

Energetico::Energetico(Jugador * jugador) {
    this->nombre="Energetico";
    this->jugador = jugador;
    this->energia = jugador->devolver_energia();
    this->energia_maxima = 100;
    this->cumplio = false;
}

void Energetico::mostrar(){
    cout << "Energético: haber terminado un turno con 100 puntos de energía. " << endl;
    if(cumplio)
        cout << "Este objetivo ha sido completado" << endl;
}

bool Energetico::checkear() {
    if (jugador->devolver_energia() >= this->energia_maxima){
        this->cumplio = true;
    }
    return this->cumplio;
}

int Energetico::calcular_progreso(){
    return 0;
}

void Energetico::actualizar(int valor){}