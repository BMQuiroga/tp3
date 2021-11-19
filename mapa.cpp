#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "mapa.h"
#include "menu.h"

Mapa::Mapa(ListaEdificios edificios){
    procesar_archivo_mapa();
    //procesar_archivo_ubicaciones(edificios);
}

void Mapa::definir(int coordenada_x,int coordenada_y){
    this->coordenada_x=coordenada_x;
    this->coordenada_y=coordenada_y;
    /*Casillero **aux=new Casillero*[coordenada_x];
    for(int i=0;i<coordenada_x;i++)
        aux[i]=new Casillero [coordenada_y];
    matriz=aux;*/

}

void Mapa::consultar_coordenadas(int coord_x,int coord_y){
    if(matriz[coord_x][coord_y]->devolver_tipo()=='C' || matriz[coord_x][coord_y]->devolver_tipo()=='B'||matriz[coord_x][coord_y]->devolver_tipo()=='M'){
        if (matriz[coord_x][coord_y]->tiene_material_o_edificio()){
            std::cout<<"Soy un casillero transitable y no me encuentro vacio"<<std::endl;
            std::cout<<"Soy un(a) "<<matriz[coord_x][coord_y]->devolver_material_o_edificio()<<" y me encuentro en el casillero consultado"<<std::endl;
        }
        else if (!matriz[coord_x][coord_y]->tiene_material_o_edificio())
            std::cout<<"Soy un casillero transitable y me encuentro vacio"<<std::endl;
    
    }
    else if(matriz[coord_x][coord_y]->devolver_tipo()=='T'){
        if (matriz[coord_x][coord_y]->tiene_material_o_edificio()){
            std::cout<<"Soy un casillero construible y no me encuentro vacio"<<std::endl;
            std::cout<<"Soy un(a) "<<matriz[coord_x][coord_y]->devolver_material_o_edificio()<<" y me encuentro en el casillero consultado"<<std::endl;
        }
        else if (!matriz[coord_x][coord_y]->tiene_material_o_edificio())
            std::cout<<"Soy un casillero construible y me encuentro vacio"<<std::endl;
    }
    else 
        std::cout<<"Soy un casillero intransitable y me encuentro vacio"<<std::endl;
}

void Mapa::llamar_lluvia(){
    srand((unsigned)time(0));
    int cantidad_material_piedra=generador_de_numeros_aleatorios(1,3);//1+rand()%1;
    int cantidad_material_madera=generador_de_numeros_aleatorios(0,2);//rand()%1;
    int cantidad_material_metal=generador_de_numeros_aleatorios(2,5);//2+rand()%2;
    //std::cout<<cantidad_material_piedra<<" "<<cantidad_material_madera<<" "<<cantidad_material_metal<<std::endl;
    lluvia(cantidad_material_piedra,"piedra");
    lluvia(cantidad_material_madera,"madera");
    lluvia(cantidad_material_metal,"metal");
    std::cout<<"Lluvia llamada satisfactoriamente"<<std::endl;
    std::cout<<"-------------------------------------------------"<<std::endl;
}

void Mapa::lluvia(int cantidad, std::string material){
    int error=0;//Para evitar while true, cuando se queda sin casilleros transitables vacios
    while(cantidad){
        error++;
        int coord_x=rand()%coordenada_x;
        int coord_y=rand()%coordenada_y;
        if (matriz[coord_x][coord_y]->devolver_tipo()=='C' && (!matriz[coord_x][coord_y]->tiene_material_o_edificio())){
            Material mat(material,1);
            matriz[coord_x][coord_y]->poner_material(mat);
            cantidad--;
        }
        if (error>100){
            cantidad=0;
            std::cout<<"No quedan mas caminos libres!"<<std::endl;
        }
    }
}

void Mapa::recolectar(Jugador jugador){//RECOLECTAR MATERIAL TIENE QUE ESTAR EN LAGO Y CAMINO PERO NO HACER NADA
    for(int i=0;i<coordenada_x;i++){
        for(int j=0;j<coordenada_y;j++){
            if(matriz[i][j]->devolver_tipo()=='T' && matriz[i][j]->devolver_jugador()==jugador.devolver_nombre())
                matriz[i][j]->recolectar_material(jugador); //MANDAR PARAMETRO PIEDRA METAL MADERA
        }
    }
    jugador.restar_energia(20);
}

