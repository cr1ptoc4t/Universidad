#include "prestamo.h"
int buscarPrestamo(const tPrestamos& prestamos, const tPrestamo& prestamo);
int buscarPrestamoAux(const tPrestamos& prestamos, const tPrestamo& prestamo, int ini, int fin);
void ampliar(tPrestamos& p);


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
	prestamos.p = new tPrestamo[TAM_INI];
}

bool insertarOrdenadoPrestamo(tPrestamos& prestamos, const tPrestamo& prestamo)
{
	int i = 0;
	while (prestamos.p[i].dni<prestamo.dni) {
		i++;
	}
	//insertar
	if (prestamos.cont + 1 == prestamos.cap)
		ampliar(prestamos);

	for (int i = prestamos.cont; i > 0 ; i--)
		prestamos.p[i+1] = prestamos.p[i];


	prestamos.cont++;
	return true;
}

bool eliminarPrestamo(tPrestamos& prestamos, const tPrestamo& prestamo)
{
	int b = false;
	int pos = buscarPrestamo(prestamos, prestamo);
	if (pos != -1) {
		b = true;
		for (int i = 0; i < prestamos.cont; i++)
			prestamos.p[i] = prestamos.p[i];
	}
	return b;
}

void mostrarPrestamos(const tPrestamos& prestamos)
{
	for (int i = 0; i < prestamos.cont; i++)
		cout << prestamos.p[i].dni << prestamos.p[i].isbn << endl;
}

void liberarPrestamos(tPrestamos& prestamos)
{
	delete[] prestamos.p;
	prestamos.cap = 0;
	prestamos.cont = 0;
}

int buscarPrestamo(const tPrestamos& prestamos, const tPrestamo& prestamo)
{
	return buscarPrestamoAux(prestamos, prestamo,0, prestamos.cont);
}

int buscarPrestamoAux(const tPrestamos& prestamos, const tPrestamo& prestamo, int ini, int fin)
{
	int pos = -1;
	if (fin >= ini) {
		int mitad = (fin + ini) / 2;

		if (prestamos.p[mitad].dni == prestamo.dni) {
			pos = mitad;
		}
		else if (prestamos.p[mitad].dni>prestamo.dni) {
			pos = buscarPrestamoAux(prestamos, prestamo, ini, mitad-1);
		}
		else {
			pos = buscarPrestamoAux(prestamos, prestamo, mitad+1, fin);
		}
	}
	return pos;
}

void ampliar(tPrestamos& p)
{
	tPrestamo* aux = new tPrestamo[p.cap+INCR_TAM];
	for (int i = 0; i < p.cont; i++)
		aux[i] = p.p[i];

	delete[]p.p;

	p.p = aux;
	p.cap = p.cap + INCR_TAM;

	aux = nullptr;
}
