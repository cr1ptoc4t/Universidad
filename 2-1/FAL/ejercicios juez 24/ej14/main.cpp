
#include <iostream>
#include <algorithm>

using namespace std;


/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

(4) An�lisis de la complejidad del algoritmo

*/

int min_poder_aux(int enemigos[], int ini, int fin, int max_duelos) {
	if (max_duelos == 1) {
		// Si solo se permite un torneo, necesitamos el total de poder de todos los enemigos en el rango
		int suma = 0;
		for (int i = ini; i <= fin; ++i) {
			suma += enemigos[i];
		}
		return suma;
	}
	
	if (fin == ini)
		return enemigos[ini];

	int mitad = (ini + fin) / 2;

	int max_izq = min_poder_aux(enemigos, ini, mitad, max_duelos -1);
	int max_der = min_poder_aux(enemigos, mitad+1, fin, max_duelos - 1);
	
	//int max_mitad = aux(enemigos, ...);

	int max_abs = max(max_izq, max_der);
	//max_abs = max(max_abs, max_mitad);
	return max_abs;
}

int min_poder(int enemigos[], int n, int max_duelos) {
	// Punto de entrada al algoritmo: a implementar
	return min_poder_aux(enemigos, 0, n-1, max_duelos);
}


const int MAX_ENEMIGOS = 1000;
bool ejecuta_caso() {
	int enemigos[MAX_ENEMIGOS];
	int num_enemigos;
	cin >> num_enemigos;
	if (num_enemigos == -1) {
		return false;
	}
	else {
		int max_torneos;
		cin >> max_torneos;
		for (int i = 0; i < num_enemigos; i++) {
			cin >> enemigos[i];
		}
		cout << min_poder(enemigos, num_enemigos, max_torneos) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}