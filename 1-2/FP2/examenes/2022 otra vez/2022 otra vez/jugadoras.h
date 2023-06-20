#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <string>


const int MAX_JUGADORAS = 100;

struct tJugadora {
	int id;
	string nombre;
	string apellido;
	int goles;
};

typedef tJugadora* tJugadoraPtr;

struct tJugadoras {
	tJugadoraPtr jugadoras[MAX_JUGADORAS];
	int cont;

};

void cargarJugadoras(ifstream& archivo,tJugadoras& jugadora);
void mostrarJugadoras(const tJugadoras& lj);
void crearJugadora(tJugadoraPtr& jug, int id, string nombre, string apellido);
void insertarJugadora(tJugadoraPtr j, tJugadoras& lj);
void liberar_memoria(tJugadoras& lista_jugadoras);