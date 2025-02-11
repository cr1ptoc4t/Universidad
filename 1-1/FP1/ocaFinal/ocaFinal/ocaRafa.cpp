
#include <iostream>
#include<cstdlib>

using namespace std;

int casilla;
int casillaActual;
int numeroDeTiradas;

const bool MODO_DEBUG = true;

const int NUM_CASILLAS = 63;
const int CASILLA_PUENTE1 = 6;
const int CASILLA_PUENTE2 = 12;
const int CASILLA_DADO1 = 26;
const int CASILLA_DADO2 = 53;
const int CASILLA_POSADA = 19;
const int CASILLA_PRISION = 52;
const int CASILLA_POZO = 31;
const int CASILLA_LABERINTO = 42;
const int CASILLA_MUERTE = 58;
const int CASILLA_META = 63;

const int TURNOS_POSADA=1;
const int TURNOS_PRISION=2;
const int TURNOS_POZO=3;


bool esOca(int casilla);
bool esPuente(int casilla);
bool esDados(int casilla);
bool esPosada(int casilla);
bool esPrision(int casilla);
bool esPozo(int casilla);
bool esLaberinto(int casilla);
bool esMuerte(int casilla);
bool esMeta(int casilla);

int siguienteOca(int casilla);
int siguientePuente(int casilla);
int siguienteDado(int casilla);
int siguienteLaberinto();
int siguienteMuerte();

int tirarDado(bool d); //el booleano que le pasamos como argumento ser� MODO_DEBUG
int quienEmpieza();
int efectoPosicion(int casillaActual);
int efectoTiradas(int casillaActual, int numeroDeTiradas);

int main() {
	int casillaJ1, casillaJ2;

	casillaActual = 1;
	numeroDeTiradas = 1;

	if (MODO_DEBUG) {
		cout << "---------MODO DEPURACION: ACTIVADO---------" << endl;
	}

	srand(time(NULL));

	int empieza = quienEmpieza();

	cout << "Empieza el jugador:" << empieza << endl;
	cout << "Estas en la casilla 1." << endl;

	if (empieza == 1) {
		casillaJ1 = casillaActual;
	} else if (empieza == 2) {
		casillaJ2 = casillaActual; 
	}

	while (!esMeta(casillaActual)) {
		while (numeroDeTiradas > 0 && !esMeta(casillaActual)) {
			casillaActual = casillaActual + tirarDado(MODO_DEBUG);
			
			cout << "estas en la casilla:" << casillaActual << endl;
			cout << efectoPosicion(casillaActual) << endl;
			casillaActual = efectoPosicion(casillaActual);
			efectoTiradas(casillaActual, numeroDeTiradas);

		}
		if (quienEmpieza() == 1) {
			casillaJ2 = casillaActual;
		}
		else if (quienEmpieza() == 2) {
			casillaJ1 = casillaActual;
		}
	}

	return 0;
}


//CASILLAS ESPECIALES////////////////////////////////////////////////////////////////////////////////////
bool esOca(int casilla) {
	bool a;
	if (casilla % 9 == 0 || casilla % 9 == 5) {
		a = true;
	}
	else { a = false; }
	return a;
}

bool esPuente(int casilla) {
	bool a;
	if (casilla == CASILLA_PUENTE1 || casilla == CASILLA_PUENTE2) {
		a = true;
	}
	else { a = false; }
	return a;
}

