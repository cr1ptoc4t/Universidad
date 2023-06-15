#pragma once

#include <fstream>

using namespace std;

const int MAX_SECCION = 3;
using namespace std;
struct tCoche {
	string matricula;
	string averia;
	int estado;
};

struct tListaCoches {
	tCoche* coches;
	int cont;
	int cap;
};

typedef tCoche* coches[MAX_SECCION];

struct tListaSeccion {
	coches lista;
	int cont;

};

void cargarCoches(ifstream& archivo, tListaCoches& lc);
void iniciarListaCoches(tListaCoches& lc);
void mostrarListaCoches(tListaCoches& lc);
tListaSeccion crearListaSeccion(tListaCoches& lc, const string& averia);
void liberaListaCoches(tListaCoches& lc);
void marcarTerminados(tListaSeccion& ls);
void mostrarListaSeccion(const tListaSeccion& ls);
bool finReparacion(tListaCoches& lc, string matricula);