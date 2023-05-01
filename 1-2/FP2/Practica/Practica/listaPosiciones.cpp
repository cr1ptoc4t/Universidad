#include "listaPosiciones.h"
using namespace std;

void iniciaListaPosiciones(tListaPosiciones& lp) {
	lp.cont = 0;
	lp.size = DIM;
	lp.arrayPos = new tPosicion[DIM];
}

void destruyeListaPosiciones(tListaPosiciones& lp) {
	lp.size = 0;
	lp.cont = 0;
	delete [] lp.arrayPos;
	lp.arrayPos = nullptr;
}


//este metodo no lo estamos usando y deberíamos
void insertar(tListaPosiciones& lp, const tPosicion& pos) {
	if (lp.cont >= lp.size) {
		//ampliar
		tPosicion* aux = lp.arrayPos;
		//doblamos espacio
		lp.size = lp.size*2;
		//construimos nuevo
		lp.arrayPos = new tPosicion[lp.size];
		//reemplazamos los valores antiguos
		for (int i = 0; i < lp.cont; i++) {
			lp.arrayPos[i] = aux[i];
		}
		//eliminamos el aux para liberar espacio en memoria
		delete [] aux;
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