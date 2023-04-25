#include "partida.h"
#include <iostream>

using namespace std;


void iniciaPartida(tPartida& partida) {
	//crear array dinamico
}
void cargarPartida(ifstream& archivo, tPartida& partida) {
	char str;
	string nivel;
	archivo >> nivel>> partida.nivel;
	archivo >> partida.tablero.nFils >> partida.tablero.nCols;
	for (int i = 0; i < partida.tablero.nFils; i++){
		for (int j = 0; j < partida.tablero.nCols; j++) {
			archivo >> str;
			partida.tablero.tablero[i][j] = charToCelda(str);
		}
	}
	archivo >> partida.listaBombillas.cont;
	for (int i = 0; i < partida.listaBombillas.cont;i++) {
		archivo >> partida.listaBombillas.arrayPos[i].x;
		archivo >> partida.listaBombillas.arrayPos[i].y;
	}
	/*
	int numPartidas;
	archivo >> numPartidas;

	for (int i = 0; i < numPartidas;i++) {
		//guardar nivel
		partida[]
	}
	//num partidas
	// nivel
	//	num filas - columnas
	//	partidas
	//	bombillas
	archivo<<
	*/
}
bool operator<(const tPartida& partida, int nivel) {
	return partida.nivel < nivel;
}
bool operator<(const tPartida& partida1, const tPartida& partida2) {
	return partida1.nivel < partida2.nivel;
}
bool juega(tPartida& partida, int& nIt) {
	return false;
}
void guardarPartida(ofstream& archivo, const tPartida& partida) {

}
void destruyePartida(tPartida& partida) {
}