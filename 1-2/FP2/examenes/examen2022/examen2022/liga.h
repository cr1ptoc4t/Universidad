#pragma once
using namespace std;

#include <iostream>
#include <fstream>
#include "jugadoras.h"

const int MAX_EQUIPOS = 10;
typedef int* tArrayJugEquipo;
struct tEquipo {
	string nombre;
	int puntos;
	int presupuesto;
	tArrayJugEquipo j;
	int num_jugadoras;
	int capacidad;
};

struct tLiga {
	tEquipo equipo[MAX_EQUIPOS];
	int cont;
};

void cargarEquipos(ifstream& archivo, tLiga& liga);
void mostrarEquipos(const tLiga& liga, const tJugadoras& jugadoras);
tEquipo campeonLiga(ifstream& archivo, tLiga& liga);
void aumentarPresupuesto(tLiga& liga, string nombre);
bool ficharNuevaJugadora(tJugadoras& lista_jugadoras, tLiga& liga, string equipo, int id_jug, string nombre_jug, string apellido_jug, int goles_jug);
void descensoEquipo(string eq, tLiga& liga, tJugadoras& jugadoras);
string getNombre(const tEquipo& equipo);
int getPuntos(const tEquipo& equipo);
void liberar_memoria(tLiga& liga);
