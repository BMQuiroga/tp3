//
// Created by ydsas on 4/12/2021.
//

#include "EdadDePiedra.h"

EdadDePiedra::EdadDePiedra(Jugador * jugador) {
    this->nombre="EdadDePiedra";
    this->jugador=jugador;
    this->cantidad_piedras = jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("piedras"))->devolver_cantidad();
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
    cantidad_piedras = (this->jugador->devolver_materiales()->consulta(this->jugador->devolver_materiales()->buscar_indice("piedra"))->devolver_cantidad());
    return cantidad_piedras;
}

/*
void EdadDePiedra::mostrar_progreso() {
    cout << "La cantidad de piedras obtenida es: " << this->cantidad_piedras << endl;
}*/