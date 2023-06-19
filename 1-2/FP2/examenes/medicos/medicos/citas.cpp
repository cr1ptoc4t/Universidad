#include "citas.h"
#include <fstream>

void inicializarListaCitas(tListaCitas& lc)
{
	lc.cap = CAP_INI;
	lc.lc = new tCita[CAP_INI];
	lc.cont = 0;
}

bool cargaListaCitas(tListaCitas& lc)
{
	bool cargado = true;
	ifstream entrada;
	int codigo;
	char espacio;

	entrada.open("citas.txt");
	if (entrada.is_open())
	{
		entrada >> codigo;
		while (codigo != -1)
		{
			if (lc.cont == lc.cap)
				ampliar(lc);

			lc.lc[lc.cont].nmedico = codigo;
			entrada.get(espacio);
			getline(entrada, lc.lc[lc.cont].npaciente);
			lc.cont++;
			entrada >> codigo;
		}
		entrada.close();
	}
	else {
		cout << "Error, no se pudo abrir el archivo 'Citas.txt'" << endl;
		cargado = false;
	}

	return cargado;
}

void ampliar(tListaCitas& lc)
{
	tCita* aux = new tCita[lc.cap+ 3];

	for (int i = 0; i < lc.cont; i++) {
		aux[i] = lc.lc[i];
	}

	delete[] lc.lc;
	lc.cap += 3;
	lc.lc = aux;
	aux = nullptr;
}

void liberarCitas(tListaCitas& lc)
{
	delete[]lc.lc;
	lc.lc = nullptr;
	lc.cap = 0;
	lc.cont = 0;
}

void muestraListaCitas(tListaCitas& lc)
{
	for (int i = 0; i < lc.cont; i++) {
		cout << lc.lc[i].nmedico << "  " << lc.lc[i].npaciente << endl;
	}
}


int getNumElems(const tListaCitas& listaCitas)
{
	return listaCitas.cont;
}

int getCodigoMedico(const tListaCitas& listaCitas, int pos)
{
	return listaCitas.lc[pos].nmedico;
}