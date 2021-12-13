#include <iostream>
#include <ctime>
#include <cstdlib>
#include "mapa.h"
#include "grafomapa.h"
#include "utilidad.h"


// Mapa::Mapa(ListaEdificios edificios){
//     procesar_archivo_mapa();
//     //procesar_archivo_ubicaciones(edificios);
// }

Mapa::Mapa(int filas, int columnas) {
    this->definir(filas, columnas);

    Casillero*** casilla;
    casilla = new Casillero**[filas];
    
    for(int i = 0; i < filas; i++){
        casilla[i] = new Casillero*[columnas];
    }

    this->matriz = casilla;
}

Mapa::~Mapa() {
    cout << "Destructor mapa" << endl;
    for (int i = 0; i < coordenada_x; i++) {
        for(int j = 0; j < coordenada_y; j++) {
            //cout << "Posicion: (" << i << ", " << j << ")" << endl;
            //  matriz[i][j]->liberar_memoria();
            delete matriz[i][j];
        }
        delete [] matriz[i];
        //matriz[i] = NULL;
    }
    delete [] matriz;
    //matriz = NULL;
}

void Mapa::definir(int coordenada_x,int coordenada_y){
    this -> coordenada_x = coordenada_x;
    this -> coordenada_y = coordenada_y;
}

int Mapa::devolver_cantidad_filas() {
    return this->coordenada_x;
}

int Mapa::devolver_cantidad_columnas() {
    return this->coordenada_y;
}

int Mapa::pedir_fila() {
    int fila;
    cout << "Ingrese la coordenada x [entre 0 - " << this->devolver_cantidad_filas() - 1 << "] -> ";    cin >> fila;
    while(fila < 0 || fila >= this->devolver_cantidad_filas()) {
        cout << "Fila no valida. Ingrese de nuevo. [entre 0 - " << this->devolver_cantidad_filas() - 1 << "] -> ";
        cin >> fila; 
    }
    return fila;
}

int Mapa::pedir_columna() {
    int columna;
    cout << "Ingrese la coordenada y [entre 0 - " << this->devolver_cantidad_columnas() - 1 << "] -> ";    cin >> columna;
    while(columna < 0 || columna >= this->devolver_cantidad_columnas()) {
        cout << "Fila no valida. Ingrese de nuevo. [entre 0 - " << this->devolver_cantidad_columnas() - 1 << "] -> ";
        cin >> columna; 
    }
    return columna;
}

Casillero* Mapa::devolver_casillero(int x, int y) {
    return matriz[x][y];
}

void Mapa::setear_casillero(int x, int y, Casillero* casillero) {
    this->matriz[x][y] = casillero;
}


void Mapa::llamar_lluvia(Jugador* jugador1, Jugador* jugador2){
    Utilidad util;
    srand((unsigned)time(0));
    int cantidad_material_piedra = util.generador_de_numeros_aleatorios(1,2);//1+rand()%1;
    int cantidad_material_madera = util.generador_de_numeros_aleatorios(0,1);//rand()%1;
    int cantidad_material_metal = util.generador_de_numeros_aleatorios(2,4);//2+rand()%2;
    int cantidad_material_andycoins = util.generador_de_numeros_aleatorios(0,1);
    //std::cout<<cantidad_material_piedra<<" "<<cantidad_material_madera<<" "<<cantidad_material_metal<<std::endl;
    int j1_x = jugador1->devolver_coordenada_x();
    int j1_y = jugador1->devolver_coordenada_y();
    int j2_x = jugador2->devolver_coordenada_x();
    int j2_y = jugador2->devolver_coordenada_y();
    lluvia(cantidad_material_piedra, "piedra",j1_x,j1_y,j2_x,j2_y);
    lluvia(cantidad_material_madera, "madera",j1_x,j1_y,j2_x,j2_y);
    lluvia(cantidad_material_metal, "metal",j1_x,j1_y,j2_x,j2_y);
    lluvia(cantidad_material_andycoins,"andycoins",j1_x,j1_y,j2_x,j2_y);
    std::cout <<"Lluvia llamada satisfactoriamente" <<std::endl;
    std::cout <<"-------------------------------------------------" <<std::endl;
}

