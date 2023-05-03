#include "jugadoras.h"

bool cargarJugadoras(ifstream& archivo, tJugadoras& lj) {
	bool cargado = archivo.is_open();
	if (cargado) {
		archivo >> lj.cont;
		for (int i = 0; i < lj.cont; i++) {
			archivo >> lj.listaJugadoras->id;
			archivo >> lj.listaJugadoras->nombre;
			archivo >> lj.listaJugadoras->apellido;
			archivo >> lj.listaJugadoras->goles;
		}
	}
	return cargado;
}