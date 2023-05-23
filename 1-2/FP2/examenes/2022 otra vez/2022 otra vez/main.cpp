using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "liga.h"



//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>

void fichaJugadoras(ifstream& archivo, tJugadoras& jugadoras, tLiga& liga);

void resuelve_caso() {
    tJugadoras jugadoras;
    tLiga liga;
    ifstream archivo;


    archivo.open("datos.in");
    cargarJugadoras(archivo, jugadoras);
    cargarEquipos(archivo, liga);
        
    mostrarJugadoras(jugadoras);
    mostrarEquipos(liga);
    
    
    tEquipo campeon = campeonLiga(archivo, liga);
    //mostrar campeon
    cout << "El campeon es "<<getNombre(campeon)<<endl;

    //aumentar presupuesto
    string equipo;
    archivo >> equipo;
    aumentarPresupuesto(equipo, liga);

    //cout << endl << "a quien quieres aumentar el presupuesto?" << endl;
    //cin >> equipo;
   //aumentarPresupuesto(equipo, liga);



    fichaJugadoras(archivo, jugadoras, liga);

    //comenzamos con los fichajes
    cout << "comenzamos con los fichajes: " << endl<< "cuantos fichajes quieres hacer? ";
    
    
    //leo el numero de fichajes
    int fichajes, id;
    cin >> fichajes;

    string nombre, apellido;


    for (int i = 0; i < fichajes; i++){
        cout << "Fichaje " << i <<"de "<<fichajes << endl;
        cout << "equipo: ";
        cin >> equipo;
        cout << "id: ";
        cin >> id;
        cout << "nombre: ";
        cin >> nombre;
        cout << "apellido: ";
        cin >> apellido;
        
        ficharJugadora(equipo, id, nombre, apellido, liga, jugadoras);
        
    }

    mostrarJugadoras(jugadoras);
    mostrarEquipos(liga);

    //equipo descendido
    cout << endl << "a quien quieres descender? " << endl;

    string descenso;
    //cin >> descenso;

    //descensoEquipo(...);

    mostrarJugadoras(jugadoras);
    mostrarEquipos(liga);

        /*
    cout << "Se libera memoria dinamica" << endl;
    liberar_memoria(...);*/
}



int main() {
    resuelve_caso();
    /*
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelve_caso();
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
#endif
    //	_CrtDumpMemoryLeaks();
    return 0;
    */
}



void fichaJugadoras(ifstream& archivo, tJugadoras& jugadoras, tLiga& liga) {
    int numFich, id, goles; string nombre, apellido, equipo;
    archivo >> numFich;
    for (int i = 0; i < numFich; i++) {
        archivo >> equipo >> id >> nombre >> apellido >> goles;
        ficharJugadora(equipo,id,nombre, apellido, liga, jugadoras);
    }

}