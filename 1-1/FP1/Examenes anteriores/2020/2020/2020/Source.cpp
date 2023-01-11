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
	int cont;
	tEquipo le[MAX_EQUIPOS];
} tClasificacion;


typedef struct {
	tEquipo equipo1;
	tEquipo equipo2;
	int res1;
	int res2;
} tPartido;


typedef struct {
	int cont;
	tEquipo le[MAX_EQUIPOS];
	tPartido partidos[MAX_EQUIPOS / 2];
} tJornada;

typedef struct{
	int cont;
	tEquipo le[MAX_EQUIPOS];
	tJornada lj[MAX_JORNADAS];
	tClasificacion lc;
} tLiga;


//
// prototipos de los subprogramas pedidos en el enunciado (salvo buscar)
//
bool cargarLiga(tLiga& liga);
bool cargarJornada(tJornada& jornada, int numEquipos);
void mostrarLiga(const tLiga& liga);
void actualizarLiga(const tJornada& jornada, tLiga& liga);
void primeroYultimo(const tLiga& liga, string& primero, string& ultimo);
int buscar(string acr, tLiga clas);



int main() {
	tLiga liga;
	tJornada jornada;
	string primero, ultimo;

	if (!cargarLiga(liga)||!cargarJornada(jornada, 9)) {

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
	string cadena;
	bool cargado = false;
	archivo.open("jornada.txt");
	cout << endl;
	if (archivo.is_open()) {
		for (int i = 0; i < numEquipos; i++) {
			archivo >> jornada.partidos[i].equipo1.nombre;
			archivo >> jornada.partidos[i].res1;
			archivo >> jornada.partidos[i].equipo2.nombre;
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
	cout << endl<<"ACTUALIZANDO..." << endl;
	liga.lc.cont=liga.cont;
	for (int i = 0; i < liga.cont/2;i++) {
		if (jornada.partidos[i].res1 == jornada.partidos[i].res2) {
			liga.le[buscar(jornada.partidos[i].equipo1.nombre, liga)].puntos++;
			liga.le[buscar(jornada.partidos[i].equipo2.nombre, liga)].puntos++;
			cout << jornada.partidos[i].equipo1.nombre << " y " << jornada.partidos[i].equipo2.nombre << ": +1" << endl;
		}
		else if (jornada.partidos[i].res1 > jornada.partidos[i].res2) {
			liga.le[buscar(jornada.partidos[i].equipo1.nombre, liga)].puntos+=3;
			cout << jornada.partidos[i].equipo1.nombre << ": +3" << endl;
		}
		else {
			liga.le[buscar(jornada.partidos[i].equipo2.nombre, liga)].puntos+=3;
			cout << jornada.partidos[i].equipo2.nombre << ": +3" << endl;
			
		}
	}
}


void primeroYultimo(const tLiga& liga, string& primero, string& ultimo) {

	int min=0;
	int max=0;
	for (int i = 0; i < liga.cont;i++) {
		if (liga.le[min].puntos > liga.le[i].puntos) min = i;
		else if (liga.le[max].puntos < liga.le[i].puntos) max = i;
	}

	ultimo = liga.le[min].nombre;
	primero  = liga.le[max].nombre;

}

int buscar(string acr, tLiga clas) {
	int i = 0;
	while (clas.le[i].nombre!=acr && i<clas.cont) i++;
	return i;
}