void Mapa::lluvia(int cantidad, std::string material, int j1_x, int j1_y, int j2_x, int j2_y){
    int error = 0;//Para evitar while true, cuando se queda sin casilleros transitables vacios
    Utilidad util;
    while(cantidad){
        error++;
        int coord_x = util.generador_de_numeros_aleatorios(0,coordenada_x-1);
        int coord_y = util.generador_de_numeros_aleatorios(0,coordenada_y-1);
        if ((matriz[coord_x][coord_y]->devolver_tipo() == 'C') && (!matriz[coord_x][coord_y]->tiene_material_o_edificio()) && (coord_x!=j1_x && coord_y!=j1_y) && (coord_x!=j2_x && coord_y!=j2_y)){
            Material* mat = new Material(material, util.diccionario_materiales(material));
            matriz[coord_x][coord_y]->poner_material(mat);
            cantidad--;
        }
        if (error > 100){
            cantidad = 0;
            std::cout<<"No quedan mas caminos libres!" <<std::endl;
        }
    }
}

void Mapa::recolectar(Jugador* jugador){//RECOLECTAR MATERIAL TIENE QUE ESTAR EN LAGO Y CAMINO PERO NO HACER NADA
    for(int i = 0; i < coordenada_x; i++){
        for(int j = 0; j < coordenada_y; j++){
            if(matriz[i][j]->devolver_tipo() == 'T' && matriz[i][j]->devolver_jugador() == jugador->devolver_nombre())
                matriz[i][j]->recolectar_material(jugador); //MANDAR PARAMETRO PIEDRA METAL MADERA
        }
    }
    jugador->restar_energia(20);
}

void Mapa::demoler(ListaEdificios* edificios, int coord_x, int coord_y, Jugador* jugador){
    if (matriz[coord_x][coord_y] -> tiene_material_o_edificio() && matriz[coord_x][coord_y]->devolver_tipo() == 'T'){
        //HAY QUE HACERLA DEVUELTA CON LAS LISTAS DE MATERIALES
        /*int piedra=devolver_indice_materiales(materiales,"piedra");
        int madera=devolver_indice_materiales(materiales,"madera");
        int metal=devolver_indice_materiales(materiales,"metal");*/

        if (jugador->devolver_nombre() == matriz[coord_x][coord_y]->devolver_jugador()) {
            std::cout << matriz[coord_x][coord_y]->devolver_material_o_edificio() << " demolido/a satisfactoriamente." << std::endl;
            matriz[coord_x][coord_y] -> demoler(jugador);
            matriz[coord_x][coord_y] -> cambiar_jugador(0);
            jugador->restar_energia(15);  
        } else {
            std::cout << "No podes demoler un edificio que no es tuyo." << std::endl;
        }
    }
    else
        std::cout<<"No hay ningun edificio en este casillero!"<<std::endl;
}

