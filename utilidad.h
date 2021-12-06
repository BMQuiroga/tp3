#ifndef UTILIDAD_H
#define UTILIDAD_H

#include <iostream>

using namespace std;


class Utilidad {
public:
    string minuscula(string palabra);
    string mayuscula(string palabra);
    string capitalizar(string palabra);
    bool es_numero(string numero);
    bool pedir_confirmacion();
};


#endif