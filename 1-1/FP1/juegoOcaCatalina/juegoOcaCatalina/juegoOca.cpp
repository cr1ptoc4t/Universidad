/*
* CATALINA FULLANA MORA Y RAFAEL HERNANDO HERIAS
* Práctica Final Fundamentos de la Programación I
* 07/10/2022 - 6/11/2022
*
*/

/*
* turnos en efectoTiradas() --> ??????
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

const bool MODO_DEBUG = true;


bool esOca(int casilla);
bool esPuente(int casilla);
bool esDados(int casilla);
bool esLaberinto(int casilla);
bool esMuerte(int casilla);
bool esPosada(int casilla);
bool esPrision(int casilla);
bool esPozo(int casilla);
bool esMeta(int casilla);
bool hayGanador(int j1, int j2);

int siguienteOca(int  casilla);
int siguientePuente(int casilla);
int siguienteDado(int casilla);
int siguienteLaberinto();
int siguienteMuerte();
int tirarDado(bool d);
int quienEmpieza();
int efectoPosicion(int casillaActual);
int efectoTiradas(int casillaActual, int numeroDeTiradas);

int juegoInterno(int jugador);

void chequeaGanador(int j1, int j2);


int main() {
	//int casilla;
	int iteracion = 0;
	int j1 = 1;
	int j2 = 1;
	int nTiradasj1 = 1;
	int nTiradasj2 = 1;
	
	int empieza;
	

	if (MODO_DEBUG) {
		cout << "---------MODO DEPURACION: ACTIVADO---------" << endl;
	}

	empieza = quienEmpieza();
	



	// TO-DO:
	// función debug
	// método efectoTiradas()
	// pedir quien empieza
	// PENSAR COMO LO HAREMOS PARA EMPEZAR DESPUÉS DE HABER PEDIDO QUIEN EMPIEZA
	// DOS WHILE
	// CONSTRUIR TODO EL MAIN
	// PROBAR MÉTODOS

	//CUANDO HAY CAMBIO DE TURNO:
	//numeroDeTiradas = -numeroDeTiradas +1;

	// DOS WHILE ANIDADOS -- While 1:  mientras ninguno de los dos jugadores esté en una casilla igual o superior a la 63
	// WHILE INTERNO MIENTRAS NO HAYA GANADOR Y NO TENGA NUMERO DE TIRADAS, TIRAR
	// char c; cin c;
	// while para testear con diferentes numeros de casilla;
	
	/*
	* FUNCIONAMIENTO:
	* se lanza el dado en modo debug o no						hecho
	* se decrementa numeroDeTiradas								
	* se actualiza valor de la casilla actual					hecho
	* se comprueba si la casilla es especial					hecho
	* Se comprueba si hay que actualizar el numero de turnos	hecho
	*/


	while (!hayGanador(j1, j2)) {
		//while (numeroDeTiradas > 0 && !esMeta(casillaActual)) {
		//}
		cout << endl;
		cout << "///////////////////////////////////////////" << endl;
		if (iteracion%2==0) {
			nTiradasj1 = 1;
			cout << "TURNO JUGADOR 1" << endl;
			while (nTiradasj1>0) {
				cout << "Casilla actual:" << j1 << endl;
				j1 = juegoInterno(j1);
				nTiradasj1 = efectoTiradas(j1, nTiradasj1);
			}
		}
		else {
			nTiradasj2 = 1;
			cout << "TURNO JUGADOR 2" << endl;
			while (nTiradasj2>0) {
				cout << "Casilla actual:" << j2 << endl;
				j2 = juegoInterno(j2);
				nTiradasj2 = efectoTiradas(j2,nTiradasj2);
			}
		}
		

		//nTiradasj1 = efectoTiradas(j1, nTiradasj1);
		iteracion++;
		cout << "" << endl;

	}

	// muestra el ganador por pantalla
	chequeaGanador(j1,j2);
	
	
	return 0;
}

int juegoInterno(int jugador) {
	jugador = jugador + tirarDado(MODO_DEBUG);
	jugador = efectoPosicion(jugador);
	return jugador;
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
	int i = 1; bool b = true;
	while (i<5 && b) {
		if(esOca(casilla+i)){
			b = false;
		}
		else { i++; }
	}
	if (casilla >= 63) {
		i = 0;
	}
	return casilla +i ;
}

int siguientePuente(int casilla) {
	if (casilla ==CASILLA_PUENTE_1) {
		casilla = CASILLA_PUENTE_2;
	}
	else if(casilla== CASILLA_PUENTE_2) {
		casilla = CASILLA_PUENTE_1;
	}
	return casilla;
}

int siguienteDado(int casilla) {
	int i = 1; bool b = true;
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

int tirarDado(bool d) {
	int a=0;
	cout << endl;
	if (d) {
		cout << "Introduce valor del dado:";
		cin >> a;
		while (a>6 || a<1) {
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
	int a = rand() % 2;
	cout << ">>>>>>> EMPIEZA EL JUGADOR NÚMERO " << a << " <<<<<<<" << endl;
	return a;
}

int efectoTiradas(int casillaActual, int numeroDeTiradas) {
	if (esOca(casillaActual) || esDados(casillaActual)) {
		numeroDeTiradas++;
	} else if (esPozo(casillaActual)) {
		numeroDeTiradas = numeroDeTiradas - 3;
	} else if (esPrision(casillaActual)) {
		numeroDeTiradas = numeroDeTiradas - 2;
	} else if (esPosada(casillaActual)) {
		numeroDeTiradas-=2;
	}
	else {
		numeroDeTiradas--;
	}

	return numeroDeTiradas;
}

int efectoPosicion(int casillaActual) {
	int a;
	if (esOca(casillaActual)) {
		a = siguienteOca(casillaActual);
		if (a!=63) {
			cout << "De oca en oca y tiro porque me toca" << endl;

		}
	} else if (esPuente(casillaActual)) {
		a = siguientePuente(casillaActual);
		cout << "De puente en puente y tiro porque me lleva la corriente" << endl;
	} else if (esDados(casillaActual)) {
		a = siguienteDado(casillaActual);
		cout << "De dado a dado y tiro porque me ha tocado" << endl;
	} else if (esLaberinto(casillaActual)) {
		a = siguienteLaberinto();
		cout << "Has caido en el laberinto, retrocedes 12 casillas:(" << endl;
	} else if (esMuerte(casillaActual)) {
		a = siguienteMuerte();
		cout << "Has caido en la muerte! regresas a la primera casilla" << endl;
	} else {
		a = casillaActual;
	}

	if (casillaActual != a) {
		if (!esMuerte(casillaActual) && !esLaberinto(casillaActual)) {
			cout << "Avanzas de casilla!" << endl;
		}
		cout << "CASILLA ANTERIOR: " << casillaActual << endl;
	}
	if (casillaActual<=63){
		cout << "CASILLA ACTUAL: " << a << endl;
	} else{ cout << "CASILLA ACTUAL: 63"<< endl; }
	
	return a;

}

//mira quien es el ganador y lo imprime por pantall
void chequeaGanador(int j1, int j2) {
	int ganador;
	if (esMeta(j1) || esMeta(j2)) {
		if (esMeta(j1)) {
			ganador = 1;
		}
		else if (esMeta(j2)) {
			ganador = 2;
		}
		cout << "HA GANADO EL JUGADOR: " << ganador << endl;
	}
}


//devuelve si hay o no hay ganador
bool hayGanador(int j1, int j2) {
	bool a;
	
	if (esMeta(j1) || esMeta(j2)) {
		a=true;
	}
	else {
		a= false;
	}
	return a;
}