void Mapa::mostrar_mapa_edificios_y_materiales(int coord_x, int coord_y, Jugador* jugador1, Jugador* jugador2){
    if(matriz[coord_x][coord_y] -> devolver_material_o_edificio() == "piedra")
        std::cout << " " << PIEDRA ;//⛏️ amarillo
    else if(matriz[coord_x][coord_y] -> devolver_material_o_edificio() == "madera")
        std::cout << " " << MADERA ;//🪓 amarillo
    else if(matriz[coord_x][coord_y] -> devolver_material_o_edificio() == "metal")
        std::cout << " " << METAL ;//⚙️ amarillo
    else if(matriz[coord_x][coord_y] -> devolver_material_o_edificio() == "andycoins")
        std::cout << " " << ANDYCOINS ;//⚙️ amarillo
    else{
        //SETEA EL COLOR DEPENDIENDO DE QUIEN SEA EL EDIFICIO, SI NO ES UN MATERIAL
        if(matriz[coord_x][coord_y] -> devolver_jugador() == jugador1->devolver_nombre())
            std::cout << COLOR_ROJO ; //ROJO PARA J1
        if(matriz[coord_x][coord_y] -> devolver_jugador() == jugador2->devolver_nombre())
            std::cout << COLOR_VIOLETA ; //VIOLETA PARA J2


        if(matriz[coord_x][coord_y]->devolver_material_o_edificio() == "planta electrica")
            std::cout << " " << PLANTA_ELECTRICA ;
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio() == "obelisco")
            std::cout << " " << OBELISCO ;
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio() == "escuela")
            std::cout << " " << ESCUELA ;
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio() == "fabrica")
            std::cout << " " << FABRICA ;
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio() == "aserradero")
            std::cout << " " << ASERRADERO ;
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio() == "mina")
            std::cout << " " << MINA ;
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio() == "mina oro")
            std::cout << " " << MINA_ORO ;
        else
            std::cout << " " << DESCONOCIDO ;
    }
}   

void Mapa::mostrar_mapa(Jugador* jugador1, Jugador* jugador2){
    std::cout <<"Ademas de los mencionados en el pdf, se usan: R para camino, T para terreno y L para lago"<<std::endl;
    std::cout <<"Columna: ";
    for(int k = 0 ;k < coordenada_y ;k++)
        std::cout <<k <<" ";
    std::cout<<std::endl;
    for(int i = 0 ;i < coordenada_x ;i++){
        if(i<10)
            std::cout <<"Fila " <<i <<": ";
        else
            std::cout <<"Fila " <<i <<":";
        //std::cout<<coordenada_y<<std::endl;
        for(int j = 0 ;j < coordenada_y ;j++){
            //std::cout<<"ENTRA"<<std::endl;
            if(i == jugador1->devolver_coordenada_x() && j == jugador1->devolver_coordenada_y())
                std::cout << JUGADOR_1 ; //J en rojo
            else if(i == jugador2->devolver_coordenada_x() && j == jugador2->devolver_coordenada_y())
                std::cout << JUGADOR_2 ; //U en violeta
            else if (matriz[i][j]->tiene_material_o_edificio())
                mostrar_mapa_edificios_y_materiales(i ,j ,jugador1 ,jugador2);
            else {
                if (matriz[i][j]->devolver_tipo() == 'C')
                    std::cout << CAMINO ; // R naranja
                else if (matriz[i][j]->devolver_tipo() == 'T')
                    std::cout << TERRENO ; // T verde
                else
                    std::cout << LAGO ; //L celeste
            }
        }
        std::cout <<std::endl;
    }
}



void Mapa::mostrar_recorrido(ListaRecorrido* recorrido, Jugador * jugador) {
    //hecho asi nomas, ver si se puede agregar las cosas de los casilleros
    std::cout <<"Columna: ";
    for(int k = 0 ;k < coordenada_y ;k++)
        std::cout <<k <<" ";
    std::cout<<std::endl;
    for(int i = 0 ;i < coordenada_x ;i++){
        if(i<10)
            std::cout <<"Fila " <<i <<": ";
        else
            std::cout <<"Fila " <<i <<":";
        for(int j = 0 ;j < coordenada_y ;j++){
            if (recorrido->contiene(matriz[i][j]->obtener_id())) {
                matriz[i][j]->recolectar_material(jugador);
                std::cout << " " << COLOR_ROJO << matriz[i][j]->devolver_tipo_camino() << COLOR_BLANCO ;
            } else {
                std::cout << " " << matriz[i][j]->devolver_tipo_camino();
            }
        }
        std::cout <<std::endl;
    }
}



