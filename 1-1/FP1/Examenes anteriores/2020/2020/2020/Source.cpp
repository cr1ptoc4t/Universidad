#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// define aquí las CONSTANTES Y TIPOS PEDIDOS 


const int MAX_EQUIPOS = 20;
const int MAX_JORNADAS = 20;


typedef struct {
	string nombre;
	int puntos;
} tEquipo;


typedef struct {
	int cont = 0;
	tEquipo le[MAX_EQUIPOS];
}tClasificacion;


typedef struct {
	tEquipo equipo1;
	tEquipo equipo2;
	int res1;
	int res2;
}tPartido;


typedef struct {
	int cont = 0;
	tEquipo le[MAX_EQUIPOS];
	tPartido partidos[MAX_EQUIPOS / 2];
}tJornada;

typedef struct{
	int cont = 0;
	tEquipo le[MAX_EQUIPOS];
	tJornada lj[MAX_JORNADAS];
}tLiga;


//
// prototipos de los subprogramas pedidos en el enunciado (salvo buscar)
//
bool cargarLiga(tLiga& liga);
bool cargarJornada(tJornada& jornada, int numEquipos);
void mostrarLiga(const tLiga& liga);
void actualizarLiga(const tJornada& jornada, tLiga& liga);
void primeroYultimo(const tLiga& liga, string& primero, string& ultimo);
/* incorpora aquí el prototipo de tu subprograma buscar*/



int main() {
	tLiga liga;
	tJornada jornada;
	string primero, ultimo;

	if (!cargarLiga(liga)) {

		cout << "carga fallida" << endl;
	}
	else {
		cout << "CLASIFICACION...\n";
		mostrarLiga(liga);
		actualizarLiga(jornada, liga);
		cout << "\nCLASIFICACION ACTUALIZADA...\n";
		mostrarLiga(liga);
		primeroYultimo(liga, primero, ultimo);
		cout << endl;
		cout << "Primer clasificado: " << primero << endl;
		cout << "Ultimo clasificado: " << ultimo << endl;
	}

	return 0;
}



bool cargarLiga(tLiga& liga) {
	ifstream archivo;
	
	bool cargado = false;
	archivo.open("liga.txt");
	
	if (archivo.is_open()) {
		string equipo;
		archivo >> equipo;
		liga.cont = 0;
		while (equipo!="FIN") {
			liga.le[liga.cont].nombre = equipo;
			archivo >> liga.le[liga.cont].puntos;
			archivo >> equipo;

			liga.cont++;
		}
		cargado = true;
	}

	return cargado;
}

bool cargarJornada(tJornada& jornada, int numEquipos) {
	ifstream archivo;

	bool cargado = false;
	archivo.open("liga.txt");

	if (archivo.is_open()) {
		for (int i = 0; i < numEquipos; i++) {
			archivo >> jornada.partidos[i].equipo1;
			archivo >> jornada.partidos[i].res1;
			archivo >> jornada.partidos[i].equipo2;
			archivo >> jornada.partidos[i].equipo1;
			archivo >> jornada.partidos[i].res2;

		}jornada.cont = numEquipos;
		cargado = true;
	}

	return cargado;
}


void mostrarLiga(const tLiga& liga) {
	for (int i = 0; i < liga.cont;i++) {
		cout << liga.le[i].nombre << " : " << liga.le[i].puntos<<endl;
	}

}


void actualizarLiga(const tJornada& jornada, tLiga& liga) {
	// incluye aquí tu código


}


void primeroYultimo(const tLiga& liga, string& primero, string& ultimo) {
	// incluye aquí tu código

}

