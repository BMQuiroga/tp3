
#ifndef TP3_2021_2C_EDADDEPIEDRA_H
#define TP3_2021_2C_EDADDEPIEDRA_H
#include "objetivo.h"

class EdadDePiedra : public Objetivo {
private:
    ListaMateriales materiales;
public:
    Edad_De_Piedra(ListaMateriales materiales);

    void mostrar(){cout << "Edad de piedra: tener en el inventario 50000 piedras" << endl;}
    int calcular_progreso();
    bool checkear();
    void actualizar(int valor);

};


#endif //TP3_2021_2C_EDADDEPIEDRA_H
