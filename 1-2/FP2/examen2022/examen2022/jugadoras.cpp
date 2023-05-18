#include "jugadoras.h"

bool cargarJugadoras(ifstream& archivo, tJugadoras& lj) {
	bool cargado = archivo.is_open();
	if (cargado) {
		archivo >> lj.cont;
		for (int i = 0; i < lj.cont; i++) {
			tJugadora* ptr = new tJugadora;
			cargarJugadora(archivo, *ptr);
			lj.array_jugadoras[i] = ptr;
			
		}
	}
	return cargado;
}
void cargarJugadora(ifstream& archivo, tJugadora& j) {
	archivo >> j.id >> j.nombre >> j.apellido >> j.goles;
}