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

    //pre: -
    //pos: convierte el string a entero y valida si se puede hacer
    int convertir_a_entero(std::string numero);

    //pre: -
    //pos: limpia la pantalla
    void limpiar_pantalla();
    
    //pre: -
    //pos: pausa el juego
    void pausa();

    //pre:-
    //pos: encuadra el texto pasado por parametro
    void encuadrar(std::string texto);

    //PRE: -
    //POST: muestra una linea separadora
    void linea();
    
    //PRE: -
    //POST: diccionario de materiales
    int diccionario_materiales(std::string material);
};


#endif