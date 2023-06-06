#pragma once
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <fstream>
using namespace std;

const int MAX = 50;

struct tLibro {
	int isbn;
	string titulo;
	int numTotal;
	int prestados;
};
typedef tLibro* tPtrLibro;
struct tBiblioteca {
	tPtrLibro libros[MAX];
	int cont;
};

void cargarBiblioteca(tBiblioteca& biblioteca, ifstream& archivo);
void mostrarBiblioteca(const tBiblioteca& biblioteca);
tPtrLibro getLibro(const tBiblioteca& biblioteca, int isbn);
int getNumExistentes(tPtrLibro ptr_libro);
int getNumPrestados(tPtrLibro ptr_libro);
void setNumPrestados(tPtrLibro ptr_libro, int num_prestados);
void liberarBiblioteca(tBiblioteca& biblioteca);

#endif