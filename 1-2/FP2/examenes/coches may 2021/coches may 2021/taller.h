#pragma once
#include <iostream>
#include <fstream>
const int MAX_SECCION = 3;
using namespace std;
//typedef enum tAveria{CHASIS, MOTOR};

typedef struct tCoche{
	string matricula;
	string averia;
	int estado;
};

struct tListaCoches {
    tCoche* coches;                 //array dinámico
    int numCoches;
    int cap;
};

struct tListaSeccion {
    tCoche* coches[MAX_SECCION];    //array estático de punteros
    int numCoches;
};


void cargarCoches(ifstream& archivo, tListaCoches& lc);
void iniciarListaCoches(tListaCoches& lc);
void mostrarListaCoches(tListaCoches& lc);
tListaSeccion crearListaSeccion(tListaCoches& lc, string tipo);
void liberaListaCoches(tListaCoches& lc);
void marcarTerminados(tListaSeccion& ls);
void mostrarListaSeccion(const tListaSeccion& ls);
bool finReparacion(tListaCoches& lc, string matricula);