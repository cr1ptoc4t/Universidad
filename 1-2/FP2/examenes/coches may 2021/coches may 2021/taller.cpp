#include "taller.h"
void ampliar(tListaCoches& lc);
void insertarEnOrden(tListaCoches& lc, tCoche& c);
void cargarCoche(ifstream& archivo, tCoche& c);
int buscaPosInsertar(string matricula, const tListaCoches& lc);
bool estadoaBool(int estado);
void cargarCoches(ifstream& archivo, tListaCoches& lc) {
	if (archivo.is_open()) {
		int num;
		archivo >> num;
		for (int i = 0; i < num-3;i++) {
			if (lc.numCoches == lc.cap)
				ampliar(lc);

			tCoche coche;
			cargarCoche(archivo, coche);
			//insertarEnOrden(lc, coche);
			lc.coches[lc.numCoches] = coche;
			lc.numCoches++;
		}
	}

}

void iniciarListaCoches(tListaCoches& lc)
{
	lc.cap = 5;
	lc.numCoches = 0;
	lc.coches = new tCoche[lc.cap];
}

void mostrarListaCoches(tListaCoches& lc) {
	cout << endl << "LISTA COCHES:"<<endl;
	for (int i = 0; i < lc.numCoches;i++) {
		cout << lc.coches[i].matricula << " " << lc.coches[i].averia << " " << lc.coches[i].estado << endl;
	}
}

void ampliar(tListaCoches& lc) {
	tCoche* aux = new tCoche[lc.cap + 5];
	for (int i = 0; i < lc.numCoches; i++)
		aux[i] = lc.coches[i];

	delete[] lc.coches;
	lc.coches = aux;
	lc.cap += 5;
	aux = nullptr;
}

void insertarEnOrden(tListaCoches& lc, tCoche& c) {
	int pos= buscaPosInsertar(c.matricula, lc);

	for (int i = lc.numCoches; i > pos; i--)
		lc.coches[i] = lc.coches[i-1];

	lc.coches[pos] = c;
	lc.numCoches++;

}

void cargarCoche(ifstream& archivo, tCoche& c) {
	archivo >> c.matricula >> c.averia >> c.estado;
}

int buscaPosMatricula(string matricula, const tListaCoches& lc) {
	int i=0;
	while (lc.coches[i].matricula!=matricula && i<lc.numCoches)
		i++;

	if (i == lc.numCoches)		i = -1;
	return i;

}

int buscaPosInsertar(string matricula, const tListaCoches& lc) {
	int posicion = 0;
	while (posicion < lc.cap && lc.coches[posicion].matricula < matricula) {
		posicion++;
	}
	return posicion;
}

tListaSeccion crearListaSeccion(tListaCoches& lc, string tipo) {
	tListaSeccion ls;//= new tListaSeccion[MAX_SECCION];
	ls.numCoches = 0;

	for (int i = 0; i < lc.numCoches-1; i++) {
		if (lc.coches[i].averia == tipo) {
			ls.coches[ls.numCoches] = &lc.coches[ls.numCoches];
			ls.numCoches++;
		}
	}


	return ls;
}

void liberaListaCoches(tListaCoches& lc)
{
	delete[] lc.coches;
	lc.cap = 0;
	lc.numCoches = 0;
}


void marcarTerminados(tListaSeccion& ls) {
	for (int i = 0; i < ls.numCoches; i++)
		ls.coches[i]->estado = 2;
}

bool finReparacion(tListaCoches& lc, string matricula) {
	bool reparado;
	//buscar coche por matricula
	int pos = buscaPosMatricula(matricula, lc);
	return estadoaBool(lc.coches[pos].estado);
}

bool estadoaBool(int estado) {
	bool reparado=false;
	if (estado == 2) reparado = true;

	return reparado;
}

void mostrarListaSeccion(const tListaSeccion& l) {
	for (int i = 0; i < l.numCoches; ++i) {
		cout << l.coches[i]->matricula << '\n';
	}
}