void Mapa::destruir(){
    for(int i = 0; i < coordenada_x; i++){
    	for(int j = 0; j < coordenada_y; j++){
            delete matriz[i][j];
            //matriz[i][j] = nullptr;// no es necesario pero buena practica. 12/12/2021(buena practica pero tira error, asi que se va)
        }

        delete[] matriz[i];
    }
    delete[] matriz;
}



void Mapa::procesar_archivo_mapa(){
    char letra;
    int coordenadax, coordenaday;
    int contador = 0;
    std::ifstream archivo_mapa("mapa.txt" ,std::ios::in);
    if(!archivo_mapa)
        std::cout <<"El archivo no se abrio correctamente"<<std::endl;
    else{
        archivo_mapa >> coordenadax;
        archivo_mapa >> coordenaday;
        
        definir(coordenadax, coordenaday);
        
        //std::cout<<coordenada_x<<" "<<coordenada_y<<std::endl;

        Casillero*** casilla;
        casilla = new Casillero**[coordenada_x];
        for(int i = 0; i < coordenada_x; i++){
            casilla[i] = new Casillero*[coordenada_y];
            for(int j = 0; j < coordenada_y; j++){
                archivo_mapa >> letra;
                //std::cout<<i<<" "<<j<<std::endl;
                if(letra == 'T')
                    casilla[i][j] = new CasilleroConstruible();
                else if(letra == 'C')
                    casilla[i][j] = new CasilleroTransitable("Camino");
                else if(letra == 'B')
                    casilla[i][j] = new CasilleroTransitable("Betun");
                else if(letra == 'M')
                    casilla[i][j] = new CasilleroTransitable("Muelle");
                else if(letra == 'L')
                    casilla[i][j] = new CasilleroInaccesible();
                else
                    std::cout<<"ERROR";

                casilla[i][j]->setear_id(contador);
                contador++;
            }     
        }
        this->matriz = casilla;
    }
}
bool Mapa::casillero_ocupado(Jugador* jugador, int coord_x, int coord_y){
    return(matriz[jugador->devolver_coordenada_x()][jugador->devolver_coordenada_y()] == matriz[coord_x][coord_y]);

}


void Mapa::construir(ListaEdificios* edificios, Jugador* jugador, Jugador* rival){
    std::string edificio, ingreso;
    int coord_x, coord_y;
    std::cout <<"Ingrese el nombre del edificio que desea construir -> ";
    cin.ignore();
    getline(cin, edificio);
    std::cout <<"Ingresaste  (es para probar espacios) -> " << edificio << std::endl;

    if(se_puede_construir(edificios, edificio, jugador)){
        std::cout <<"Se puede construir el edificio, desea hacerlo?\n1. Construir el edificio\n2. Salir al menú" <<std::endl;
        std::cin >>ingreso;
        if(ingreso == "1"){
            coord_x = pedir_fila();
            coord_y = pedir_columna();

            if(matriz[coord_x][coord_y] -> devolver_tipo() == 'T'){
                if( !casillero_ocupado(jugador, coord_x, coord_y) && 
                    !casillero_ocupado(rival, coord_x, coord_y) && 
                    !matriz[coord_x][coord_y]->tiene_material_o_edificio()){
                        realizar_construccion(edificios,coord_x,coord_y,edificio,jugador);
                        matriz[coord_x][coord_y] -> cambiar_jugador(jugador->devolver_nombre());
                }
                else
                    std::cout <<"El casillero esta ocupado!"<<std::endl;
            } else {
                std::cout <<"No se puede construir en esa coordenada!"<<std::endl;
            }
        }
    }
}

