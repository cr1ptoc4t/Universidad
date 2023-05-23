#pragma once
#ifndef LIGA_H_
#define LIGA_H_
#include "jugadoras.h"
#include <string>
#include<iostream>
#include <fstream>


using namespace std;
const int MAX_EQUIPOS = 10;
typedef int* tArrayJugEquipo;

typedef struct tEquipo {
	string nombre;
	int puntos=0;
	int presupuesto;
	int numJugadoras;
	tArrayJugEquipo jugadoras;
};


typedef struct tLiga{
	tEquipo arrayEquipos[MAX_EQUIPOS];
	int cont;
};

int buscarElemento(string id, const tLiga l);

void mostrarEquipo(const tEquipo& c);
void cargarLiga(ifstream& archivo, tLiga& liga);
void cargarEquipos(ifstream& archivo, tLiga& liga);
void aumentarPresupuesto(string id, tLiga& l);
void cargarEquipo(ifstream& archivo, tEquipo& equipo);
void aumentarArray(tEquipo& arrayJ);
void mostrarEquipos(tLiga& liga);

bool ficharJugadora(string nEquipo, int id, string nombre, string apellido, tLiga l, tJugadoras& lj);

string getNombre(const tEquipo& c );
tEquipo campeonLiga(ifstream& archivo, tLiga liga);
tEquipo buscarMasPuntos(const tLiga liga);
#endif