#include "pelicula.h"
using namespace std;
#include <iostream>
void cargar(ifstream& fichero, tPelicula& pelicula)
{
	getline(fichero,  pelicula.titulo);
	getline(fichero, pelicula.director);
	getline(fichero, pelicula.genero);
	fichero >> pelicula.valoracion;
	cargar(fichero, pelicula.reparto);
}

bool interviene(tPelicula pelicula, string actor)
{
	return aparece(pelicula.reparto, actor, 0);
}
	
void mostrar(const tPelicula& pelicula) {
	cout << "Titulo:     " << pelicula.titulo << endl;
	cout << "Director:   " << pelicula.director << endl;
	cout << "Genero:     " << pelicula.genero << endl;
	cout << "Valoracion: " << pelicula.valoracion << endl;

}

string getGenero(const tPelicula& pelicula)
{
	return pelicula.genero;
}

double getValoracion(const tPelicula& pelicula)
{
	return pelicula.valoracion;
}
