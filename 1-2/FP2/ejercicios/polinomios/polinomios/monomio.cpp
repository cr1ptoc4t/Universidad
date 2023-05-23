#include <fstream>
#include <iostream>
#include "monomio.h"
using namespace std;
bool cargarMonomio(ifstream& archivo, tMonomio& monomio, int grado_monomio)
{
	int coeficiente;
	bool guardado;
	archivo >> coeficiente;
	guardado = coeficiente != 0;
	if (guardado)
	{
		monomio.grado = grado_monomio;
		monomio.coeficiente = coeficiente;
	}
	return guardado;
}
void escribirMonomio(const tMonomio& monomio, bool primero)
{
	int coef = monomio.coeficiente;
	if (coef >= 1 && !primero)
		cout << " + ";
	else if (coef <= -1)
	{
		cout << " - ";
		coef = -monomio.coeficiente;
	}
	if (coef != 1 || monomio.grado == 0)
		cout << coef;
	if (monomio.grado != 0)
	{
		cout << "x";
		if (monomio.grado > 1)
			cout << '^' << monomio.grado;
	}
}
int gradoMonomio(const tMonomio& monomio)
{
	return monomio.grado;
}
int coeficiente(const tMonomio& monomio)
{
	return monomio.coeficiente;
}
tMonomio sumaMonomios(const tMonomio& m1, const tMonomio& m2)
{
	tMonomio m;
	m.grado = m1.grado;
	m.coeficiente = m1.coeficiente + m2.coeficiente;
	return m;
}
tMonomio multiplicarDosMonomios(const tMonomio& m1, const tMonomio& m2)
{
	tMonomio resultado;
	resultado.coeficiente = m1.coeficiente * m2.coeficiente;
	resultado.grado = m1.grado + m2.grado;
	return resultado;
}