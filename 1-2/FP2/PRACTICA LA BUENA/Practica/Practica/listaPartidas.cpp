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
		iniciaPartida(*listaPartidas.datos[i]);
		cargarPartida(archivo,*listaPartidas.datos[i]); //creo que el puntero va asi
	}
}

void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida) {
	int indice = buscaPos(listaPartidas, partida.nivel);
	//insertar
	for (int i = listaPartidas.nElem; i > indice;i--) {
		listaPartidas.datos[i + 1] = listaPartidas.datos[i];
	}
	*listaPartidas.datos[indice] = partida;

}

int buscaPos(const tListaPartidas& listaPartidas, int nivel) {
	int indice = 0;
	while (operator<(*listaPartidas.datos[indice], nivel) && indice < listaPartidas.nElem)
		indice++;

	return indice;
}

tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos) {
	return listaPartidas.datos[pos];
}

int dameNumElem(const tListaPartidas& listaPartidas) {
	return listaPartidas.nElem;
}

void eliminarPartida(tListaPartidas& listaPartidas, const tPartida& partida) {
	int posicion = buscaPos(listaPartidas,getNivel(partida));
	for (int i = posicion; i < listaPartidas.nElem; i++)
		listaPartidas.datos[i] = listaPartidas.datos[i + 1];
	listaPartidas.nElem--;
}

void actualizaBombillas(tPartida& partida) {
	tPosicion pos;
	destruyeListaPosiciones(partida.listaBombillas);
	iniciaListaPosiciones(partida.listaBombillas);
	partida.listaBombillas.cont = 0;
	for (int i = 0; i <getNumFilas(partida.tablero); i++) {
		for (int j = 0; j < getNumCols(partida.tablero); j++) {

			if (esBombilla(celdaEnPos(partida.tablero,i,j))){
				//si hay bombilla en el tablero la metemos al array e incrementamos
				//iniciaPosicion(partida.listaBombillas.arrayPos[dameNumElem(partida.listaBombillas)], i, j);	//GETTER
				//incrementamos contador 
				iniciaPosicion(pos, i, j);
				insertar(partida.listaBombillas, pos );
				//partida.listaBombillas.cont++;
			}
		}
	}
}
void guardarListaPartidas(ofstream& archivo, const tListaPartidas& listaPartidas) {
	archivo << dameNumElem(listaPartidas) << endl;
	for (int i = 0; i < dameNumElem(listaPartidas); i++) {
		guardarPartida(archivo, *listaPartidas.datos[i]);
	}	
}

void destruyeListaPartidas(tListaPartidas& listaPartidas) {
	for (int i = 0; i < dameNumElem(listaPartidas); i++) {
		destruyePartida(*listaPartidas.datos[i]);
	}
	listaPartidas.nElem = 0;
}