
#ifndef TP3_2021_2C_LISTAOBJETIVOS_H
#define TP3_2021_2C_LISTAOBJETIVOS_H
#include "objetivo.h"
#include "ComprarAndypolis.h"
#include "EdadDePiedra.h"
#include "Bombardero.h"
#include "Energetico.h"
#include "Letrado.h"
#include "Minero.h"
#include "Cansado.h"
#include "Constructor.h"
#include "Armado.h"
#include "Extremista.h"

class listaObjetivos {

private:
    Objetivo** objetivos;
    int tope;

public:
    listaObjetivos(int tope, Jugador * jugador, ListaMateriales materiales, ListaEdificios edificios, Mapa * mapa);

    void alta(Objetivo *objetivo, int posicion);

};


#endif //TP3_2021_2C_LISTAOBJETIVOS_H
