#include "partida.h"
#include <iostream>

using namespace std;


void iniciaPartida(tPartida& partida) {
	//crear array dinamico
}
void cargarPartida(ifstream& archivo, tPartida& partida) {

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