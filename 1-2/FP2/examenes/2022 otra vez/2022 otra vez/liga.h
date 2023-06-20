#pragma once
#ifndef LIGA_H_
#define LIGA_H_
#include "jugadoras.h"
#include <string>
#include<iostream>
#include <fstream>


const int MAX_EQUIPOS = 10;

struct tEquipo {
	int* jugadoras;
	string nombre;
	int puntos, presupuesto, njug;
};
struct tLiga {
	tEquipo equipos[MAX_EQUIPOS];
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
void liberar_memoria(tLiga& liga);
int getPuntos(const tEquipo& c);

#endif