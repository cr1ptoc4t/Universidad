/*
NOMBRE Y APELLIDOS:CATALINA FULLANA MORA

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/

#include <iostream>
using namespace std;


/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada del dise�o sistem�tico del mismo.
*/


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



(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(4.2) Resoluci�n utilizando los patrones vistos en clase

(4.3) Determinaci�n justificada de la complejidad del algoritmo final.



*/


bool es_superb_aux(int v[], int ini, int fin) {
	int n = fin - ini;
	if (n < 3) return true;

	int mid = (ini + fin) / 2;


	int max_antes = v[ini];
	for (int i = ini; i < mid; i++) {
		if (v[i] > max_antes)
			max_antes = v[i];
	}

	int min_desp = v[mid + 1];
	for (int i = mid + 1; i < fin; i++) {
		if (v[i] < min_desp)
			min_desp = v[i];
	}

	int dif = max_antes - min_desp;
	if (dif < 0) dif = -dif;
	return v[mid] == dif
		&& es_superb_aux(v, ini, mid - 1)
		&& es_superb_aux(v, mid + 1, fin);


}

bool es_superb(int v[], int n) {
	return es_superb_aux(v, 0, n);
}


/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).


const static int MAX_ELEMENTS = 10000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		int v[MAX_ELEMENTS];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (es_superb(v, n)) {
			cout << "SUPERB" << endl;;
		}
		else {
			cout << "NO SUPERB" << endl;
		}
		return true;
	}
}


int main() {
	while (ejecuta_caso());
	return 0;
}