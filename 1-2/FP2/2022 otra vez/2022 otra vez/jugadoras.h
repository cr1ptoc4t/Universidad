#pragma once
using namespace std;
#include <iostream>
#include <fstream>


const int MAX_JUGADORAS = 100;

typedef struct tJugadora {
	int id;
	string nombre;
	string apellido;
	int goles=0;
};

typedef tJugadora* tJugadoraPtr;

typedef tJugadoraPtr tArrayJug[MAX_JUGADORAS];

typedef struct tJugadoras
{
	tArrayJug array_jugadoras;
	int cont = 0;
};

void cargarJugadoras(ifstream& archivo,tJugadoras& jugadora);
void mostrarJugadoras(const tJugadoras& lj);
void crearJugadora(tJugadora& jug, int id, string nombre, string apellido);
void insertarJugadora(tJugadora j, tJugadoras& lj);