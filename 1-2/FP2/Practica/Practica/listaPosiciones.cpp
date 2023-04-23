
#include "listaPosiciones.h"
using namespace std;

void iniciaListaPosiciones(tListaPosiciones& lp) {
	lp.cont = 0;
	lp.size = DIM;
	//crear array lp
}
void destruyeListaPosiciones(tListaPosiciones& lp) {

}
void insertar(tListaPosiciones& lp, const tPosicion& pos) {


}

int dameNumElem(const tListaPosiciones& lp) {
	return lp.cont;
}
tPosicion dameElem(const tListaPosiciones& lp, int i) {
	return lp.arrayPos[i];
}
void guardarListaBombillas(ofstream& archivo, const tListaPosiciones& lp) {

}
