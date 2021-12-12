#include "utilidad.h"
#include <cstdlib>

#ifdef _WIN32
    #define CLEAR "cls"
    #define PAUSE "pause"
#else
    // Assume POSIX
    #define CLEAR "clear"
    #define PAUSE "read -p 'Press Enter to continue...' var"

#endif

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
    while (validacion && contador < (int) numero.length()) {
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


int Utilidad::generador_de_numeros_aleatorios(int min, int max){
    //srand((unsigned)time(0));
    return min + rand()%(max+1-min);
}


int Utilidad::convertir_a_entero(std::string numero) {
    int numero_convertido;
    if (es_numero(numero))
        numero_convertido = stoi(numero);
    else {
        while(!es_numero(numero))  {
            std::cout << "Entrada invalida. Ingrese un entero: ";
            std::cin >> numero;
        }
        numero_convertido = stoi(numero);
    }
    return numero_convertido;
}


void Utilidad::limpiar_pantalla() {
    system(CLEAR);
}

void Utilidad::pausa() {
    system(PAUSE);
}

int Utilidad::diccionario_materiales(std::string material){
    if (material=="andycoins")
        return 250;
    if (material=="piedra")
        return 100;
    else
        return 50;
}