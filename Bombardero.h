
#ifndef TP3_2021_2C_BOMBARDERO_H
#define TP3_2021_2C_BOMBARDERO_H
#include "objetivo.h"

class Bombardero : public Objetivo {
private:

    int bombas_usadas;
    int bombas_objetivos;
    bool cumplio;

public:

    //Pre:-
    //Pos:Inicializa sus atributos, bombas_objetivo = 5
    Bombardero();

    //Pre:-
    //Pos:Destructor
    ~Bombardero();

    //Pre:-
    //Pos:Muestra por pantalla el objetivo, las bombas usadas,
    //    si cumple el objetivo muestra que fue completado
    void mostrar();

    //Pre:-
    //Pos: Retorna la cantidad de bombas usadas
    int calcular_progreso();

    //Pre:-
    //Pos: Devuelve true si las bombas usadas son mayores o igual que 5(objetivo)
    bool checkear();

    //Pre: Recibe la cant nueva de bombas
    //Pos: Actualiza la cant de bombas usadas sumandole lo del parametro
    void actualizar(int valor);
};


#endif //TP3_2021_2C_BOMBARDERO_H