bool esDados(int casilla) {
	bool a;
	if (casilla == CASILLA_DADO1 || casilla == CASILLA_DADO2) {
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

bool esMeta(int casilla) {
	bool a;
	if (casilla == CASILLA_META) {
		a = true;
	}
	else { a = false; }
	return a;
}

//SIGUIENTE CASILLA///////////////////////////////////////////////////////////////////////////////////////////////////
int siguienteOca(int casilla) {
	int b;
	if (casilla % 9 == 0) {
		b = casilla + 5;
	}
	else if (casilla % 9 == 5) {
		b = casilla + 4;
	}
	else {
		b = 0;
	}

	return b;
}

int siguientePuente(int casilla) {
	int b;
	if (casilla == CASILLA_PUENTE1) {
		b = CASILLA_PUENTE2;
	}

	else if (casilla == CASILLA_PUENTE2) {
		b = CASILLA_PUENTE1;
	}
	return b;
}

int siguienteDado(int casilla) {
	int b;

	if (casilla == CASILLA_DADO1) {
		b = CASILLA_DADO2;
	}

	else if (casilla == CASILLA_DADO2) {
		b = CASILLA_DADO1;
	}

	return b;
}

int siguienteLaberinto() {
	return CASILLA_LABERINTO-12;
}

int siguienteMuerte() {
	return 1;
}


//FUNCIONES REGULADORAS DEL JUEGO////////////////////////////////////////////////////////////////////////////////////7
int tirarDado(bool d) {
	int a = 0;
	cout << endl;
	if (d) {
		cout << "Introduce valor del dado:";
		cin >> a;
		while (a > 6 || a < 1) {
			cout << "ERROR: el numero debe pertenecer al intervalo [1,6]." << endl;
			cout << "Elige otro numero:";
			cin >> a;
		}
	}
	else {
		int a = rand() % 7;
		cout << "Valor del dado: " << a << endl;
	}

	return a;
}

int quienEmpieza() {
	int limiteInferior = 1;
	int limiteSuperior = 2;
	int empezar;
	empezar = limiteInferior + rand() % (limiteSuperior + 1 - limiteInferior);
	return empezar;
}


int efectoPosicion(int casillaActual) {
	int a;
	if (esOca(casillaActual)) {
		a = siguienteOca(casillaActual);
		if (a != 63) { // !=63 porque al llegar a la casilla 63 ya no saltaremos a la siguiente oca
			cout << "De oca en oca y tiro porque me toca" << endl;
		}
	}
	else if (esPuente(casillaActual)) {
		a = siguientePuente(casillaActual);
		cout << "De puente en puente y tiro porque me lleva la corriente" << endl;
	}
	else if (esDados(casillaActual)) {
		a = siguienteDado(casillaActual);
		cout << "De dado a dado y tiro porque me ha tocado" << endl;
	}
	else if (esLaberinto(casillaActual)) {
		a = siguienteLaberinto();
		cout << "Has caido en el laberinto, retrocedes 12 casillas:(" << endl;
	}
	else if (esMuerte(casillaActual)) {
		a = siguienteMuerte();
		cout << "Has caido en la muerte! regresas a la primera casilla" << endl;
	}
	else { a = casillaActual; }

	if (casillaActual != a) { // si ha habido algun cambio de casilla:
		if (!esMuerte(casillaActual) && !esLaberinto(casillaActual)) { //las unicas casillas que nos hacen retroceder
			cout << "Avanzas de casilla!" << endl;
		}
		cout << "CASILLA ANTERIOR: " << casillaActual << endl;
	}
	if (casillaActual <= 63) {
		cout << "CASILLA ACTUAL: " << a << endl;
	}
	else { cout << "CASILLA ACTUAL: 63" << endl; }

	return a;

}

int efectoTiradas(int casillaActual, int numeroDeTiradas) {

	if (esOca(casillaActual) || esDados(casillaActual)) {
		numeroDeTiradas++;
	} else if (esPozo(casillaActual)) {
		numeroDeTiradas = numeroDeTiradas - TURNOS_POZO;
	} else if (esPrision(casillaActual)) {
		numeroDeTiradas = numeroDeTiradas - TURNOS_PRISION;
	} else if (esPosada(casillaActual)) {
		numeroDeTiradas = numeroDeTiradas - TURNOS_POSADA;
	} else if (esPuente(casillaActual)) {
		numeroDeTiradas++;
	}

	numeroDeTiradas--;

	return numeroDeTiradas;
}