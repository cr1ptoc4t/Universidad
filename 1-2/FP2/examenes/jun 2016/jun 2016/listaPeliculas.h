#ifndef LISTAPELICULAS_H
#define LISTAPELICULAS_H
#include "Pelicula.h"
#include <fstream>

typedef struct {
	tPelicula* lista[50]; // una lista de punteros a pel�culas
	int contador;         // n�m. pel�culas en la lista
} tListaPeliculas;

/*
carga la lista de pel�culas a partir del fichero peliculas.txt
Aviso: la carga implica ocupaci�n de meoria din�mica que deber� ser liberada con
destruir(pelis) antes de acabar la aplicaci�n.
*/
void cargar(tListaPeliculas& pelis);

/*
Dada una lista de pel�culas y un actor, devuelve la lista de pel�culas
en las que ha participado el actor
Aviso: En la lista que se devuelve hay punteros a las pel�culas en pelis,
no se ocupa memoria din�mica (por tanto la lista devuelta no hay que destruirla)
*/
tListaPeliculas filtrarPorActor(const tListaPeliculas& pelis, string actor);

/*
Muestra por pantalla la lista de pel�culas, sin incluir el reparto
*/
void mostrar(const tListaPeliculas& pelis);

/*
Ordena la lista de pel�culas por g�nero de menor a mayor
*/
void ordenarPorGenero(tListaPeliculas& pelis);

/*
Ordena la lista de pel�culas por valoraci�n de mayor a menor
*/
void ordenarPorValoracion(tListaPeliculas& pelis);

/*
libera la memoria ocupada por cada pel�cula en la lista
*/
void destruir(tListaPeliculas& pelis);
#endif