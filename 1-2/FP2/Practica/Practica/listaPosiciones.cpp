#include "listaPosiciones.h"
using namespace std;

void iniciaListaPosiciones(tListaPosiciones& lp) {
	lp.cont = 0;
	lp.size = DIM;
	lp.arrayPos = new tPosicion[DIM];
}

void destruyeListaPosiciones(tListaPosiciones& lp) {
	//mirar esto
	lp.size = 0;
	lp.cont = 0;
	delete [] lp.arrayPos;
	lp.arrayPos = nullptr;
}

void insertar(tListaPosiciones& lp, const tPosicion& pos) {
	if (lp.cont >= lp.size) {
		//ampliar
		//ESTO HAY QUE CAMBIARLO
		tPosicion* puntero = lp.arrayPos;
		lp.size *= 2;
		lp.arrayPos = new tPosicion[lp.size];
		for (int i = 0; i < lp.cont; i++) {
			lp.arrayPos[i] = puntero[i];
		}
		delete [] puntero;
	}
	lp.arrayPos[lp.cont] = pos;
	lp.cont++;


}

int dameNumElem(const tListaPosiciones& lp) {
	return lp.cont;
}
tPosicion dameElem(const tListaPosiciones& lp, int i) {
	return lp.arrayPos[i];
}
void guardarListaBombillas(ofstream& archivo, const tListaPosiciones& lp) {
	archivo << lp.cont << endl;
	for (int i = 0; i < lp.cont; i++)
		guardarPosicion(archivo, lp.arrayPos[i]);
}

void setCont(tListaPosiciones& lp, int c) {
	lp.cont = c;
}