bool Mapa::se_puede_construir(ListaEdificios* edificios, std::string nombre, Jugador* jugador){
    //bool es_valido_construir = true;
    //cout << "antes";
    bool es_valido_construir = false;

    Edificio* edificio = edificios->consulta(nombre);
    //cout << "despues";
    if(!edificios->es_edificio_valido(nombre)){
        std::cout <<"No existe un edificio con ese nombre!" <<std::endl;
        return false;
    }
    int indice_piedra = jugador->devolver_materiales()->buscar_indice("piedra");
    int indice_madera = jugador->devolver_materiales()->buscar_indice("madera");
    int indice_metal = jugador->devolver_materiales()->buscar_indice("metal");
    
    bool hay_piedra = false, hay_madera = false, hay_metal = false;
    
    hay_piedra=(jugador->devolver_materiales()->consulta(indice_piedra)->devolver_cantidad()>= edificios->consulta(nombre)->devolver_piedra());
    hay_madera=(jugador->devolver_materiales()->consulta(indice_madera)->devolver_cantidad()>= edificios->consulta(nombre)->devolver_madera());
    hay_metal=(jugador->devolver_materiales()->consulta(indice_metal)->devolver_cantidad()>= edificios->consulta(nombre)->devolver_metal());

    if(hay_madera && hay_piedra && hay_metal){
        if(edificio->devolver_maximos_permitidos() > edificios_construidos(nombre,jugador)){
            es_valido_construir = true;
        }
        else{
            std::cout <<"Ya se alcanzo el limite para ese edificio!"<<std::endl;
        }
    }
    else{
        std::cout <<"No alcanzan los materiales!"<<std::endl;
    }
    return es_valido_construir;
}

int Mapa::edificios_construidos(std::string nombre, Jugador* jugador){
    int contador = 0;
    for (int i = 0; i < coordenada_x; i++){
        for(int j = 0; j<coordenada_y; j++){
            if( matriz[i][j]->devolver_tipo() == 'T' && matriz[i][j]->tiene_material_o_edificio() && 
                matriz[i][j]->devolver_material_o_edificio() == nombre && matriz[i][j]->devolver_tipo() == 'T' && 
                matriz[i][j]->devolver_jugador() == jugador->devolver_nombre())

                contador++;
        }
    }
    return contador;
}

void Mapa::realizar_construccion(ListaEdificios* edificios, int coord_x, int coord_y, std::string nombre, Jugador* jugador){
   
    int indice_piedra = jugador->devolver_materiales()->buscar_indice("piedra");
    int indice_madera = jugador->devolver_materiales()->buscar_indice("madera");
    int indice_metal = jugador->devolver_materiales()->buscar_indice("metal");

    jugador->devolver_materiales()->obtener_nodo(indice_piedra) -> restar_cantidad(edificios->consulta(nombre)->devolver_piedra());
    jugador->devolver_materiales()->obtener_nodo(indice_madera) -> restar_cantidad(edificios->consulta(nombre)->devolver_madera());
    jugador->devolver_materiales()->obtener_nodo(indice_metal) -> restar_cantidad(edificios->consulta(nombre)->devolver_metal());

    matriz[coord_x][coord_y] -> construir(edificios->consulta(nombre));
    std::cout <<nombre <<" construido/a satisfactoriamente!" <<std::endl;
    jugador->restar_energia(15);
}

void Mapa::listar_edificios_construidos(ListaEdificios* edificios, Jugador* jugador){
    
    Edificio** array_edificios = edificios->devolver_todo();

    for(int i = 0 ; i < edificios->devolver_cantidad() - 1; i++){//
        std::string nombre = array_edificios[i]->devolver_nombre();
        int construidos = edificios_construidos(nombre, jugador);
        if (construidos){
            std::cout <<"Nombre: " <<nombre<<", Cantidad construida: " <<construidos <<std::endl;
            std::cout <<"Coordenadas:";
            mostrar_coordenadas(nombre, jugador);
        } 
    }
    delete[] array_edificios;
}

void Mapa::mostrar_coordenadas(std::string nombre, Jugador* jugador){
    for(int i = 0; i < coordenada_x; i++){
        for(int j = 0; j<coordenada_y; j++){
            if(matriz[i][j] -> devolver_material_o_edificio() == nombre && matriz[i][j] -> devolver_jugador() == jugador->devolver_nombre())
                std::cout<<" ("<<i<<", "<<j<<") ";
        }
    }
    std::cout <<"\n-------------------------------------------------" <<std::endl;
}

