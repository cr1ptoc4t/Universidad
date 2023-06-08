#pragma once
#ifndef LISTA_PRESTAMOS_H
#define LISTA_PRESTAMOS_H

#include <iostream>
#include <fstream>
#include "biblioteca.h"
using namespace std;

const int TAM_INI = 50;
const int INCR_TAM = 2;

struct tPrestamo {
	int dni;
	int isbn;
};

struct tPrestamos {
	tPrestamo* p;
	int cont;
	int cap;
};



tPrestamo crearPrestamo(int dni, int isbn);
void crearListaPrestamos(tPrestamos& prestamos);
bool insertarOrdenadoPrestamo(tPrestamos& prestamos, const tPrestamo& prestamo);
bool eliminarPrestamo(tPrestamos& prestamos, const tPrestamo& prestamo);
void mostrarPrestamos(const tPrestamos& prestamos);
void liberarPrestamos(tPrestamos& prestamos);


#endif