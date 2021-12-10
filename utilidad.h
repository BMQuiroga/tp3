#ifndef UTILIDAD_H
#define UTILIDAD_H

#include <iostream>

using namespace std;


class Utilidad {
public:
    //pre: -
    //post: devuelve la palabra ingresada como todo minuscula
    string minuscula(string palabra);

    //pre: -
    //post: devuelve la palabra ingresada como todo mayuscula
    string mayuscula(string palabra);

    //pre: -
    //post: devuelve la palabra ingresada con el primer caracter mayuscula y el resto minuscula
    string capitalizar(string palabra);

    //pre: -
    //post: chequea que el numero ingresado es convertible a entero
    bool es_numero(string numero);

    //pre: -
    //post: pide confirmacion si el usuario quiere proceder
    bool pedir_confirmacion();

    //pre: -
    //post: pide ingreso al usuario, valida si es entero y lo devuelve
    int pedir_opcion();
    
    //pre: -
    //post: Devuelve un numero aleatorio entre los valores seleccionados (no incluye el max)
    int generador_de_numeros_aleatorios(int min, int max);

    void limpiar_pantalla();


    void pausa();


    void dormir();
};


#endif