void Mapa::menu_demoler(ListaEdificios* edificios, Jugador* jugador){
    int coord_x, coord_y;
    // std::cout <<"Ingrese la coordenada x"<<std::endl;
    // std::cin >>coord_x;
    // std::cout<<"Ingrese la coordenada y"<<std::endl;
    // std::cin >>coord_y;

    coord_x = pedir_fila();
    coord_y = pedir_columna();

    demoler(edificios, coord_x,coord_y,jugador);

    // if(coord_x < coordenada_x && coord_y < coordenada_y && coord_x >= 0 && coord_y >= 0)
    //     demoler(edificios, coord_x,coord_y,jugador);
    // else
    //     std::cout<<"Posicion elegida fuera de rango!"<<std::endl;
}

void Mapa::menu_consultar_coordenada(){
    int coord_x,coord_y;
    // std::cout <<"Ingrese la coordenada x"<<std::endl;
    // std::cin >>coord_x;
    // std::cout <<"Ingrese la coordenada y"<<std::endl;
    // std::cin >>coord_y;
    coord_x = pedir_fila();
    coord_y = pedir_columna();

    this->matriz[coord_x][coord_y]->mostrar();

    // if(coord_x < coordenada_x && coord_y<coordenada_y && coord_x >= 0 && coord_y >= 0)
    //     this->matriz[coord_x][coord_y]->mostrar();
    // else
    //     std::cout <<"Posicion elegida fuera de rango!" <<std::endl;
}

void Mapa::listar_todos_los_edificios(ListaEdificios* edificios, Jugador* jugador1, Jugador* jugador2){
    Edificio** array_edificios = edificios->devolver_todo();
    cout << edificios->devolver_cantidad();
    for(int i = 0; i < edificios->devolver_cantidad()-1 ; i++){

        Edificio* edificio = array_edificios[i];
        std::string nombre = edificio->devolver_nombre();
        int construidos1 = edificios_construidos(nombre, jugador1);
        int construidos2 = edificios_construidos(nombre, jugador2);
        int maximos_permitidos = edificio->devolver_maximos_permitidos();
        
        std::cout <<"Nombre: " <<edificio->devolver_nombre() <<std::endl;

        std::cout <<"Para construirlo se requieren " << edificio->devolver_piedra() <<" de piedra, " <<edificio->devolver_madera() <<" de madera y " <<edificio->devolver_metal() <<" de metal." <<std::endl;
        std::cout <<"El jugador 1 construyó "<<construidos1 <<" y puede construir " << maximos_permitidos - construidos1 <<" mas antes de llegar al limite." <<std::endl;
        std::cout <<"El jugador 2 construyó "<<construidos2 <<" y puede construir " << maximos_permitidos - construidos2 <<" mas antes de llegar al limite." <<std::endl;
        edificio->imprimir_brinda_materiales();
        std::cout <<"-------------------------------------------------" <<std::endl;
    }
    delete[] array_edificios;
}

void Mapa::menu_atacar(Jugador* jugador, Jugador* rival){
    bool destruido;
    int coord_x, coord_y;
    // std::cout <<"Ingrese la coordenada x del edificio enemigo que desea atacar" <<std::endl;
    // std::cin >>coord_x;
    // std::cout <<"Ingrese la coordenada y" <<std::endl;
    // std::cin >>coord_y;
    coord_x = pedir_fila();
    coord_y = pedir_columna();

    if(matriz[coord_x][coord_y] -> devolver_jugador() == rival->devolver_nombre() && matriz[coord_x][coord_y] -> tiene_material_o_edificio()){
        if(jugador->devolver_energia() >= 30){
            if(jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("bombas"))->devolver_cantidad() >= 1){
                destruido = matriz[coord_x][coord_y] -> atacar();
                if(destruido)
                    matriz[coord_x][coord_y]->cambiar_jugador(0);
                jugador->restar_energia(30);
                jugador->devolver_materiales()->consulta(jugador->devolver_materiales()->buscar_indice("bombas"))->sumar_cantidad(-1);
                jugador->actualizar_bombas_usadas();//le suma 1 por defecto
            }
            else
                std::cout<<"No tienes bombas!" <<std::endl;
        }
        else
            std::cout <<"No tienes energia suficiente!" <<std::endl;
    }
    else
        std::cout <<"No hay un edificio enemigo en esa posicion!" <<std::endl;


}

