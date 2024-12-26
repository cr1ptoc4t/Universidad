#include <iostream>
#include <algorithm>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.



*/


int misterio(const int a[], int n) {

	int num_act = a[0];
	int freq_act = 1;
	int freq_max = 1;
	int num_freq_max = a[0];
	for (int i = 1; i < n; i++) {
		num_act = a[i];
		if (num_act != a[i-1]) {
			if (freq_max < freq_act) {
				freq_max = freq_act;
				num_freq_max = a[i - 1];
			}
			freq_act = 1;
		}
		else { freq_act++; }
	}

	if (freq_max < freq_act) {
		freq_max = freq_act;
		num_freq_max = a[n - 2];
	}

	return num_freq_max;
}

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema


*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR */

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
			cout << misterio(a, n) << endl;
		}
	} while (n != -1);
}