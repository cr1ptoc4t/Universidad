/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:


Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/


#include <iostream>
using namespace std;


/*

PRECONDICION DE LA FUNCION:
---Escribe aqu� la precondici�n de la funci�n.


*/


int /* resul */ long_tramo_par_mas_largo(int v[], unsigned int n);

/*
   POSTCONDICION DE LA FUNCION:
   ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
   ---al valor devuelto por la funci�n, utiliza la pseudo-variable
   ---'resul'
(1) Definiciones auxiliares (si procede):


(2) Postcondici�n



*/



/* DISE�O DEL ALGORITMO:
--- Detalla aqu� el proceso seguido para dise�ar el
--- algoritmo

PASO 1. Variables adicionales (aparte de los par�metros y el resultado)

PASO 2. Invariante
   (2.1) Definiciones auxiliares (si procede)



   (2.2) Invariante


PASO 3. C�digo de inicializaci�n, justificando que, tras
		dicho c�digo, se cumple el invariante


PASO 4. Condici�n del bucle, c�digo tras el bucle (si procede),
		y justificaci�n de que, una vez finalizado el algoritmo,
		se cumple la postcondici�n


PASO 5. Dise�o del cuerpo del bucle, justificando que dicho c�digo
		preserva el invariante


PASO 6: Expresi�n de cota y justificaci�n de que el algoritmo siempre
		termina


PASO 7: Determinaci�n justificada de la complejidad del algoritmo

*/


int /* resul */ long_tramo_par_mas_largo(int v[], int n) {
	/* IMPLEMENTACION */
	int long_max = 0;
	int ini=0;
	for (int fin = 0; fin < n; fin++) {
		if (v[fin] % 2 != 0) {
			//si encontramos num impar
			ini = fin + 1;
		}
		else {
			//si la longitud es mas grande que la longitud max
			long_max = max(long_max, fin-ini+1);
		}
	}

	return long_max;
}



/* PROGRAMA DE PRUEBA: No modificar */

const int MAX_ELEMS = 1000000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	static int v[MAX_ELEMS];
	if (n == -1) return false;
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << long_tramo_par_mas_largo(v, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}