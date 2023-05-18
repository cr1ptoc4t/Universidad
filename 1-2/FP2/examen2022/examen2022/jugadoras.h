#pragma once
#include "jugadora.h"
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_JUG = 100;

typedef struct {
	tJugadora listaJugadoras[MAX_JUG];
	int cont;
}tJugadoras;

bool cargarJugadoras(ifstream& archivo, tJugadoras& lj);
