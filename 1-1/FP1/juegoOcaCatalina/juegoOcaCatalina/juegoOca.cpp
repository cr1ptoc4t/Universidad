/*
* CATALINA FULLANA MORA Y RAFAEL HERNANDO HERIAS
* Práctica Final Fundamentos de la Programación I
* 07/10/2022 - 6/11/2022
*
*
*/

#include <iostream>
#include <cstdlib>
using namespace std;

const int NUM_CASILLAS = 63;
const int CASILLA_PUENTE_1 = 6;
const int CASILLA_PUENTE_2 = 12;
const int CASILLA_DADOS_1 = 26;
const int CASILLA_DADOS_2 = 53;
const int TURNOS_POSADA = 1;
const int CASILLA_LABERINTO = 42;
const int CASILLA_POSADA = 19;
const int CASILLA_PRISION = 52;
const int CASILLA_MUERTE = 58;
const int CASILLA_POZO = 31;


bool esOca(int casilla);
bool esPuente(int casilla);
bool esDados(int casilla);
bool esLaberinto(int casilla);
bool esMuerte(int casilla);
bool esPosada(int casilla);
bool esPrision(int casilla);
bool esPozo(int casilla);
bool esMeta(int casilla);

int siguienteOca(int  casilla);
int siguientePuente(int casilla);
int siguienteDado(int casilla);
int siguienteLaberinto();
int siguienteMuerte();
int tirarDado();
int quienEmpieza();
int efectoPosicion(int casillaActual);
int efectoTiradas(int casillaActual, int numeroDeTiradas);

int main() {
	int casilla;
	int i = 0;
	/*
	cout << "Introduce casilla:";
	cin >> casilla;
	cout << esOca(casilla);
	*/

	return 0;
}


bool esOca(int casilla) {
	bool a;

	if ((casilla % 9 == 0 || (casilla % 9 == 5) && casilla != NUM_CASILLAS)) {
		a = true;
	}
	else { a = false; }


	return a;
}

bool esPuente(int casilla) {
	bool a;
	if (casilla == CASILLA_PUENTE_1 || casilla == CASILLA_PUENTE_2) {
		a = true;
	}
	else { a = false; }

	return a;
}

bool esDados(int casilla) {
	bool a;
	if (casilla == CASILLA_DADOS_1 || casilla == CASILLA_DADOS_2) {
		a = true;
	}
	else { a = false; }

	return a;
}

bool esLaberinto(int casilla) {
	bool a;

	if (casilla == CASILLA_LABERINTO) {
		a = true;
	}
	else { a = false; }

	return a;
}

bool esMuerte(int casilla) {
	bool a;
	if (casilla == CASILLA_MUERTE) {
		a = true;
	}
	else { a = false; }

	return a;
}

bool esPosada(int casilla) {
	bool a;
	if (casilla == CASILLA_POSADA) {
		a = true;
	}
	else { a = false; }

	return a;
}

bool esPrision(int casilla) {
	bool a;
	if (casilla == CASILLA_PRISION) {
		a = true;
	}
	else { a = false; }

	return a;
}

bool esPozo(int casilla) {
	bool a;
	if (casilla == CASILLA_POZO) {
		a = true;
	}
	else { a = false; }

	return a;
}

bool esMeta(int casilla) {
	bool a;
	if (casilla >= 63) {
		a = true;
	}
	else { a = false; }

	return a;
}


int siguienteOca(int casilla) {
	int i = 0; bool b = true;
	while (i<5 && b) {
		if(esOca(casilla+i)){
			b = false;
		}
		else { i++; }
	}
	return casilla +i ;
}

int siguientePuente(int casilla) {
	int i = 0; bool b = true;
	while (b) {
		if (esPuente(casilla + i)) {
			b = false;
		}
		else { i++; }
	}
	return casilla + i;
}

int siguienteDado(int casilla) {
	int i = 0; bool b = true;
	while (b) {
		if (esDados(casilla + i)) {
			b = false;
		}
		else { i++; }
	}
	return casilla + i;
}

int siguienteLaberinto() {
	return CASILLA_LABERINTO - 12;
	
}

int siguienteMuerte() {
	return 1;
}

int tirarDado() {
	int a = rand() % 7;
	return a;
}

int quienEmpieza() {
	int a = rand() % 2;
	return a;
}

int efectoPosicion(int casillaActual) {
	int a;
	if (esOca(casillaActual)) {
		a=siguienteOca(casillaActual+1); //si no añadimos el +1, devuelve la misma oca - TESTEAR
	} else if (esPuente(casillaActual)) {
		a = siguientePuente(casillaActual);
	} else if (esDados(casillaActual)) {
		a = siguienteDado(casillaActual);
	} else if (esLaberinto(casillaActual)) {
		a = siguienteLaberinto();
	} else if (esMuerte(casillaActual)) {
		a = siguienteMuerte();
	} else {
		a = casillaActual;
	}
	return a;
}

int efectoTiradas(int casillaActual, int numeroDeTiradas) {

	return 0;
}


