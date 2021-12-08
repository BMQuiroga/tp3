#include "utilidad.h"

string Utilidad::minuscula(string palabra) {
    for (unsigned int i = 0; i < palabra.length(); i++) {
        palabra[i] = (char) tolower(palabra[i]);
    }

    return palabra;
}

string Utilidad::capitalizar(string palabra) {
    palabra[0] = (char) toupper(palabra[0]);

    for (unsigned int i = 1; i < palabra.length(); i++) {
        palabra[i] = (char) tolower(palabra[i]);
    }

    return palabra;
}

string Utilidad::mayuscula(string palabra) {
    for (unsigned int i = 0; i < palabra.length(); i++) {
        palabra[i] = (char) toupper(palabra[i]);
    }
    return palabra;
}

bool Utilidad::es_numero(string numero) {
    bool validacion = true;
    int contador = 0;
    while (validacion && contador < numero.length()) {
        validacion = isdigit(numero[contador]);
        contador++;
    }

    return validacion;
}

bool Utilidad::pedir_confirmacion() {
    string opcion;

    cout << "Desea continuar con la operacion? [si/no] -> ";
    cin >> opcion;
    
    while (minuscula(opcion) != "si" && minuscula(opcion) != "no") {
        cout << "Ingreso invalido. Ingrese si o no [si/no] -> ";
        cin >> opcion;
    }
    return this->minuscula(opcion) == "si";
}

int Utilidad::pedir_opcion() {
    std::string opcion;

    std::cout << "Ingrese una opcion: " << std::endl;
    std::cin >> opcion;

    while (!this->es_numero(opcion))
    {
        std::cout << "Ingreso invalido. Intente de nuevo: ";
        std::cin >> opcion;
    }
    return stoi(opcion);
}