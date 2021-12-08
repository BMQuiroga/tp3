
#ifndef TP3_2021_2C_LISTAOBJETIVOS_H
#define TP3_2021_2C_LISTAOBJETIVOS_H


// para evitar el importe circular
class Mapa;
class Jugador;
class Objetivo;
class ListaMateriales;
class ListaEdificios;

class ListaObjetivos {

private:
    Objetivo** objetivos;
    int tope;

public:
    ListaObjetivos(Jugador jugador, ListaMateriales materiales, ListaEdificios edificios, Mapa * mapa);

    void alta(Objetivo *objetivo, int posicion);

    void obtener_objetivos_aleatorios(Jugador jugador);

};


#endif //TP3_2021_2C_LISTAOBJETIVOS_H
