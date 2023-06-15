#include <iostream>
#include "liga.h"
using namespace std;

void fichajes(ifstream& archivo, tJugadoras& lista_jugadoras, tLiga liga);


int main() {
	tJugadoras lista_jugadoras;
	tLiga liga;
	ifstream archivo;
	tEquipo equipo_campeon;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	archivo.open("entrada.txt");
	bool abierto = archivo.is_open();
	if (abierto)
	{
		cargarJugadoras(archivo, lista_jugadoras);
		mostrarJugadoras(lista_jugadoras);
		cargarEquipos(archivo, liga);
		mostrarEquipos(liga, lista_jugadoras);
		
		//Equipo campeón
		equipo_campeon = campeonLiga(archivo, liga);
		cout << "El campeón de la liga es: " << getNombre(equipo_campeon)
			<< " con " << getPuntos(equipo_campeon) << " puntos" <<
			endl << endl;

		/*
		//Aumentar presupuesto
		string equipo;
		archivo >> equipo;
		aumentarPresupuesto(liga, equipo);
		mostrarEquipos(liga, lista_jugadoras);
		//Fichajes
		fichajes(archivo, lista_jugadoras, liga);
		mostrarJugadoras(lista_jugadoras);
		mostrarEquipos(liga, lista_jugadoras);
		//Descenso equipo
		string descenso;
		archivo >> descenso;
		descensoEquipo(descenso, liga, lista_jugadoras);
		cout << "Desciende el equipo " << descenso << endl << endl;
		mostrarJugadoras(lista_jugadoras);
		mostrarEquipos(liga, lista_jugadoras);
		cout << "Se libera memoria dinámica" << endl;
		*/
		liberar_memoria(liga);
		liberar_memoria(lista_jugadoras);
		archivo.close();
	}
	else
		cout << "Archivo no abierto" << endl;
	return 0;
}

void fichajes(ifstream& archivo, tJugadoras& lista_jugadoras, tLiga liga)
{
}
