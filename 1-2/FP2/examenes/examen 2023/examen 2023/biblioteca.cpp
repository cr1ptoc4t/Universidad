#include "prestamo.h"

void cargarLibro(tLibro& libro, ifstream& archivo);
int buscarLibro(const tBiblioteca& b, int isbn);

void cargarBiblioteca(tBiblioteca& biblioteca, ifstream& archivo)
{
	int num;
	archivo >> num;
	tLibro aux;
	biblioteca.cont = 0;
	for (int i = 0; i < num; i++){
		cargarLibro(aux, archivo);
		biblioteca.array[i] = new tLibro(aux);
		biblioteca.cont++;
	}
}

void mostrarBiblioteca(const tBiblioteca& biblioteca)
{
	for (int i = 0; i < biblioteca.cont; i++) {
		cout << biblioteca.array[i]->isbn << endl;
		cout << biblioteca.array[i]->titulo << endl;
		cout << biblioteca.array[i]->total << endl;
		cout << biblioteca.array[i]->prestados<< endl;

	}
}

tPtrLibro getLibro(const tBiblioteca& biblioteca, int isbn)
{
	int pos = buscarLibro(biblioteca, isbn);
	tPtrLibro l;
	if (pos == -1) l = nullptr;
	else l = biblioteca.array[pos];

	return l;
}

int getNumExistentes(tPtrLibro ptr_libro)
{
	return ptr_libro->total;
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
	for (int i = 0; i < biblioteca.cont; i++)
	{
		delete biblioteca.array[i];
		biblioteca.cont = 0;
	}
}

void cargarLibro(tLibro& libro, ifstream& archivo)
{
	archivo >> libro.isbn >> libro.titulo >> libro.total >> libro.prestados;

}
int buscarLibro(const tBiblioteca& b, int isbn)
{
	int i = 0;
	while (b.cont > i && b.array[i]->isbn != isbn) i++;
	if (i == b.cont) i = -1;
	return i;
}