void Mapa::demoler(ListaEdificios edificios, int coord_x,int coord_y,Jugador jugador){
    if (matriz[coord_x][coord_y]->tiene_material_o_edificio() && matriz[coord_x][coord_y]->devolver_tipo()=='T'){
        //HAY QUE HACERLA DEVUELTA CON LAS LISTAS DE MATERIALES
        /*int piedra=devolver_indice_materiales(materiales,"piedra");
        int madera=devolver_indice_materiales(materiales,"madera");
        int metal=devolver_indice_materiales(materiales,"metal");*/

        if (jugador.devolver_nombre() == matriz[coord_x][coord_y]->devolver_jugador()) {
            std::cout << matriz[coord_x][coord_y]->devolver_material_o_edificio() << " demolido/a satisfactoriamente." << std::endl;
            matriz[coord_x][coord_y]->demoler(jugador);
            matriz[coord_x][coord_y]->cambiar_jugador(0);
            jugador.restar_energia(15);  
        } else {
            std::cout << "No podes demoler un edificio que no es tuyo." << std::endl;
        }
    }
    else
        std::cout<<"No hay ningun edificio en este casillero!"<<std::endl;
}

void Mapa::mostrar_mapa_edificios_y_materiales(int coord_x, int coord_y, Jugador jugador1, Jugador jugador2){
    if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="piedra")
        std::cout<<" \033[33;1mS\033[0m";//⛏️
    else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="madera")
        std::cout<<" \033[33;1mW\033[0m";//🪓
    else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="metal")
        std::cout<<" \033[33;1mI\033[0m";//⚙️
    else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="andycoins")
        std::cout<<" \033[33;1mC\033[0m";//⚙️
    else{
        //SETEA EL COLOR DEPENDIENDO DE QUIEN SEA EL EDIFICIO, SI NO ES UN MATERIAL
        if(matriz[coord_x][coord_y]->devolver_jugador()==jugador1.devolver_nombre())
            std::cout<<"\033[31;1m"; //ROJO PARA J1
        if(matriz[coord_x][coord_y]->devolver_jugador()==jugador2.devolver_nombre())
            std::cout<<"\033[35;1m"; //VIOLETA PARA J2


        if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="planta electrica")
            std::cout<<"P\033[0m";
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="obelisco")
            std::cout<<"O\033[0m";
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="escuela")
            std::cout<<"E\033[0m";
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="fabrica")
            std::cout<<"F\033[0m";
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="aserradero")
            std::cout<<"A\033[0m";
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="mina")
            std::cout<<"M\033[0m";
        else if(matriz[coord_x][coord_y]->devolver_material_o_edificio()=="mina oro")
            std::cout<<"\033[0m";
        else
            std::cout<<"#\033[0m";
    }
}   

void Mapa::mostrar_mapa(Jugador jugador1, Jugador jugador2){
    std::cout<<"Ademas de los mencionados en el pdf, se usan: R para camino, T para terreno y L para lago"<<std::endl;
    std::cout<<"Columna: ";
    for(int k=0;k<coordenada_y;k++)
        std::cout<<k<<" ";
    std::cout<<std::endl;
    for(int i=0;i<coordenada_x;i++){
        if(i<10)
            std::cout<<"Fila "<<i<<": ";
        else
            std::cout<<"Fila "<<i<<":";
        //std::cout<<coordenada_y<<std::endl;
        for(int j=0;j<coordenada_y;j++){
            //std::cout<<"ENTRA"<<std::endl;
            if(i==jugador1.devolver_coordenada_x() && j==jugador1.devolver_coordenada_y())
                std::cout<<" \033[31;1mJ\033[0m";
            else if(i==jugador2.devolver_coordenada_x() && j==jugador2.devolver_coordenada_y())
                std::cout<<" \033[31;1mU\033[0m";
            else if (matriz[i][j]->tiene_material_o_edificio())
                mostrar_mapa_edificios_y_materiales(i,j,jugador1,jugador2);
            else {
                if (matriz[i][j]->devolver_tipo()=='C')
                    std::cout<<" \033[1;38;5;136mR\033[0m";
                else if (matriz[i][j]->devolver_tipo()=='T')
                    std::cout<<" \033[32;1mT\033[0m";
                else
                    std::cout<<" \033[34;1mL\033[0m";
            }
        }
        std::cout<<std::endl;
    }
}

