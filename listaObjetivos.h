
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
    Objetivo **objetivos;
    int tope;

public:
    //ListaObjetivos(Jugador jugador,/* ListaMateriales materiales, */ListaEdificios edificios/*, Mapa * mapa*/);

    void alta(Objetivo *objetivo, int posicion);

    void obtener_objetivos_aleatorios(Jugador jugador);

    Objetivo** obtener_objetivos_aleatorios(Jugador jugador, ListaEdificios edificios);

    void asignar_objetivos_correspondientes(int pos1, int pos2, int pos3, Jugador jugador, ListaEdificios edificios);
};


#endif //TP3_2021_2C_LISTAOBJETIVOS_H
