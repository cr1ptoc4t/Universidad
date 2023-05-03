#include "liga.h"

void cargarEquipos(ifstream archivo, tLiga& liga) {
	archivo >> liga.cont;
	for (int i = 0; i < liga.cont; i++) {
		archivo >> liga.listaEquipos[i].nombre;
		archivo >> liga.listaEquipos[i].presupuesto;
		archivo >> liga.listaEquipos[i].puntos;
		archivo >> liga.listaEquipos[i].num_jugadoras;

		for (int j = 0; j < liga.listaEquipos[i].num_jugadoras; j++) {
			archivo >> liga.listaEquipos[i].jugadoras->listaJugadoras[j].id;
		}
	}
}

void cargarPartidos(ifstream archivo, tLiga& liga) {

}

tEquipo campeonLiga(ifstream archivo, tLiga& liga)
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