void Mapa::menu_reparar(Jugador* jugador){
    int coord_x, coord_y;
    // std::cout <<"Ingrese la coordenada x del edificio que desea reparar" <<std::endl;
    // std::cin >>coord_x;
    // std::cout <<"Ingrese la coordenada y" <<std::endl;
    // std::cin >>coord_y;
    coord_x = pedir_fila();
    coord_y = pedir_columna();

    if(matriz[coord_x][coord_y] -> devolver_jugador() == jugador->devolver_nombre() && matriz[coord_x][coord_y] -> tiene_material_o_edificio()){
        if((matriz[coord_x][coord_y] -> devolver_material_o_edificio() == "mina" || matriz[coord_x][coord_y] -> devolver_material_o_edificio() == "fabrica")){
            matriz[coord_x][coord_y] -> reparar(jugador);
        }
        else
            std::cout <<"Ese edificio no está dañado!" <<std::endl;
    }
    else
        std::cout <<"No hay un edificio propio en esa posicion!" <<std::endl;
}


bool Mapa::tiene_edificio(std::string nombre_edificio, Jugador* jugador) {
    int i = 0;
    int j = 0;

    while (i < coordenada_x) {
        while (j < coordenada_x) {
            if(matriz[i][j] -> devolver_tipo() == 'T' && matriz[i][j] -> devolver_material_o_edificio() == nombre_edificio && matriz[i][j] -> devolver_jugador() == jugador->devolver_nombre()) {
                return true;
            } j++;
        } i++;
    }
    return false;
}



void Mapa::reescribir_ubicaciones(Jugador* j, Jugador* u){
    std::ofstream archivo_ubicaciones;
    
    archivo_ubicaciones.open("ubicaciones.txt");
    if(!archivo_ubicaciones.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo ubicaciones" <<std::endl;
    }
    else{
        reescribir_materiales(archivo_ubicaciones);
        archivo_ubicaciones << "1 (" << j->devolver_coordenada_x() << ", " << j->devolver_coordenada_y() << ")" << std::endl;
        reescribir_jugador(archivo_ubicaciones,1);
        archivo_ubicaciones << "2 (" << u->devolver_coordenada_x() << ", " << u->devolver_coordenada_y() << ")" << std::endl;
        reescribir_jugador(archivo_ubicaciones,2);
    }
    archivo_ubicaciones.close();
}

void Mapa::reescribir_materiales(ofstream & archivo_ubicaciones){
    std::string material_o_edificio;
    for(int i = 0; i < coordenada_x; i++){
        for(int j = 0; j < coordenada_y; j++){
            if(matriz[i][j] -> tiene_material_o_edificio() && matriz[i][j] -> devolver_tipo()=='C'){
                material_o_edificio = matriz[i][j] -> devolver_material_o_edificio();
                archivo_ubicaciones <<material_o_edificio <<" (" << i <<", " << j <<")"<<std::endl;
            }
        }
    }   
}

void Mapa::reescribir_jugador(ofstream & archivo_ubicaciones, int numero_jugador){
    std::string material_o_edificio;
    for(int i = 0; i < coordenada_x; i++){
        for(int j = 0; j < coordenada_y; j++){
            if(matriz[i][j] -> tiene_material_o_edificio() && matriz[i][j] -> devolver_jugador()==numero_jugador){
                material_o_edificio = matriz[i][j] -> devolver_material_o_edificio();
                archivo_ubicaciones <<material_o_edificio <<" (" << i <<", " << j <<")"<<std::endl;
            }
        }
    }   
}

