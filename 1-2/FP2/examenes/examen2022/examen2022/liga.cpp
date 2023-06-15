#include "liga.h"

void cargarEquipo(ifstream& archivo, tEquipo& equipo);
void mostrarEquipo(const tEquipo& equipo, const tJugadoras& jugadoras);
void mostrarEquiposAux(const tLiga& liga, const tJugadoras& jugadoras, int pos);
int sumarPuntos(string eq, tLiga& liga, int puntos);
int posicionEquipo(tLiga& liga, string nombre);
void actualizarCampeon(string eq, string& campeon, int& max_puntos, int p);

void cargarEquipos(ifstream& archivo, tLiga& liga)
{
	archivo >> liga.cont;
	for (int i = 0; i < liga.cont; i++) {
		cargarEquipo(archivo, liga.equipo[i]);
	}
}

void cargarEquipo(ifstream& archivo, tEquipo& equipo)
{
	archivo >> equipo.nombre >> equipo.presupuesto >> equipo.num_jugadoras;
	equipo.puntos = 0;
	equipo.j = new int[equipo.presupuesto * 3 / 1000];
	for (int i = 0; i < equipo.num_jugadoras; i++)
		archivo >> equipo.j[i];
}

tEquipo campeonLiga(ifstream& archivo, tLiga& liga)
{
	string eq1, eq2;
	int pt1, pt2, p;
	int num_enfrentamientos;
	int max_puntos = 0;
	string campeon = "";
	archivo >> num_enfrentamientos;
	for (int i = 0; i < num_enfrentamientos; i++)
	{
		archivo >> eq1 >> pt1 >> eq2 >> pt2;
		if (pt1 == pt2)
		{
			p = sumarPuntos(eq1, liga, 1);
			actualizarCampeon(eq1, campeon, max_puntos, p);
			p = sumarPuntos(eq2, liga, 1);
			actualizarCampeon(eq2, campeon, max_puntos, p);
		}

		else if (pt1 > pt2)
		{
			p = sumarPuntos(eq1, liga, 3);
			actualizarCampeon(eq1, campeon, max_puntos, p);
		}
		else
		{
			p = sumarPuntos(eq2, liga, 3);
			actualizarCampeon(eq2, campeon, max_puntos, p);
		}
	}

	//buscar equipo con mas puntos
	int pos = 0;
	for (int i = 0; i < liga.cont; i++) {
		if (liga.equipo[pos].puntos < liga.equipo[i].puntos)
			pos = i;
	}

	return liga.equipo[pos];
}

void aumentarPresupuesto(tLiga& liga, string nombre)
{
}

bool ficharNuevaJugadora(tJugadoras& lista_jugadoras, tLiga& liga, string equipo, int id_jug, string nombre_jug, string apellido_jug, int goles_jug)
{
	return false;
}

void descensoEquipo(string eq, tLiga& liga, tJugadoras& jugadoras)
{
}

string getNombre(const tEquipo& equipo)
{
	return string();
}

int getPuntos(const tEquipo& equipo)
{
	return equipo.puntos;
}

void liberar_memoria(tLiga& liga)
{
	for (int i = 0; i < liga.cont; i++)
	{
		delete[] liga.equipo[i].j;
		liga.equipo[i].j = nullptr;
	}
}

void mostrarEquipos(const tLiga& liga, const tJugadoras& jugadoras)
{
	cout << "- - - - -" << endl;
	cout << "EQUIPOS" << endl;
	cout << "- - - - -" << endl;
	mostrarEquiposAux(liga, jugadoras, 0);
	cout << endl;
}
void mostrarEquiposAux(const tLiga& liga, const tJugadoras& jugadoras, int pos)
{
	if (pos < liga.cont)
	{
		mostrarEquipo(liga.equipo[pos], jugadoras);
		mostrarEquiposAux(liga, jugadoras, pos + 1);
	}
}
void mostrarEquipo(const tEquipo& equipo, const tJugadoras& jugadoras)
{
	tJugadora jug;
	cout << "Nombre: " << equipo.nombre << ","
		<< " Presupuesto: " << equipo.presupuesto << ","
		<< " Puntos: " << equipo.puntos << ","
		<< " Jugadoras: " << equipo.num_jugadoras << endl;
	if (equipo.num_jugadoras > 0)
		cout << "Plantilla: ";
	for (int i = 0; i < equipo.num_jugadoras; i++)
		if (buscarJugadora(equipo.j[i], jugadoras, jug))
			cout << getApellido(jug) << ", ";
	cout << endl << endl;
}

int sumarPuntos(string eq, tLiga& liga, int puntos)
{
	int pos = posicionEquipo(liga, eq);
	liga.equipo[pos].puntos += puntos;
	return liga.equipo[pos].puntos;
}
int posicionEquipo(tLiga& liga, string nombre)
{
	int pos = -1;
	bool encontrado = false;
	int i = 0;
	while (i < liga.cont && liga.equipo[i].nombre != nombre)
		i++;
	if (i < liga.cont)
		pos = i;
	return pos;
}
void actualizarCampeon(string eq, string& campeon, int& max_puntos, int p)
{
	if (p > max_puntos)
	{
		max_puntos = p;
		campeon = eq;
	}
}
