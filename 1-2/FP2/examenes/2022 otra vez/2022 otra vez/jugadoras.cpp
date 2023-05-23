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

void crearJugadora(tJugadoraPtr& jug, int id, string nombre, string apellido) {
	tJugadora jugadora;
	jugadora.nombre   = nombre;
	jugadora.apellido = apellido;
	jugadora.id       = id;
	jugadora.goles    = 0;
	*jug = jugadora;

}


void insertarJugadora(tJugadoraPtr j, tJugadoras& lj) {
	tJugadora aux;
	aux = *j;
	//*lj.array_jugadoras[lj.cont] = aux;

}

