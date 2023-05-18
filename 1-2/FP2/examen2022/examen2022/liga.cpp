#include "liga.h"
using namespace std;


void cargarPartidos(ifstream& archivo, tLiga& liga) {

}

tEquipo campeonLiga(ifstream& archivo, tLiga& liga)
{
	int numPartidos;
	string e1, e2;
	int p1, p2;
	tEquipo mejor;
	mejor.puntos = 0;

	archivo >> numPartidos;
	for (int i = 0; i < numPartidos; i++) {
		archivo >> e1 >> p1 >> e2 >> p2;
		actualizaPuntos(liga, e1, p1, e2, p2);
	}
	//mirar cual es el mejor
	for (int i = 0; i < liga.cont;i++) {
		if(liga.listaEquipos[i].puntos>mejor.puntos) {
			mejor = liga.listaEquipos[i];
		}
	}

	return mejor;
}
void actualizaPuntos(tLiga&liga, string e1, int p1, string e2, int p2) {
	int ganador;
	if (p1 > p2) {
		ganador=buscaEquipoPorNombre(liga, e1);
		liga.listaEquipos[ganador].puntos+=3;

	} else if (p2<p1){
		ganador=buscaEquipoPorNombre(liga, e2);
		liga.listaEquipos[ganador].puntos+=3;
	}
	else {
		ganador = buscaEquipoPorNombre(liga, e1);
		liga.listaEquipos[ganador].puntos++;
		ganador = buscaEquipoPorNombre(liga, e2);
		liga.listaEquipos[ganador].puntos++;
	}
}

int buscaEquipoPorNombre(const tLiga& liga, string nombre) {
	int i = 0;
	while (liga.listaEquipos[i].nombre != nombre && i<liga.cont) {
		i++;
	}
	return i;

}


void cargarEquipos(ifstream& archivo, tLiga& liga) {
	int num_equipos;
	archivo >> num_equipos;
	for (int i = 0; i < num_equipos; i++)
	{
		cargarEquipo(archivo, liga.listaEquipos[i]);
		liga.cont++;
	}
}

void cargarEquipo(ifstream& archivo, tEquipo& equipo)
{
	archivo >> equipo.nombre;
	archivo >> equipo.presupuesto;
	archivo >> equipo.num_jugadoras;
	equipo.jugadoras = new int[equipo.presupuesto * 3 / 1000];
	for (int i = 0; i < equipo.num_jugadoras; i++)
		archivo >> equipo.jugadoras[i];
}