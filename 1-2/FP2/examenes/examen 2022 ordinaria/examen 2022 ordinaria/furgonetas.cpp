
#include "furgonetas.h"
#include "paquetes.h"
#include <fstream>
#include <iostream>
using namespace std;

int buscarFurgoneta(const tListaFurgonetas listaFurgonetas, int codigo_postal);
int buscarFurgonetaAux(const tListaFurgonetas listaFurgonetas, int codigo_postal,
	int ini, int fin);

bool cargarCodigos(tListaFurgonetas listaFurgonetas) //Es array estático (no lista)
{
	ifstream fich;
	bool ok = true;

	fich.open("codigos.txt");
	if (!fich.is_open())
		ok = false;
	else
	{
		for (int i = 0; i < NUM_FURGONETAS; i++)
		{
			fich >> listaFurgonetas[i].codigo_postal;
			listaFurgonetas[i].cargados.array = new string[MAX_IDS]; //inic array din
			listaFurgonetas[i].cargados.cont = 0;
		}
		fich.close();
	}
	return ok;
}












void mostrarFurgonetas(const tListaFurgonetas listaFurgonetas)
{
	for (int f = 0; f < NUM_FURGONETAS; f++)
	{
		cout << "Furgoneta " << f + 1 << " reparte en " << listaFurgonetas[f].codigo_postal;
		if (listaFurgonetas[f].cargados.cont == 0)
			cout << " - Sin paquetes asignados" << endl;
		else
		{
			cout << " - Paquetes asignados: ";
			for (int c = 0; c < listaFurgonetas[f].cargados.cont; c++)
				cout << listaFurgonetas[f].cargados.array[c] << " ";
			cout << endl;
		}
	}
}

void cargarPaquetes(tListaFurgonetas listaFurgonetas, tListaPaquetes& listaPaquetes)
{
	int codigo_postal;
	int num_paquetes = getNumPaquetes(listaPaquetes);
	for (int i = 0; i < num_paquetes; i++)
	{
		codigo_postal = getCodigoPostalPaquete(listaPaquetes, i);
		int pos = buscarFurgoneta(listaFurgonetas, codigo_postal);
		if (pos != -1 && listaFurgonetas[pos].cargados.cont < MAX_IDS)
		{
			setCargado(listaPaquetes, i);
			listaFurgonetas[pos].cargados.array[listaFurgonetas[pos].cargados.cont] =
				getIdPaquete(listaPaquetes, i);
			listaFurgonetas[pos].cargados.cont++;
		}
	}
}








int buscarFurgoneta(const tListaFurgonetas listaFurgonetas, int codigo_postal)
{
	return buscarFurgonetaAux(listaFurgonetas, codigo_postal, 0, NUM_FURGONETAS - 1);
}

int buscarFurgonetaAux(const tListaFurgonetas listaFurgonetas, int codigo_postal,
	int ini, int fin)
{
	int pos = -1;
	if (ini <= fin)
	{
		int mitad = (ini + fin) / 2;
		if (codigo_postal == listaFurgonetas[mitad].codigo_postal)
			pos = mitad;
		else if (codigo_postal < listaFurgonetas[mitad].codigo_postal)
			pos = buscarFurgonetaAux(listaFurgonetas, codigo_postal, ini, mitad - 1);
		else
			pos = buscarFurgonetaAux(listaFurgonetas, codigo_postal, mitad + 1, fin);
	}
	return pos;
}

void liberarFurgonetas(tListaFurgonetas listaFurgonetas) {
	for (int i = 0; i < NUM_FURGONETAS; i++) {
		delete[]listaFurgonetas[i].cargados.array;
		listaFurgonetas[i].cargados.array = nullptr;
		listaFurgonetas[i].cargados.cont = 0;
	}
}