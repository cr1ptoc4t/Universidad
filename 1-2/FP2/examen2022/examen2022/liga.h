#pragma once
#include <iostream>
#include "equipo.h"
using namespace std;
const int MAX_EQUIPOS = 10;

typedef struct {
	tEquipo listaEquipos[MAX_EQUIPOS];
	int cont;
}tLiga;

void cargarEquipos(ifstream archivo, tLiga& liga);
void cargarPartidos(ifstream archivo, tLiga& liga);
tEquipo campeonLiga(ifstream archivo, tLiga& liga);