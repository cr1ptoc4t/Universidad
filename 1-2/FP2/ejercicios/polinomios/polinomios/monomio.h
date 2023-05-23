#pragma once
#include <fstream>
using namespace std;
typedef struct
{
	int grado, coeficiente;
} tMonomio;
bool cargarMonomio(ifstream& archivo, tMonomio& monomio, int grado);
void escribirMonomio(const tMonomio& monomio, bool primero);
int gradoMonomio(const tMonomio& monomio);
int coeficiente(const tMonomio& monomio);
tMonomio sumaMonomios(const tMonomio& m1, const tMonomio& m2);
tMonomio multiplicarDosMonomios(const tMonomio& m1, const tMonomio& m2);
