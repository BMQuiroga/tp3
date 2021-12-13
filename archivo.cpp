#include "archivo.h"
const std::string PATH_MAPA =           "mapa.txt";
const std::string PATH_EDIFICIOS =      "edificios.txt";
const std::string PATH_UBICACIONES =    "ubicaciones.txt";
const std::string PATH_MATERIALES =     "materiales.txt";


Archivo::Archivo() {}

void Archivo::leer_archivo(ifstream &archivo, std::string path) {
    archivo.open(path, ios::in);

    if(archivo)     std::cout << "Se abrio el archivo en " << path << endl;
    else            std::cout << "No se encontro el archivo en " << path << endl; 
}


Mapa* Archivo::procesar_archivo_mapa(){
    Mapa * mapa = NULL;
    ifstream archivo_mapa;
    char letra;
    int coordenadax, coordenaday, contador = 0;

    leer_archivo(archivo_mapa, PATH_MAPA);

    if (archivo_mapa) {
        archivo_mapa >> coordenadax;
        archivo_mapa >> coordenaday;

        mapa = new Mapa(coordenadax, coordenaday);    

        for(int i = 0; i < coordenadax; i++){
            for(int j = 0; j < coordenaday; j++){
                archivo_mapa >> letra;
                mapa->setear_casillero(i,j, asignar_casillero(letra));
                mapa->devolver_casillero(i,j)->setear_id(contador);
                contador++;
            }     
        }
    } else {
        std::cout << "Mapa esta vacio." << std::endl;
    }
    return mapa;
}


Casillero* Archivo::asignar_casillero(char letra) {     //pasable a mapa?
    Casillero* casillero = NULL;

         if(letra == 'T')       casillero = new CasilleroConstruible();
    else if(letra == 'C')       casillero = new CasilleroTransitable("Camino");
    else if(letra == 'B')       casillero = new CasilleroTransitable("Betun");
    else if(letra == 'M')       casillero = new CasilleroTransitable("Muelle");
    else if(letra == 'L')       casillero = new CasilleroInaccesible();
    else                        std::cout<<"ERROR";

    return casillero;
}


void Archivo::procesar_archivo_materiales(ListaMateriales* j1, ListaMateriales* j2){
    std::string nombre,numero1,numero2;    
    std::ifstream archivo("materiales.txt"); //abro el archivo modo lectura

    if(!archivo.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo materiales" <<std::endl;
    }else{
        while(getline(archivo, nombre, ' ')) {
            getline(archivo, numero1, ' ');
            getline(archivo, numero2);
            Material* material1 = new Material(nombre,stoi(numero1));
            Material* material2 = new Material(nombre,stoi(numero2));
            j1->alta(material1);
            j2->alta(material2);
        }
    
    archivo.close();
    }
}
