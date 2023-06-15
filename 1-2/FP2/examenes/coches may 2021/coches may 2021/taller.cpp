#include "taller.h"
#include <iostream>
void ampliar(tListaCoches& lc);
int buscar(const tListaCoches& lc, const string& matricula, int ini, int fin);
int buscar(const tListaCoches& lc, const string& matricula);

void cargarCoches(ifstream& archivo, tListaCoches& lc)
{
	tCoche c;
	int num;
	archivo >> num;

	archivo.ignore();

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
	for (int i = 0; i < lc.cont; i++)
		cout << lc.coches[i].matricula <<" " << lc.coches[i].averia <<" " << lc.coches[i].estado << endl;
}

tListaSeccion crearListaSeccion(tListaCoches& lc, const string& averia) {
	tListaSeccion l;
	l.cont = 0;
	int i = 0;
	while (i < lc.cont && l.cont < MAX_SECCION) {
		if (lc.coches[i].averia == averia && lc.coches[i].estado == 0) {
			l.lista[l.cont] = &lc.coches[i];
			l.cont++;
			lc.coches[i].estado = 1;
		}
		i++;
	}
	return l;
}

void liberaListaCoches(tListaCoches& lc)
{
	delete[]lc.coches;
	lc.cont = 0;
	lc.cap = 0;
}

void marcarTerminados(tListaSeccion& ls)
{
	for (int i = 0; i < ls.cont; ++i) {
		ls.lista[i]->estado = 2;
	}
}

void mostrarListaSeccion(const tListaSeccion& ls)
{
	for (int i = 0; i < ls.cont; i++)
		cout << ls.lista[i]->matricula << " " << ls.lista[i]->averia << " " << ls.lista[i]->estado << endl;
}

bool finReparacion(tListaCoches& lc, string matricula)
{
	int pos = buscar(lc, matricula);
	if (pos != -1) {
		return lc.coches[pos].estado == 2;
	}
	else return false;
}

void ampliar(tListaCoches& lc) {

	tCoche* aux = new tCoche[lc.cap + 5];
	for (int i = 0; i < lc.cont; i++)
		aux[i] = lc.coches[i];

	//delete [] lc.coches;
	lc.coches = aux;
	lc.cap += 5;
	aux = nullptr;
}

int buscar(const tListaCoches& lc, const string& matricula, int ini, int fin) {

	if (ini >= fin) return -1;
	else {
		int m = (ini + fin) / 2;
		if (lc.coches[m].matricula == matricula) return m;
		else if (lc.coches[m].matricula < matricula)
			return buscar(lc, matricula, m + 1, fin);
		else return buscar(lc, matricula, ini, m);
	}
}

int buscar(const tListaCoches& lc, const string& matricula) {
	return buscar(lc, matricula, 0, lc.cont);
}