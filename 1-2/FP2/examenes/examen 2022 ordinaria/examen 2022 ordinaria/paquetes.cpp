#include "paquetes.h"

#include <fstream>
#include <iostream>
using namespace std;

void mostrarPaquete(const tPaquete& paquete);
int buscarPaquete(const tListaPaquetes& listaPaquetes, string id);
void eliminarPaquete(tListaPaquetes& listaPaquetes, int posicion);

bool cargarPaquetes(tListaPaquetes& listaPaquetes)
{
	ifstream fich;
	bool ok = true;
	tPaquete paq;

	fich.open("paquetes.txt");
	if (!fich.is_open()) ok = false;
	else
	{
		fich >> listaPaquetes.cont;
		for (int i = 0; i < listaPaquetes.cont; i++) {
			fich >> paq.id >> paq.codigo_postal;
			listaPaquetes.array_paquetes[i] = new tPaquete(paq);
		}
		fich.close();
	}
	return ok;
}

void mostrarPaquetes(const tListaPaquetes& listaPaquetes)
{
	for (int i = 0; i < listaPaquetes.cont; i++)
		mostrarPaquete(*listaPaquetes.array_paquetes[i]);
}

void mostrarPaquete(const tPaquete& paquete)
{
	cout << paquete.id << " va a " << paquete.codigo_postal << " - cargado: ";
	if (paquete.cargado) cout << "SI" << endl;
	else cout << "NO" << endl;
}
void recogerPaquete(tListaPaquetes& listaPaquetes)
{
	string idpaq;
	int posicionPaq;

	cout << "Introduzca el identificador del paquete a recoger: ";
	cin >> idpaq;
	posicionPaq = buscarPaquete(listaPaquetes, idpaq);
	if (posicionPaq != -1 && !listaPaquetes.array_paquetes[posicionPaq]->cargado)
		eliminarPaquete(listaPaquetes, posicionPaq);
}

int buscarPaquete(const tListaPaquetes& listaPaquetes, string id)
{
	bool encontrado = false;
	int pos = 0;
	while (pos < listaPaquetes.cont && !encontrado) {
		encontrado = listaPaquetes.array_paquetes[pos]->id == id;
		if (!encontrado) pos++;
	}
	if (!encontrado) pos = -1;
	return pos;
}

void eliminarPaquete(tListaPaquetes& listaPaquetes, int posicion)
{
	delete listaPaquetes.array_paquetes[posicion];
	for (int i = posicion; i < listaPaquetes.cont - 1; i++)
		listaPaquetes.array_paquetes[i] = listaPaquetes.array_paquetes[i + 1];
	listaPaquetes.cont--;
}

void liberarPaquetes(tListaPaquetes& listaPaquetes)
{
	for (int i = 0; i < listaPaquetes.cont; i++)
	{
		delete listaPaquetes.array_paquetes[i];
		listaPaquetes.array_paquetes[i] = nullptr;
	}
	listaPaquetes.cont = 0;
}



int getNumPaquetes(const tListaPaquetes& listaPaquetes)
{
	return listaPaquetes.cont;
}

int getCodigoPostalPaquete(const tListaPaquetes& listaPaquetes, int i)
{
	return listaPaquetes.array_paquetes[i]->codigo_postal;
}

string getIdPaquete(const tListaPaquetes& listaPaquetes, int i)
{
	return listaPaquetes.array_paquetes[i]->id;
}

void setCargado(tListaPaquetes& listaPaquetes, int i)
{
	listaPaquetes.array_paquetes[i]->cargado = true;
}