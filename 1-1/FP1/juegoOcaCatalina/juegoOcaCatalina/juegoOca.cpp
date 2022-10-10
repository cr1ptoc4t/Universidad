/*
* CATALINA FULLANA MORA Y RAFAEL HERNANDO HERIAS
* Práctica Final Fundamentos de la Programación I
* 07/10/2022 - 6/11/2022
* 
* 
*/

#include <iostream>
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

int main() {
	cout << "hay oca en la casilla 65?" << esOca(6) << endl;
	return 0;
}


bool esOca(int casilla) {
	bool a = false;
	int i = 5;
	
	//recorremos todas las casillas oca
	while (i<NUM_CASILLAS) {
		if (casilla = i) {
			a = true;
		} else { a = false;}

		//incrementamos el valor en 5 o en 4 en función de su posición en el tablero
		if (i%3==0) {
			i += 5;
		}
		else {
			i += 4;
		}
		
	}
	return a;
}


bool esPuente(int casilla) {
	bool a;
	if (casilla = CASILLA_PUENTE_1 || casilla == CASILLA_PUENTE_2) {
		a = true;
	}
	else { a = false; }
	return a;
}
bool esDados(int casilla) {
	bool a;
	if (casilla = CASILLA_DADOS_1 || casilla == CASILLA_DADOS_2) {
		a = true;
	}
	else { a = false; }
	return a;
}
bool esLaberinto(int casilla) {
	return 0;
}
bool esMuerte(int casilla) {
	return 0;
}
bool esPosada(int casilla) {
	return 0;
}
bool esPrision(int casilla) {
	return 0;
}
bool esPozo(int casilla) {
	return 0;
}
bool esMeta(int casilla) {
	return 0;
}


int siguienteOca(int casilla){
	return 0;
}
int siguientePuente(int casilla) {
	return 0;
}
int siguienteDado (int casilla){
	return 0;
}
int siguienteLaberinto() {
	return 0;
}
int siguienteMuerte() {
	return 0;
}

int tirarDado() {
	return 0;
}
int quienEmpieza() {
	return 0;
}
int efectoPosicion(int casillaActual) {
	return 0;
}
int efectoTiradas(int casillaActual, int numeroDeTiradas) {
	return 0;
}

