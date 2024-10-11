#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  PARA_TODO i : 0<i<TAM(a): a[i]<k && 0<n<TAM(a)
*/

int llena_mochila(const int a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  
  max_prod= max{ SUMA MAX DE i A j : i<j y todos los elementos entre ellos son consecutivos


 */


 /*
 DISE�O DEL ALGORITMO:

 Paso 1. Variables


 Paso 2. Invariante


 Paso 3. Inicializaci�n

 Paso 4. Condici�n del bucle, y c�digo tras el bucle.


 Paso 5. Cuerpo del bucle

 Paso 6. Justificaci�n de que el algoritmo siempre termina.
 la ventana se va haciendo pequeña y no existe ningún elemento que pese
 más que k

 Paso 7. Complejidad: O(n)


 */

int llena_mochila(const int a[], int n, int k) {

	int ini = 0;
	int fin;
	int suma_act=0;
	int max_prod=0;
	for (int fin = 0; fin < n; fin++) {
		suma_act += a[fin];

		while (suma_act > k) {
			suma_act -= a[ini];
			ini++;
		}

		if (fin - ini + 1 > max_prod)
			max_prod = fin - ini + 1;
	}
	
	return max_prod;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	static int a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n >= 0) {
			int k;
			cin >> k;
			cout << llena_mochila(a, n, k) << endl;
		}
	} while (n != -1);
}