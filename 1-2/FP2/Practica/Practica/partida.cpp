#include "partida.h"
#include "celda.h"
#include <iostream>

using namespace std;


void iniciaPartida(tPartida& partida) {
	iniciaListaPosiciones(partida.listaBombillas);
	iniciarTablero(partida.tablero);
}

void cargarPartida(ifstream& archivo, tPartida& partida) {
	char str;
	string nivel;
	int f, c, n ;
	archivo >> nivel >> n;
	archivo >> f >> c;
	
	setNivel(partida, n);
	setNumFils(partida.tablero, f);
	setNumCols(partida.tablero, c);

	for (int i = 0; i < f; i++) {		//partida.tablero.nFils
		for (int j = 0; j < c; j++) {	//partida.tablero.nCols
			archivo >> str;
			ponCeldaEnPos(partida.tablero, i, j, charToCelda(str));
		}
	}

	archivo >> n;
	setCont(partida.listaBombillas, n);	//setCont(getListaBomb(partida), n);
	tCelda celda;
	int x, y;
	for (int i = 0; i < n; i++) { //	partida.listaBombillas.cont
		archivo >> x; 
		archivo >> y;
		partida.listaBombillas.arrayPos->x = x;				//GETTER
		partida.listaBombillas.arrayPos->y = y;

	}
}
bool operator<(const tPartida& partida, int nivel) {
	return partida.nivel < nivel;
}

bool operator<(const tPartida& partida1, const tPartida& partida2) {
	return partida1.nivel < partida2.nivel;
}

bool juega(tPartida& partida, int& nIt) {
	int a=0, b=0;
	colocaBombillas(partida);
	cout << "Tablero de nivel "<<partida.nivel<<endl;
	mostrarTablero(partida.tablero);

	while (!(estaTerminado(partida.tablero) || esPosQuit(a, b))) {
		cout << "Pos: ";
		cin >> a >> b;

		if (esPosReset(a, b)) {
			nIt = 1;
		}

		ejecutarPos(partida.tablero, a, b);
		mostrarTablero(partida.tablero);
		nIt++;
	}

	if (esPosQuit(a, b))
		cout << "Gracias por jugar, nos vemos a la proxima" << endl;
	else{
		cout << "Has completado el juego" << endl;
		mostrarTablero(partida.tablero);
	}
	//guardar en listaBombillas posicion de bombillas y num
	return esPosQuit(a, b);
}

int getNivel(const tPartida& partida) {
	return partida.nivel;
}

tTablero getTablero( tPartida& partida)	{
	return partida.tablero;
}

tListaPosiciones getListaBomb(tPartida& partida) {
	return partida.listaBombillas;
}

void guardarPartida(ofstream& archivo, const tPartida& partida) {
	archivo << "LEVEL " << getNivel(partida) << endl;
	archivo << getNumFilas(partida.tablero) <<" " << getNumCols(partida.tablero) << endl;
	for (int i = 0; i < getNumFilas(partida.tablero); i++) {
		for (int j = 0; j < getNumCols(partida.tablero); j++) {
			char a = celdaToCharArchivo(celdaEnPos(partida.tablero, i, j));
			if (esParedRestringida(celdaEnPos(partida.tablero, i, j)))
				 archivo << int(a);
			else archivo << a;
		}
		archivo << endl;
	}
	archivo << dameNumElem(partida.listaBombillas) << endl;
	for (int i = 0; i < dameNumElem(partida.listaBombillas); i++)
		guardarPosicion(archivo,dameElem(partida.listaBombillas, i));	//ESTO NO ESTA BIEN
	
}
void destruyePartida(tPartida& partida) {
	setNumFils(partida.tablero,0);
	setNumCols(partida.tablero, 0);
	destruyeListaPosiciones(partida.listaBombillas);
}

void setNivel(tPartida& partida, int nivel) {
	partida.nivel = nivel;
}

void colocaBombillas(tPartida& partida) {
	for (int i = 0; i < dameNumElem(partida.listaBombillas); i++){
		ejecutarPos(partida.tablero, dameX(dameElem(partida.listaBombillas, i)), dameY(dameElem(partida.listaBombillas, i)));
	}
}