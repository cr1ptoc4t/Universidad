#include "liga.h"
#include "liga.h"


void crearJugadora(tJugadoraPtr& jug, int id_jug, string nombre_jug, string apellido_jug, int goles_jug);
void insertarJugadora(tJugadoras& lista_jugadoras, tJugadoraPtr& jug);



int buscarElemento(string id, const tLiga l)
{
	int i = 0;
	while (i < l.cont && l.equipos[i].nombre != id)
	{
		i++;
	}
	if (i == l.cont) i = -1;
	return i;
}

void mostrarEquipo(const tEquipo& c)
{
	cout << c.nombre << " " << c.presupuesto << " " << c.puntos << " num jugadoras: "<<c.njug;
	
	for (int i = 0; i < c.njug; i++)
		cout << " " << c.jugadoras[i];

	//id a string

}

void cargarLiga(ifstream& archivo, tLiga& liga)
{
	archivo >> liga.cont;
	for (int i = 0; i < liga.cont; i++) {
		cargarEquipos(archivo, liga);
	}

}

void cargarEquipos(ifstream& archivo, tLiga& liga)
{
	archivo >> liga.cont;
	for (int i = 0; i < liga.cont; i++) {
		cargarEquipo(archivo, liga.equipos[i]);
	}
}

void aumentarPresupuesto(string id, tLiga& l)
{
	//buscar
	int i = buscarElemento(id, l);

	if (i!=-1) {
		l.equipos[i].presupuesto += 1000;
	}

}

void cargarEquipo(ifstream& archivo, tEquipo& equipo)
{
	equipo.puntos = 0;
	archivo >> equipo.nombre >> equipo.presupuesto >> equipo.njug;
	equipo.jugadoras = new int[equipo.presupuesto * 3 / 1000];
	for (int i = 0; i < equipo.njug; i++) {
		archivo >> equipo.jugadoras[i];
	}
}

void aumentarArray(tEquipo& arrayJ)
{
	int* aux = new int [arrayJ.njug+5];

	for (int i = 0; i < arrayJ.njug;i++) {
		aux[i] = arrayJ.jugadoras[i];
	}

	delete[] arrayJ.jugadoras;
	arrayJ.jugadoras = aux;
	aux = nullptr;

}

void mostrarEquipos(tLiga& liga)
{
	for(int i =0; i<liga.cont; i++){
		mostrarEquipo(liga.equipos[i]);
		cout << endl;
	}
}

bool ficharJugadora(string nEquipo, int id, string nombre, string apellido, tLiga l, tJugadoras& lj)
{
	int pos = buscarElemento(nEquipo, l);
	bool b = false;
	if (pos!=-1 && l.equipos[pos].njug< l.equipos[pos].presupuesto * 3 / 1000) {
		b = true;

		//insertar nueva jugadora en el equipo
		l.equipos[pos].jugadoras[l.equipos[pos].njug] = id;
		l.equipos[pos].njug++;
		l.equipos[pos].presupuesto -= 1000;



		//crear e insertar nueva jugadora en la lista de jugadoras
		tJugadoraPtr j;


		crearJugadora(j, id, nombre, apellido, 0);
		insertarJugadora(lj, j);

		
		lj.jugadoras[lj.cont] = j;

	}

	return b;
}

string getNombre(const tEquipo& c)
{
	return c.nombre;
}


int getPuntos(const tEquipo& c)
{
	return c.puntos;
}

tEquipo campeonLiga(ifstream& archivo, tLiga liga)
{
	//actualizar marcador
	string e1, e2;
	int r1, r2,pos;
	int numJornadas;
	archivo >> numJornadas;
	for (int i = 0; i < numJornadas; i++) {
		archivo >> e1 >> r1 >> e2 >> r2;
		if (r1==r2) {
			//sumar 1 en ambos equipos
			pos = buscarElemento(e1, liga);
			liga.equipos[pos].puntos++;
			pos = buscarElemento(e2, liga);
			liga.equipos[pos].puntos++;

		}
		else if (r1>r2) {
			pos = buscarElemento(e1, liga);
			liga.equipos[pos].puntos++;
		}
		else {
			pos = buscarElemento(e2, liga);
			liga.equipos[pos].puntos++;
		}
	}

	return buscarMasPuntos(liga);
}

tEquipo buscarMasPuntos(const tLiga liga)
{
	int max=0;
	for (int i = 0; i < liga.cont;i++) {
		if (liga.equipos[i].puntos>liga.equipos[max].puntos) {
			max = i;
		}
	}


	return liga.equipos[max];
}

void liberar_memoria(tLiga& liga)
{
	for (int i = 0; i < liga.cont;i++) {
		delete[] liga.equipos[i].jugadoras;
		liga.equipos[i].jugadoras = nullptr;
	}
}

void crearJugadora(tJugadoraPtr& jug, int id_jug, string nombre_jug, string apellido_jug, int goles_jug)
{
	jug->apellido = apellido_jug;
	jug->goles = 0;
	jug->id = id_jug;
	jug->nombre = nombre_jug;
}

void insertarJugadora(tJugadoras& lista_jugadoras, tJugadoraPtr& jug)
{
	lista_jugadoras.jugadoras[lista_jugadoras.cont] = jug;
}
