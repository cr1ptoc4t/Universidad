#include "jugadoras.h"

void cargarJugadora(ifstream& archivo, tJugadora& j);
void mostrarJugadora(const tJugadora& j);
bool cargarJugadoras(ifstream& archivo, tJugadoras& lj)
{
	
	archivo >> lj.cont;
	for (int i = 0; i < lj.cont; i++) {

		tJugadora j;
		cargarJugadora(archivo, j);
		lj.array[i] = new tJugadora(j);
	}
	return true;
}

void cargarJugadora(ifstream& archivo, tJugadora& j) {
	archivo >> j.id >> j.nombre >> j.apellido >> j.goles;
}

void mostrarJugadora(const tJugadora& j)
{
	cout << j.nombre << " " << j.apellido << " "<<j.id<<" "<<j.goles<<endl;
}

void mostrarJugadoras(const tJugadoras& lj) {
	for (int i = 0; i < lj.cont; i++) {
		mostrarJugadora(*lj.array[i]);
	}
}

bool buscarJugadora(int id, const tJugadoras& lista_jug, tJugadora& jug)
{
	return false;
}

string getApellido(const tJugadora& jug)
{
	return jug.apellido;
}

void liberar_memoria(tJugadoras& lista_jugadoras)
{
	for(int i=0; i<lista_jugadoras.cont; i++)
		delete lista_jugadoras.array[i];
	lista_jugadoras.cont = 0;
}
