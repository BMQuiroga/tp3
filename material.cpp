#include <iostream>
#include "material.h"

void Material::operator+(int numero){
    this->cantidad = cantidad + numero;

}

void Material::operator-(int numero){
    this->cantidad = cantidad - numero;
    
}

std::string Material::devolver_nombre(){
    return this->nombre;
}

int Material::devolver_cantidad(){
    return this->cantidad;


}

Material::Material(std::string nombre,int cantidad){
    this->nombre = nombre;
    this->cantidad = cantidad;
}

Material::Material(){
    this->nombre = "0";
    this->cantidad = 0;
}

void Material::modificar_cantidad(int cantidad){
    this->cantidad = cantidad;
}

void Material::modificar_nombre(std::string nombre){
    this->nombre = nombre;
}

void Material::sumar_cantidad(int cantidad){
    this->cantidad+=cantidad;
}
