#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

class Material{

private:
    std::string nombre;
    int cantidad;
public:
    //Pre:
    //Post:Resta la cantidad de material con el numero que recibe
    void operator-(int numero);

    //Pre:
    //Post:Suma la cantidad de material con el numero que recibe
    void operator+(int numero);

    //Pre:
    //Post:Devuelve el nombre del material
    std::string devolver_nombre();

    //Pre:
    //Post:Devuelve la cantidad del material
    int devolver_cantidad();

    //Pre:
    //Post:Crea un objeto material con nombre y cantidad
    Material(std::string nombre,int cantidad);

    //Pre:
    //Post:Crea un objeto material con nombre, cant piedra, cant madera, cant metal, maximos permitidos asignados en 0.
    Material();

    //Pre:
    //Post:Cambia el atributo cantidad por el que le pasan 
    void modificar_cantidad(int cantidad);

    //Pre:
    //Post:Cambia el atributo nombre por el que le pasan 
    void modificar_nombre(std::string nombre);

    //Pre:
    //Post: Suma el numero que le pasan al artibuto cantidad
    void sumar_cantidad(int cantidad);
};

#endif