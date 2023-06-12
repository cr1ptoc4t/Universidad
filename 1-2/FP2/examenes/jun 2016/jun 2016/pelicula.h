#ifndef PELICULA_H
#define PELICULA_H

#include <string>
using namespace std;

#include "Reparto.h"

struct tPelicula {
	string titulo;
	string director;
	string genero;
	double valoracion;
	tReparto reparto;
};

/*
 carga una pel?cula a partir del fichero que ya est? abierto
*/
void cargar(ifstream& fichero, tPelicula& pelicula);

/*
indica si el 'actor' aparece en el reparto de la 'pel?cula'
*/
bool interviene(tPelicula pelicula, string actor);

/*
Muestra por pantalla los datos de una pel?cula, sin incluir el reparto
*/
void mostrar(const tPelicula& pelicula);
string getGenero(const tPelicula& pelicula);
double getValoracion(const tPelicula& pelicula);
#endif