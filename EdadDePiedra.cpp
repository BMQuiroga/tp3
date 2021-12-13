#include "EdadDePiedra.h"
#include "jugador.h"

EdadDePiedra::EdadDePiedra(Jugador * jugador) {
    this->nombre="EdadDePiedra";
    this->jugador=jugador;
    this->indice = jugador->devolver_materiales()->buscar_indice("piedra");
    this->cantidad_piedras = jugador->devolver_materiales()->consulta(indice)->devolver_cantidad();
    this->cantidad_piedras_necesarias = 50000;
    this->cumplio = false;
}

void EdadDePiedra::mostrar(){
    cout << "Edad de piedra: tener en el inventario 50000 piedras" << endl;
    cout << "Piedra obtenida: " << calcular_progreso() << "/50000" << endl;
    if(checkear())
        cout << "Este objetivo ha sido completado" << endl;
}

bool EdadDePiedra::checkear() {
    if (this->cantidad_piedras >= this->cantidad_piedras_necesarias){
        this->cumplio = true;
    }
    return this->cumplio;
}

int EdadDePiedra::calcular_progreso(){
    cantidad_piedras = (this->jugador->devolver_materiales()->consulta(indice)->devolver_cantidad());
    return cantidad_piedras;
}


void EdadDePiedra::actualizar(int valor){
    
}