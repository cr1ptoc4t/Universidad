#include "liga.h"
void insertarIdJugadora(tEquipo& equipo, int id);
void cargarEquipo(ifstream& archivo, tEquipo& equipo);

void cargarEquipos(ifstream& archivo, tLiga& liga) {
	archivo >> liga.cont;
	for (int i = 0; i < liga.cont;i++) {
		cargarEquipo(archivo, liga.arrayEquipos[i]);
	}
}

void cargarLiga(ifstream& archivo, tLiga& liga) {
	//numpartidos
	//resultado
	//
}

void cargarEquipo(ifstream& archivo, tEquipo& equipo) {
	archivo >> equipo.nombre>>equipo.presupuesto>> equipo.numJugadoras;
	equipo.jugadoras = new int[equipo.presupuesto * 3 / 1000];
	for (int i = 0; i < equipo.numJugadoras; i++) {
		archivo >> equipo.jugadoras[i];
	}
}

void aumentarPresupuesto(string id, tLiga& l) {
	int indice = buscarElemento(id, l);
	if (indice != -1) {
		l.arrayEquipos[indice].presupuesto += 1000;
		cout << "Se aumenta el presupuesto de " << id<<endl;
		aumentarArray(l.arrayEquipos[indice]);
	}

}

int buscarElemento(string id, const tLiga l) {
	int pos = 0;
	while (l.arrayEquipos[pos].nombre != id && pos < l.cont)
		pos++;

	if (pos == l.cont) pos = -1;
	return pos;
}

void aumentarArray(tEquipo& arrayJ) {
	int* aux  = new int[arrayJ.presupuesto*3/1000];
	
	for (int i = 0; i < arrayJ.numJugadoras; i++) {
		aux[i] = arrayJ.jugadoras[i];
	}
	delete[] arrayJ.jugadoras;
	arrayJ.jugadoras = aux;
	aux = nullptr;

}




bool ficharJugadora(string nEquipo, int id, string nombre, string apellido, tLiga l, tJugadoras& j) {
	bool ok = false;
	int indice = buscarElemento(nEquipo, l);
	if(indice!=-1 && l.arrayEquipos[indice].numJugadoras <
		l.arrayEquipos[indice].presupuesto * 3 / 1000) {
		insertarIdJugadora(l.arrayEquipos[indice], id);
		tJugadoraPtr jug;
		crearJugadora(jug,id,nombre, apellido);
		insertarJugadora(jug, j);

		ok=true;
	}

	return ok;
}

string getNombre(const tEquipo& c)
{
	return c.nombre;
}

void insertarIdJugadora (tEquipo& equipo, int id) {
	equipo.jugadoras[equipo.numJugadoras] = id;
	equipo.numJugadoras++;
}

void mostrarEquipos(tLiga& liga){
	cout << "- - - - -"<<endl<<"EQUIPOS"<<endl<<"- - - - -"<<endl;
	for (int i = 0; i < liga.cont; i++)
		mostrarEquipo(liga.arrayEquipos[i]);
		
}

void mostrarEquipo(const tEquipo& equipo) {
	cout << "Nombre: " << equipo.nombre << ". Presupuesto:" << equipo.presupuesto << ". Jugadoras: "<<equipo.numJugadoras<<endl;
	cout << "Plantilla: ";
	for (int i = 0; i < equipo.numJugadoras;i++) {
		cout << equipo.jugadoras[i] << " ";
	}
	cout << endl;
}

tEquipo campeonLiga(ifstream& archivo, tLiga liga) {
	int numPartidos; string aumentaPresupuesto;
	int indice1, indice2;
	archivo >> numPartidos;
	string e1, e2;
	int r1, r2;
	for (int i = 0; i < numPartidos; i++) {
		archivo >> e1 >> r1 >> e2 >> r2;
		if (r1==r2) {
			indice1 = buscarElemento(e1, liga);
			indice2 = buscarElemento(e2, liga);
			liga.arrayEquipos[indice1].puntos++;
			liga.arrayEquipos[indice2].puntos++;
		}
		else if (r1>r2) {
			indice1 = buscarElemento(e1, liga);
			liga.arrayEquipos[indice1].puntos+=3;

		}
		else {
			indice2 = buscarElemento(e2, liga);
			liga.arrayEquipos[indice1].puntos+=3;

		}
	}

	return buscarMasPuntos(liga);;
}

tEquipo buscarMasPuntos(const tLiga liga) {
	int max = 0;
	for(int i=0;i<liga.cont;i++)
		if (liga.arrayEquipos[max].puntos<liga.arrayEquipos[i].puntos) {
			max = i;
		}

	return liga.arrayEquipos[max];

}

