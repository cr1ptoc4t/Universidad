#include "citas.h"
#include <fstream>

void inicializarListaCitas(tListaCitas& lc)
{
	lc.citas = new tCita[CAP_INI];
	lc.cap = CAP_INI;
}

bool cargaListaCitas(tListaCitas& lc)
{
	ifstream archivo;
	archivo.open("citas.txt");
	bool b = false;
	
	if (archivo.is_open()) {
		int i = 0;
		int a;
		archivo >> a;
		while (a!=-1) {
			lc.citas[i].codmed = a;
			archivo >> lc.citas[i].codpac >> a;
			i++;
		}
		
		lc.cont = i;
		archivo.close();
		b = true;
	}
	return b;
}

void ampliar(tListaCitas& lc)
{
	tCita* aux = new tCita[lc.cont + 5];
	for (int i = 0; i < lc.cont; i++)
		aux[i] = lc.citas[i];

	delete[] lc.citas;
	lc.citas = aux;
	lc.cap += 5;
	aux = nullptr;
}

void liberarCitas(tListaCitas& lc)
{
	delete[]lc.citas; 
	lc.citas = nullptr;
	lc.cont = 0;
	lc.cap = 0;
}

void muestraListaCitas(tListaCitas& lc)
{
	for (int i = 0; i < lc.cont; i++)
		cout << lc.citas[i].codmed << " - " << lc.citas[i].codpac << endl;
}

int getNumElems(const tListaCitas& listaCitas)
{
	return listaCitas.cont;
}

int getCodigoMedico(const tListaCitas& listaCitas, int pos)
{
	return listaCitas.citas[pos].codmed;
}
