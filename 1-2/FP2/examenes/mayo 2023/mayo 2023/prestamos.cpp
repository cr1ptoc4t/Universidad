#include "prestamos.h"

int buscarPrestamo(const tPrestamos& prestamos, const tPrestamo& prestamo);
void ampliar(tPrestamos& prestamos);

tPrestamo crearPrestamo(int dni, int isbn)
{
	tPrestamo p;
	p.dni = dni;
	p.isbn = isbn;
	return p;
}

void crearListaPrestamos(tPrestamos& prestamos)
{
	prestamos.cap = TAM_INI;
	prestamos.cont = 0;
	prestamos.prestamos = new tPrestamo[TAM_INI];
}

bool insertarOrdenadoPrestamo(tPrestamos& prestamos, const tPrestamo& prestamo)
{
	int i = 0;
	while (i < prestamos.cont && prestamos.prestamos[i].dni < prestamo.dni)
		i++;

	if (i == prestamos.cont)
		ampliar(prestamos);

	for (int j = prestamos.cont; j>i; j--)
		prestamos.prestamos[j] = prestamos.prestamos[j-1];

	prestamos.prestamos[i] = prestamo;

	return true;
}

bool eliminarPrestamo(tPrestamos& prestamos, const tPrestamo& prestamo)
{
	int pos = buscarPrestamo(prestamos, prestamo);
	bool b=false;
	if (pos != -1) {
		b = true;
		for (int i = pos; i < prestamos.cont; i++)
			prestamos.prestamos[i-1] = prestamos.prestamos[i];

		prestamos.cont--;
	}
	return b;
}

void mostrarPrestamos(const tPrestamos& prestamos)
{
	for (int i = 0; i < prestamos.cont; i++) {
		cout << prestamos.prestamos[i].dni << " - " << prestamos.prestamos[i].isbn<<endl;
	}
}

void liberarPrestamos(tPrestamos& prestamos)
{
	delete [] prestamos.prestamos;
	prestamos.cap = 0;
	prestamos.cont = 0;
	prestamos.prestamos = nullptr;
}

int buscarPrestamo(const tPrestamos& prestamos, const tPrestamo& prestamo) {
	int i = 0;
	while (i < prestamos.cont && prestamos.prestamos[i].dni != prestamo.dni && prestamos.prestamos[i].isbn != prestamo.isbn)
		i++;

	if (i == prestamos.cont)
		i = -1;

	return i;
}

void ampliar(tPrestamos& prestamos) {
	tPrestamo* aux = new tPrestamo[prestamos.cont + INCR_TAM];
	for (int i = 0; i < prestamos.cont;i++) {
		aux[i] = prestamos.prestamos[i]; 
	}
	delete[] prestamos.prestamos;
	prestamos.prestamos = aux;
	prestamos.cap += INCR_TAM;
}