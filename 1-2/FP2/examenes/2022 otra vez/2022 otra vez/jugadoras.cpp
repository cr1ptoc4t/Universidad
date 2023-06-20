#include "jugadoras.h"
#include <iostream>
using namespace std;
void mostrarJugadora(tJugadora& j);
void cargarJugadoras(ifstream& archivo, tJugadoras& jugadora)
{
	tJugadora j;
	archivo >> jugadora.cont;
	for (int i = 0; i < jugadora.cont; i++) {
		archivo >> j.id >> j.nombre >> j.apellido >> j.goles;
		jugadora.jugadoras[i] = new tJugadora(j);
	}
}

void mostrarJugadoras(const tJugadoras& lj)
{
	cout << lj.cont;
	for (int i = 0; i < lj.cont; i++) {
		mostrarJugadora(*lj.jugadoras[i]);
	}
}

void crearJugadora(tJugadoraPtr& jug, int id, string nombre, string apellido)
{
	jug->id = id;
	jug->nombre = nombre;
	jug->apellido = apellido;
}

void insertarJugadora(tJugadoraPtr j, tJugadoras& lj)
{
}

void liberar_memoria(tJugadoras& lista_jugadoras)
{
	for (int i = 0; i < lista_jugadoras.cont; i++){
		delete lista_jugadoras.jugadoras[i];
		lista_jugadoras.jugadoras[i] = nullptr;
	}
	lista_jugadoras.cont = 0;
}

void mostrarJugadora(tJugadora& j){
	cout << j.id << " " << j.nombre << " " << j.apellido << " " << j.goles << endl;
}