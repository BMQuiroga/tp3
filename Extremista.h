
#ifndef TP3_2021_2C_EXTREMISTA_H
#define TP3_2021_2C_EXTREMISTA_H
#include "objetivo.h"

class Extremista : public Objetivo {
private:
    int bombas_compradas;
    int bombas_necesarias;
    bool cumplio;
public:

    //Pre:-
    //Pos:Asigna los atributos, bombas_necesarias=500
    Extremista();

    //Pre:
    //Pos:
    int calcular_progreso();

    //Pre:-
    //Pos: Cheque que se haya comprado mayor o igual que 500 bombas
    bool checkear();

    //Pre:Recibe una cant de bombas
    //Pos: Actualiza la cant de bombas compradas sumandole el parametro
    void actualizar(int valor);

    //Pre:-
    //Pos:Muestra por pantalla el objetivo, y si lo cumple muestra que fue completado
    void mostrar();
};


#endif //TP3_2021_2C_EXTREMISTA_H
