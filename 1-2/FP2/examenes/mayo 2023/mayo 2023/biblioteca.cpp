#include <iostream>           
#include <fstream>   
#include <string>
#include "biblioteca.h"
using namespace std;
int buscarLibro(const tBiblioteca& biblioteca, int isbn);
void cargarLibro(ifstream& archivo, tLibro& libro);


void cargarBiblioteca(tBiblioteca& biblioteca, ifstream& archivo)
{
	if (archivo.is_open()) {
		int num;
		tLibro libro;
		biblioteca.cont = 0;
		archivo >> num;
		for (int i = 0; i < num; i++) {
			cargarLibro(archivo, libro);
			biblioteca.libros[i] = new tLibro(libro);
			biblioteca.cont++;
		}
		archivo.close();
	}
}

void mostrarBiblioteca(const tBiblioteca& biblioteca)
{
	cout << biblioteca.cont << endl;
	for (int i = 0; i < biblioteca.cont;i++) {
		cout << biblioteca.libros[i]->isbn << endl << biblioteca.libros[i]->titulo << endl << biblioteca.libros[i]->numTotal << endl << biblioteca.libros[i]->prestados << endl;
	}
}

tPtrLibro getLibro(const tBiblioteca& biblioteca, int isbn)
{
	int pos = buscarLibro(biblioteca, isbn);
	tPtrLibro libro;

	if (pos == -1) libro = nullptr;
	else libro= biblioteca.libros[pos];

	return libro;
}

int getNumExistentes(tPtrLibro ptr_libro)
{
	return ptr_libro->numTotal;
}

int getNumPrestados(tPtrLibro ptr_libro)
{
	return ptr_libro->prestados;
}

void setNumPrestados(tPtrLibro ptr_libro, int num_prestados)
{
	ptr_libro->prestados = num_prestados;
}

void liberarBiblioteca(tBiblioteca& biblioteca)
{
	for (int i = 0; i < biblioteca.cont; i++) {
		delete biblioteca.libros[i];
	}
	biblioteca.cont = 0;

}

int buscarLibro(const tBiblioteca& biblioteca, int isbn) {
	int i = 0;
	while (biblioteca.cont>i&&biblioteca.libros[i]->isbn!=isbn)
		i++;

	if (i == biblioteca.cont)
		i = -1;
	return i;
}

void cargarLibro(ifstream& archivo, tLibro& libro)
{
	archivo >> libro.isbn;
	archivo >> libro.titulo;
	archivo >> libro.numTotal;
	archivo >> libro.prestados;
}