bool Mapa::procesar_archivo_ubicaciones(ListaEdificios* edificios, Jugador* j, Jugador* u){
    std::string nombre;
    //int coord_x;
    // int coord_y;
    std::string aux;
    bool archivo_en_blanco = true;


    std::ifstream archivo_ubicaciones("ubicaciones.txt",std::ios::in);
    if(!archivo_ubicaciones){
        return true;
        std::cout<<"No se ha encontrado el archivo ubicaciones, comenzando nueva partida..."<<std::endl;
    }
    else{
        //archivo_en_blanco = true;
        archivo_en_blanco=procesar_archivo_ubicaciones_materiales(archivo_ubicaciones);
        if(archivo_en_blanco)
            return true;
        else{
            
            //getline(archivo_ubicaciones,aux,'(');
            
            procesar_archivo_ubicaciones_jugador(archivo_ubicaciones,j);
           
            procesar_archivo_ubicaciones_edificios(archivo_ubicaciones, edificios,1);
           
            procesar_archivo_ubicaciones_jugador(archivo_ubicaciones,u);
            
            procesar_archivo_ubicaciones_edificios(archivo_ubicaciones,edificios,2);
           
        }
    }
    return archivo_en_blanco;
}

bool Mapa::procesar_archivo_ubicaciones_materiales(ifstream & archivo){
    Utilidad util;
    std::string nombre;
    bool archivo_en_blanco;
    std::string aux;
    int coord_x,coord_y;
    while(archivo >> nombre){
        archivo_en_blanco=false;
        //std::cout << nombre << "nombre" << std::endl;
        if (nombre == "1"){
            return archivo_en_blanco;
        }
        //std::cout << nombre << "nombre" << std::endl;
        getline(archivo,aux,'(');
        archivo >> aux;
        coord_x = stoi(aux);
        archivo >> aux;
        coord_y = stoi(aux);
        Material* material = new Material(nombre,util.diccionario_materiales(nombre));
        matriz[coord_x][coord_y]->poner_material(material);
    }
    return archivo_en_blanco;
}

void Mapa::procesar_archivo_ubicaciones_edificios(ifstream & archivo, ListaEdificios* edificios, int numero_jugador){
    std::string nombre;
    //bool archivo_en_blanco;
    std::string aux;
    int coord_x,coord_y;
    while (archivo>>nombre){
    
        if (nombre == "2"){
            return;
        }
        getline(archivo,aux,'(');
        
        if (aux == " oro "){
            nombre = "mina oro";
        }
        if (aux == " electrica "){
            nombre = "planta electrica";
        }
        
        //cout << "Nombre: " << aux;
        archivo >> aux;
       
        coord_x = stoi(aux);
        
        archivo >> aux;
       
        coord_y = stoi(aux);
        
        Edificio* edificio = edificios->consulta(nombre);
        
        //std::cout <<edificio->devolver_nombre() <<edificio->devolver_madera() <<edificio->devolver_piedra() <<edificio->devolver_metal() << std::endl;
        //matriz[coord_x][coord_y]->mostrar();
        matriz[coord_x][coord_y]->construir(edificio);
       
        matriz[coord_x][coord_y]->cambiar_jugador(numero_jugador);
        
    };
}


void Mapa::procesar_archivo_ubicaciones_jugador(ifstream & archivo,  Jugador* jugador){
    std::string aux;
    int coord_x,coord_y;
    getline(archivo,aux,'(');
    archivo >> aux;
    coord_x = stoi(aux);
    archivo >> aux;
    coord_y = stoi(aux);
    jugador->mover_gratis(coord_x,coord_y);
    //std::cout <<"Jugador" << jugador->devolver_nombre() << " movido a: "<< coord_x << "," << coord_y << std::endl;
}