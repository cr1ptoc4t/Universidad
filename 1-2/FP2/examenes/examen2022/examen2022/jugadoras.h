#pragma once
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_JUGADORAS = 100;
struct tJugadora {
	int id;
	string nombre;
	string apellido;
	int goles;
};

struct tJugadoras {
	tJugadora* array [MAX_JUGADORAS];
	int cont;
};

bool cargarJugadoras(ifstream& archivo, tJugadoras& lj);
void mostrarJugadoras(const tJugadoras& lj);
bool buscarJugadora(int id, const tJugadoras& lista_jug, tJugadora& jug);
string getApellido(const tJugadora& jug);
void liberar_memoria(tJugadoras& lista_jugadoras);