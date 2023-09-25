using namespace std;
#include <iostream>

int moda(int v[], int n);

int main() {
	int v[25000];
	int n;
	//leer enttrada vector
	
	//ordenar vector
	
	moda(v, n);
	return 0;
}

//supone que está ordenado
int moda(int v[], int n) {
	int ret;

	int repe[25000]; //guarda frecuencias en sus indices

	for (int i = 0; i < n; i++) {
		repe[v[i]]++;
	}

	//buscar el mayor del repe
	int mayor = 0;
	for (int i = 0; i < n; i++) {
		if (repe[i] > mayor)
			mayor = repe[i];
	}

	return mayor;
}