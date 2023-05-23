#pragma once
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_JUG = 100;
typedef struct tJugadora
{
	int id;
	string nombre;
	string apellido;
	int goles = 0;
};

typedef tJugadora* tJugadoraPtr;

typedef tJugadoraPtr tArrayJug[MAX_JUG];

typedef struct tJugadoras
{
	tArrayJug array_jugadoras;
	int cont = 0;
};
bool cargarJugadoras(ifstream& archivo, tJugadoras& lj);
void cargarJugadora(ifstream& archivo, tJugadora& j);