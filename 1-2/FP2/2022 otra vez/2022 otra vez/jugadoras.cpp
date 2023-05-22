#include "jugadoras.h"

void cargarJugadora(ifstream& archivo, tJugadora& jugadora);

void cargarJugadoras(ifstream& archivo, tJugadoras& jugadoras)
{	
	if (archivo.is_open()) {
		archivo >> jugadoras.cont;
		for (int i = 0; i < jugadoras.cont; i++){
			tJugadora* ptr = new tJugadora;
			cargarJugadora(archivo, *ptr);
			jugadoras.array_jugadoras[i] = ptr;
		}
	}
}

void mostrarJugadoras(const tJugadoras& lj)
{
	cout << "- - - - -" << endl << "JUGADORAS" << endl << "- - - - -" << endl;

	for (int i = 0; i < lj.cont; i++)
		cout << "Nombre: " << lj.array_jugadoras[i]->nombre<<" " <<lj.array_jugadoras[i]->apellido<<". Goles: "<< lj.array_jugadoras[i]->goles<<endl;
}

void cargarJugadora(ifstream& archivo, tJugadora& jugadora) {
	archivo >> jugadora.id >> jugadora.nombre >> jugadora.apellido >> jugadora.goles;
}

void crearJugadora(tJugadora& jug, int id, string nombre, string apellido) {
	jug.nombre   = nombre;
	jug.apellido = apellido;
	jug.id       = id;
	jug.goles    = 0;
}


void insertarJugadora(tJugadora j, tJugadoras& lj) {

	lj.array_jugadoras[lj.cont]->apellido = j.apellido;
	lj.array_jugadoras[lj.cont]->goles = j.goles;
	lj.array_jugadoras[lj.cont]->nombre = j.nombre;
	lj.array_jugadoras[lj.cont]->id = j.id;


}