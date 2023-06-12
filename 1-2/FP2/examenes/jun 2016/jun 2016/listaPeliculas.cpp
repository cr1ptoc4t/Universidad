#include <fstream>
#include <iostream>
using namespace std;

#include "ListaPeliculas.h"
#include "Pelicula.h"

void swap(tListaPeliculas& pelis, int i);

void cargar(tListaPeliculas& pelis)
{
	ifstream flujo;
	flujo.open("peliculas.txt");
	if (flujo.is_open()) {
		flujo >> pelis.contador;
		flujo.ignore();

		for (int i = 0; i < pelis.contador; i++){
			pelis.lista[i] = new tPelicula;
			cargar(flujo, *pelis.lista[i]);
		}
	}
}

tListaPeliculas filtrarPorActor(const tListaPeliculas& pelis, string actor)
{
	tListaPeliculas lp;
	lp.contador = 0;
	for (int i = 0; i < pelis.contador; i++) {
		if (interviene(*pelis.lista[i], actor)) {
			lp.lista[lp.contador] = pelis.lista[i];
			lp.contador++;
		}
	} 
	return lp;
}

void mostrar(const tListaPeliculas& pelis) {
	for (int i = 0; i < pelis.contador; i++) {
		mostrar(*(pelis.lista[i]));
		if (i != pelis.contador - 1)
			cout << "---" << endl;
	}
}

void ordenarPorGenero(tListaPeliculas& pelis)
{
	for (int i = 1; i < pelis.contador; i++) {
		tPelicula* p = pelis.lista[i];
		// insertar p en el lugar que le corresponda, entre 0 e i.
		int j = i - 1;
		// el lugar de p ser� j+1, y se encuentra cuando en j hay 
		// un genero <=
		while (j >= 0 && pelis.lista[j]->genero > p->genero) {
			pelis.lista[j + 1] = pelis.lista[j];
			j--;
		}
		pelis.lista[j + 1] = p;
	}
}

void ordenarPorValoracion(tListaPeliculas& pelis)
{
	bool ordenado = false;

	while (!ordenado) {
		ordenado = true;
		for (int i = 0; i < pelis.contador-1; i++) {
			if (getValoracion(*pelis.lista[i]) < getValoracion(*pelis.lista[i + 1])) {
				swap(pelis, i);
				ordenado = false;
			}
		}
	}
}

void destruir(tListaPeliculas& pelis)
{
	for (int i = 0; i < pelis.contador; i++) {
		delete pelis.lista[i];
	}
	pelis.contador = 0;
}

void swap(tListaPeliculas& pelis, int i)
{
	tPelicula* aux;
	aux = pelis.lista[i];
	pelis.lista[i] = pelis.lista[i + 1];
	pelis.lista[i + 1] = aux;
}
