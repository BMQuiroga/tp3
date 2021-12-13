#include "Cansado.h"
#include "jugador.h"

Cansado::Cansado(Jugador * jugador) {
    this->nombre="Cansado";
    this->energia = jugador->devolver_energia();
    this->energia_minima = 20;//Se checkea dsp de terminar el turno, asi que el minimo es 20 de energia
    this->cumplio = false;
    this->jugador = jugador;

}

Cansado::~Cansado() {}

void Cansado::mostrar(){
    cout << "Cansado: terminar un turno con 0 de energía." << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}

bool Cansado::checkear() {
    if (this->jugador->devolver_energia() == this->energia_minima){
        this->cumplio = true;
    }
    return this->cumplio;
}

int Cansado::calcular_progreso(){
    return 0;
}

void Cansado::actualizar(int valor) {
    
}
