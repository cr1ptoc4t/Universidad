#include "listaPartidas.h"
using namespace std;

void iniciaListaPartidas(tListaPartidas& listaPartidas) {
	listaPartidas.nElem = 0;
	for (int i = 0; i < MAX_PARTIDAS; i++) {
		listaPartidas.datos[i] = new tPartida;
	}
}

void cargarListaPartidas(ifstream& archivo, tListaPartidas& listaPartidas) {
	archivo >> listaPartidas.nElem;
	for (int i = 0; i < listaPartidas.nElem;i++) {
		cargarPartida(archivo,*listaPartidas.datos[i]); //creo que el puntero va asi
	}
}

void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida) {

}

int buscaPos(const tListaPartidas& listaPartidas, int nivel) {
	return 0;
}

tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos) {
	return listaPartidas.datos[pos];
}

int dameNumElem(const tListaPartidas& listaPartidas) {
	return listaPartidas.nElem;
}

void eliminarPartida(tListaPartidas& listaPartidas, const tPartida& partida) {

}

void guardarListaPartidas(ofstream& archivo, const tListaPartidas& listaPartidas) {

}

void destruyeListaPartidas(tListaPartidas& listaPartidas) {

}