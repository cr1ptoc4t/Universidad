#pragma once
using namespace std;

#include <iostream>
#include <fstream>
#include "equipo.h"
#include "jugadoras.h"

const int MAX_EQUIPOS = 10;
typedef int* tArrayJugEquipo;

typedef struct tEquipo {
	string nombre;
	int puntos=0;
	int presupuesto;
	tArrayJugEquipo jugadoras;
	int num_jugadoras;
};


typedef struct tLiga {
	tEquipo listaEquipos[MAX_EQUIPOS];
	int cont;
};

void cargarEquipo(ifstream& archivo, tEquipo& equipo);
void actualizaPuntos(tLiga& liga, string e1, int p1, string e2, int p2);
void cargarEquipos(ifstream& archivo, tLiga& liga);
void cargarPartidos(ifstream& archivo, tLiga& liga);
tEquipo campeonLiga(ifstream& archivo, tLiga& liga);
int buscaEquipoPorNombre(const tLiga& liga, string nombre);
