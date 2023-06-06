#include "taller.h"

void ampliar(tListaCoches& lc);
void cargarCoches(ifstream& archivo, tListaCoches& lc)
{
	tCoche c;
	int num;
	archivo >> num;
	lc.cont = 0;
	for (int i = 0; i < num; i++) {
		archivo >> c.matricula >> c.averia >> c.estado;
		if (i == lc.cap)
			ampliar(lc);

		lc.coches[i] = c;
		lc.cont++;
	}
}

void iniciarListaCoches(tListaCoches& lc)
{
	lc.cont = 0;
	lc.cap = 0;
	//lc.coches = new tCoche[];
}

void mostrarListaCoches(tListaCoches& lc)
{
}

tListaSeccion crearListaSeccion(tListaCoches& lc, string tipo)
{
	return tListaSeccion();
}

void liberaListaCoches(tListaCoches& lc)
{
}

void marcarTerminados(tListaSeccion& ls)
{
}

void mostrarListaSeccion(const tListaSeccion& ls)
{
}

bool finReparacion(tListaCoches& lc, string matricula)
{
	return false;
}
void ampliar(tListaCoches& lc) {
	tCoche* aux = new tCoche[lc.cap + 5];
	for (int i = 0; i < lc.cont; i++)
		aux[i] = lc.coches[i];

	//delete[] lc.coches;
	lc.coches = aux;
	lc.cap += 5;
	aux = nullptr;
}