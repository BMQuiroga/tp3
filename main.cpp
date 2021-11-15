#include <iostream>
#include "menu.h"

using namespace std;


int main(){
    /*
    Material *materiales=new Material [MAX_MATERIALES];
    int tope_material;
    Edificio *edificios=new Edificio[MAX_EDIFICIOS];
    int tope_edificio;
    procesar_archivo_materiales(materiales,tope_material);
    procesar_archivo_edificios(edificios,tope_edificio);
    */
    ListaEdificios edificios;
    ListaMateriales materiales;
    Mapa mapa(edificios);
    //if(tope_material != ERROR){
    int opcion_elegida;
    do{
        cout<< "Bienvenido a Andypolis :D !" << endl;
        cout << "Escriba una opcion" <<endl;
        mostrar_menu();
        cin >> opcion_elegida;
        while(!es_opcion_valida(opcion_elegida,5)){
            cout<<"No es valida "<< endl;
            mostrar_menu();
            cin >> opcion_elegida;

        }
        procesar_opcion(opcion_elegida,materiales,edificios,mapa);
    }while(opcion_elegida!=GUARDAR_Y_SALIR_MENU);
    //}
    //guardar_archivo_materiales(materiales, tope_material);
    //guardar_archivo_edificios(edificios, tope_edificio);
    return 0;
}

