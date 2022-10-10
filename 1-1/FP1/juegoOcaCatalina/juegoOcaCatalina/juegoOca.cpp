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

int main() {
	cout << "hay oca en la casilla 65?" << esOca(63) << endl;
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
/*
bool esPuente(int casilla) {

}
bool esDados(int casilla) {

}
bool esLaberinto(int casilla) {

}
bool esMuerte(int casilla) {

}
bool esPosada(int casilla) {

}
bool esPrision(int casilla) {

}
bool esPozo(int casilla) {

}
bool esMeta(int casilla) {

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


*/