void Mapa::destruir(){
    for(int i=0;i<coordenada_x;i++){
    	for(int j=0;j<coordenada_y;j++)
            delete matriz[i][j];
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Mapa::procesar_archivo_mapa(){
    char letra;
    int coordenadax,coordenaday;
    std::ifstream archivo_mapa("mapa.txt",std::ios::in);
    if(!archivo_mapa)
        std::cout<<"El archivo no se abrio correctamente"<<std::endl;
    else{
        archivo_mapa>>coordenadax;
        archivo_mapa>>coordenaday;
        
        definir(coordenadax,coordenaday);
        
        //std::cout<<coordenada_x<<" "<<coordenada_y<<std::endl;

        Casillero*** casilla;
        casilla=new Casillero**[coordenada_x];
        for(int i=0;i<coordenada_x;i++){
            casilla[i]=new Casillero*[coordenada_y];
            for(int j=0;j<coordenada_y;j++){
                archivo_mapa>>letra;
                //std::cout<<i<<" "<<j<<std::endl;
                if(letra=='T')
                    casilla[i][j]=new CasilleroConstruible();
                else if(letra=='C')
                    casilla[i][j]=new CasilleroTransitable("Camino");
                else if(letra=='B')
                    casilla[i][j]=new CasilleroTransitable("Betun");
                else if(letra=='M')
                    casilla[i][j]=new CasilleroTransitable("Muelle");
                else if(letra=='L')
                    casilla[i][j]=new CasilleroInaccesible();
                else
                    std::cout<<"ERROR";
            }     
        }
        this->matriz=casilla;
    }
}
bool Mapa::casillero_ocupado(Jugador jugador, int coord_x, int coord_y){
    return(matriz[jugador.devolver_coordenada_x()][jugador.devolver_coordenada_y()] == matriz[coord_x][coord_y]);

}


void Mapa::construir(ListaEdificios edificios, Jugador jugador, Jugador rival){
    std::string edificio,ingreso;
    int coord_x,coord_y;
    std::cout<<"Ingrese el nombre del edificio que desea construir"<<std::endl;
    std::cin>>edificio;
    if(se_puede_construir(edificios,edificio,jugador)){
        std::cout<<"Se puede construir el edificio, desea hacerlo?\n1. Construir el edificio\n2. Salir al menú"<<std::endl;
        std::cin>>ingreso;
        if(ingreso=="1"){
            std::cout<<"Ingrese la coordenada x (entre 0 y "<<coordenada_x-1<<")"<<std::endl;
            std::cin>>coord_x;
            std::cout<<"Ingrese la coordenada y (entre 0 y "<<coordenada_y-1<<")"<<std::endl;
            std::cin>>coord_y;
            if(!casillero_ocupado(jugador, coord_x, coord_y) && !casillero_ocupado(rival, coord_x, coord_y)){
                if(coord_x>=0&&coord_x<coordenada_x&&coord_y>=0&&coord_y<coordenada_y){
                    if(matriz[coord_x][coord_y]->devolver_tipo()=='T'){
                        realizar_construccion(edificios,coord_x,coord_y,edificio,edificios.buscar_indice(edificio),jugador);
                        matriz[coord_x][coord_y]->cambiar_jugador(jugador.devolver_nombre());
                    }
                    else
                        std::cout<<"No se puede construir en esa coordenada!"<<std::endl;
                }
                else
                    std::cout<<"Coordenadas fuera de rango!"<<std::endl;
            }
        }
    }
}

bool Mapa::se_puede_construir(ListaEdificios edificios,std::string nombre,Jugador jugador){
    bool es_valido_construir=false;
    int indice_edificio=edificios.buscar_indice(nombre);
    if(indice_edificio==-1){
        std::cout<<"No existe un edificio con ese nombre!"<<std::endl;
        return false;
    }
    // int indice_piedra=jugador.devolver_materiales()->buscar_indice("piedra");
    // int indice_madera=jugador.devolver_materiales()->buscar_indice("madera");
    // int indice_metal=jugador.devolver_materiales()->buscar_indice("metal");
    int indice_piedra=jugador.devolver_materiales().buscar_indice("piedra");
    int indice_madera=jugador.devolver_materiales().buscar_indice("madera");
    int indice_metal=jugador.devolver_materiales().buscar_indice("metal");
    
    bool hay_piedra=false,hay_madera=false,hay_metal=false;
    
    // hay_piedra=(jugador.devolver_materiales()->consulta(indice_piedra).devolver_cantidad()>=edificios.consulta(indice_edificio).devolver_piedra());
    // hay_madera=(jugador.devolver_materiales()->consulta(indice_madera).devolver_cantidad()>=edificios.consulta(indice_edificio).devolver_madera());
    // hay_metal=(jugador.devolver_materiales()->consulta(indice_metal).devolver_cantidad()>=edificios.consulta(indice_edificio).devolver_metal());
    hay_piedra=(jugador.devolver_materiales().consulta(indice_piedra).devolver_cantidad()>=edificios.consulta(indice_edificio).devolver_piedra());
    hay_madera=(jugador.devolver_materiales().consulta(indice_madera).devolver_cantidad()>=edificios.consulta(indice_edificio).devolver_madera());
    hay_metal=(jugador.devolver_materiales().consulta(indice_metal).devolver_cantidad()>=edificios.consulta(indice_edificio).devolver_metal());

    if(hay_madera&&hay_piedra&&hay_metal){
        if(edificios.consulta(indice_edificio).devolver_maximos_permitidos()>edificios_construidos(nombre,jugador)){
            es_valido_construir=true;
        }
        else{
            std::cout<<"Ya se alcanzo el limite para ese edificio!"<<std::endl;
        }
    }
    else{
        std::cout<<"No alcanzan los materiales!"<<std::endl;
    }
    return es_valido_construir;
}

int Mapa::edificios_construidos(std::string nombre,Jugador jugador){
    int contador=0;
    for (int i=0;i<coordenada_x;i++){
        for(int j=0;j<coordenada_y;j++){
            if(matriz[i][j]->devolver_material_o_edificio()==nombre && matriz[i][j]->devolver_tipo()=='T' && matriz[i][j]->devolver_jugador()==jugador.devolver_nombre())
                contador++;
        }
    }
    return contador;
}

/*int Mapa::devolver_indice_edificios(Edificio edificios[],std::string nombre){//VA A PASAR A SER PARTE DE LISTAEDIFICIOS.CPP
    int indice=-1;
    for(int i=0;i<100;i++){
        if (edificios[i].devolver_nombre()==nombre)
            indice=i;
    }
    return indice;
}*/

/*int Mapa::devolver_indice_materiales(Material materiales[],std::string nombre){//VA A PASAR A SER PARTE DE LISTAMATERIALES.CPP
    int indice=-1;
    for(int i=0;i<100;i++){
        if (materiales[i].devolver_nombre()==nombre)
            indice=i;
    }
    return indice;
}*/

void Mapa::realizar_construccion(ListaEdificios edificios,int coord_x, int coord_y, std::string nombre, int indice_edificio, Jugador jugador){
    // int indice_piedra=jugador.devolver_materiales()->buscar_indice("piedra");
    // int indice_madera=jugador.devolver_materiales()->buscar_indice("madera");
    // int indice_metal=jugador.devolver_materiales()->buscar_indice("metal");
    int indice_piedra=jugador.devolver_materiales().buscar_indice("piedra");
    int indice_madera=jugador.devolver_materiales().buscar_indice("madera");
    int indice_metal=jugador.devolver_materiales().buscar_indice("metal");

    // jugador.devolver_materiales()->obtener_nodo(indice_piedra)->restar_cantidad(edificios.consulta(indice_edificio).devolver_piedra());
    // jugador.devolver_materiales()->obtener_nodo(indice_madera)->restar_cantidad(edificios.consulta(indice_edificio).devolver_madera());
    // jugador.devolver_materiales()->obtener_nodo(indice_metal)->restar_cantidad(edificios.consulta(indice_edificio).devolver_metal());
    jugador.devolver_materiales().obtener_nodo(indice_piedra)->restar_cantidad(edificios.consulta(indice_edificio).devolver_piedra());
    jugador.devolver_materiales().obtener_nodo(indice_madera)->restar_cantidad(edificios.consulta(indice_edificio).devolver_madera());
    jugador.devolver_materiales().obtener_nodo(indice_metal)->restar_cantidad(edificios.consulta(indice_edificio).devolver_metal());

    matriz[coord_x][coord_y]->construir(edificios.consulta(indice_edificio));
    std::cout<<nombre<<" construido/a satisfactoriamente!"<<std::endl;
}

void Mapa::listar_edificios_construidos(ListaEdificios edificios, Jugador jugador){
    int limite=edificios.devolver_cantidad();
    //std::cout<<limite<<std::endl;
    for(int i=1;i<limite+1;i++){//
        std::string nombre=edificios.consulta(i).devolver_nombre();
        int construidos=edificios_construidos(nombre,jugador);
        if (construidos&&nombre!="0"){
            std::cout<<"Nombre: "<<nombre<<", Cantidad construida: "<<construidos<<std::endl;
            std::cout<<"Coodenadas:";
            //for(int i=0;i<construidos;i++)
            mostrar_coordenadas(nombre,jugador);
            
        }
    }
}

void Mapa::mostrar_coordenadas(std::string nombre,Jugador jugador){
    for(int i=0;i<coordenada_x;i++){
        for(int j=0;j<coordenada_y;j++){
            if(matriz[i][j]->devolver_material_o_edificio()==nombre && matriz[i][j]->devolver_jugador()==jugador.devolver_nombre())
                std::cout<<" ("<<i<<", "<<j<<") ";
        }
    }
    std::cout<<"\n-------------------------------------------------"<<std::endl;
}

void Mapa::menu_demoler(ListaEdificios edificios, Jugador jugador){
    int coord_x,coord_y;
    std::cout<<"Ingrese la coordenada x"<<std::endl;
    std::cin>>coord_x;
    std::cout<<"Ingrese la coordenada y"<<std::endl;
    std::cin>>coord_y;
    demoler(edificios, coord_x,coord_y,jugador);
}

void Mapa::menu_consultar_coordenada(){
    int coord_x,coord_y;
    std::cout<<"Ingrese la coordenada x"<<std::endl;
    std::cin>>coord_x;
    std::cout<<"Ingrese la coordenada y"<<std::endl;
    std::cin>>coord_y;
    consultar_coordenadas(coord_x,coord_y);
}

void Mapa::listar_todos_los_edificios(ListaEdificios edificios, Jugador jugador1, Jugador jugador2){
    int limite=edificios.devolver_cantidad();
    //std::cout<<limite<<std::endl;
    for(int i=1;i<limite+1;i++){
        std::string nombre=edificios.consulta(i).devolver_nombre();
        int cantidad_piedra=edificios.consulta(i).devolver_piedra();
        int cantidad_madera=edificios.consulta(i).devolver_madera();
        int cantidad_metal=edificios.consulta(i).devolver_metal();
        int construidos1=edificios_construidos(nombre,jugador1);
        int construidos2=edificios_construidos(nombre,jugador2);
        int maximos_permitidos=edificios.consulta(i).devolver_maximos_permitidos();
        
        
        std::cout<<"Nombre: "<<nombre<</*" ,Cantidad construida: "<<construidos<<*/std::endl;
        std::cout<<"Para construirlo se requieren "<<cantidad_piedra<<" de piedra, "<<cantidad_madera<<" de madera y "<<cantidad_metal<<" de metal."<<std::endl;
        //std::cout<<"Hay "<</*construidos<<*/" construidos y se pueden construir "<<maximos_permitidos/*-construidos*/<<" mas antes de llegar al limite."<<std::endl;
        std::cout<<"El jugador 1 construyó "<<construidos1<<" y puede construir "<<maximos_permitidos-construidos1<<" mas antes de llegar al limite."<<std::endl;
        std::cout<<"El jugador 2 construyó "<<construidos2<<" y puede construir "<<maximos_permitidos-construidos2<<" mas antes de llegar al limite."<<std::endl;
        edificios.consulta(i).imprimir_brinda_materiales();
        std::cout<<"-------------------------------------------------"<<std::endl;
    }
}

/*void Mapa::procesar_archivo_ubicaciones(ListaEdificios edificios){
    std::string nombre;
    int coord_x;
    int coord_y;
    std::string aux;
    std::ifstream archivo_ubicaciones("ubicaciones.txt",std::ios::in);
    if(!archivo_ubicaciones)
        std::cout<<"El archivo no se abrio correctamente"<<std::endl;
    else{
        while(archivo_ubicaciones>>nombre){
            if (nombre=="planta"){
                archivo_ubicaciones>>nombre;
                nombre="planta electrica";
            }

            //aux=archivo_ubicaciones.get();
            getline(archivo_ubicaciones,aux,'(');
            archivo_ubicaciones>>aux;
            coord_x=stoi(aux);
            archivo_ubicaciones>>aux;
            coord_y=stoi(aux);
            if (matriz[coord_x][coord_y]->devolver_tipo()=='T'){
                int indice=edificios.buscar_indice(nombre);
                matriz[coord_x][coord_y]->construir(edificios.consulta(indice));
            }
            if (matriz[coord_x][coord_y]->devolver_tipo()=='C'){
                matriz[coord_x][coord_y]->poner_material(nombre);
            }
        }
    }
}*/



void Mapa::reescribir_ubicaciones(){
    std::ofstream archivo_ubicaciones;
    std::string material_o_edificio;
    archivo_ubicaciones.open("ubicaciones.txt");
    if(!archivo_ubicaciones.is_open()){ //no existe el archivo
        std::cout <<"No se encontro el archivo ubicaciones" <<std::endl;
    }
    else{
        for(int i=0;i<coordenada_x;i++){
            for(int j=0;j<coordenada_y;j++){
                if(matriz[i][j]->tiene_material_o_edificio()){
                    material_o_edificio=matriz[i][j]->devolver_material_o_edificio();
                    archivo_ubicaciones<<material_o_edificio<<" ("<<i<<", "<<j<<")"<<std::endl;
                }
            }
        }
    archivo_ubicaciones.close();
    }
}

void Mapa::menu_atacar(Jugador jugador, Jugador rival){
    bool destruido;
    int coord_x,coord_y;
    std::cout<<"Ingrese la coordenada x del edificio enemigo que desea atacar"<<std::endl;
    std::cin>>coord_x;
    std::cout<<"Ingrese la coordenada y"<<std::endl;
    std::cin>>coord_y;
    if(matriz[coord_x][coord_y]->devolver_jugador()==rival.devolver_nombre() && matriz[coord_x][coord_y]->tiene_material_o_edificio()){
        if(jugador.devolver_energia()>=30){
            if(jugador.devolver_materiales().consulta(jugador.devolver_materiales().buscar_indice("bombas")).devolver_cantidad()>=1){
                destruido=matriz[coord_x][coord_y]->atacar();
                if(destruido)
                    matriz[coord_x][coord_y]->cambiar_jugador(0);
                jugador.restar_energia(30);
                jugador.devolver_materiales().consulta(jugador.devolver_materiales().buscar_indice("bombas")).sumar_cantidad(-1);
            }
            else
                std::cout<<"No tienes bombas!"<<std::endl;
        }
        else
            std::cout<<"No tienes energia suficiente!"<<std::endl;
    }
    else
        std::cout<<"No hay un edificio enemigo en esa posicion!"<<std::endl;


}

void Mapa::menu_reparar(Jugador jugador){
    int coord_x,coord_y;
    std::cout<<"Ingrese la coordenada x del edificio que desea reparar"<<std::endl;
    std::cin>>coord_x;
    std::cout<<"Ingrese la coordenada y"<<std::endl;
    std::cin>>coord_y;
    if(matriz[coord_x][coord_y]->devolver_jugador()==jugador.devolver_nombre() && matriz[coord_x][coord_y]->tiene_material_o_edificio()){
        if((matriz[coord_x][coord_y]->devolver_material_o_edificio()=="mina" || matriz[coord_x][coord_y]->devolver_material_o_edificio()=="fabrica")){
            matriz[coord_x][coord_y]->reparar(jugador);
        }
        else
            std::cout<<"Ese edificio no está dañado!"<<std::endl;
    }
    else
        std::cout<<"No hay un edificio propio en esa posicion!"<<std::endl;




}
