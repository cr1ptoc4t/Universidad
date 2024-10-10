
#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  P: { 0<=n<tam(a)
*/

int tramo_mas_corto(bool a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
​
 

 */


 /*
 DISE�O DEL ALGORITMO:

 Paso 1. Variables


 Paso 2. Invariante


 Paso 3. Inicializaci�n

 Paso 4. Condici�n del bucle, y c�digo tras el bucle.


 Paso 5. Cuerpo del bucle

 Paso 6. Justificaci�n de que el algoritmo siempre termina.
	fin avanza en cada iteración y n nunca cambia. en algun momento fin tiene que "superar"
	al valor de n

 Paso 7. Complejidad:
 O(n)

 */



int tramo_mas_corto(bool a[], int n, int k) {
	// A IMPLEMENTAR
	int inicio = 0; 
	int contador = 0;
	int min_tamano = n + 1;

	for (int fin = 0; fin < n; ++fin) {
		if (a[fin]) { 
			contador++;
		}

		while (contador == k) {
			min_tamano = min(min_tamano, fin - inicio + 1);

			if (a[inicio]) {
				contador--; 
			}
			inicio++;  
		}
	}

	return (min_tamano == n + 1) ? n + 1 : min_tamano;
}

/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA:
   NO MODIFICAR */


void lee_caso(int& n, bool a[], int& k) {
	cin >> n;
	if (n != -1) {
		for (int i = 0; i < n; i++) {
			int elem;
			cin >> elem;
			a[i] = bool(elem);
		}
		cin >> k;
	}
}

const int MAX_TAM = 100;
int main() {
	int n;
	bool a[MAX_TAM];
	int k;
	do {
		lee_caso(n, a, k);
		if (n != -1) {
			cout << tramo_mas_corto(a, n, k) << endl;
		}
	} while (n != -1);
}

