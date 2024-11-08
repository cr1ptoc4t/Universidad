/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:
CATALINA FULLANA MORA

Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/

#include<iostream>

using namespace std;



/*
(1) ESPECIFICACION:

(2) GENERALIZACION (EN CASO DE QUE PROCEDA), Y SU ESPECIFICACION


(3) DISE�O
	se divide el array cada vez en tres partes (izquierda, derecha y elemento
	central) que van comparando los dos últimos parámetros. En el caso base se
	toman los valores iniciales y durante la recursión se van ajustando al tramo
	correspondiente.

(4) TERMINACI�N
	expresión de cota; fin-ini

(5) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE
	he añadido los siguientes parametros:
		- ini y fin: para delimitar el espacio a recorrer del vector
		- num_menor y num_mayor: representan los numeros mas pequeños y mas grandes,
		respectivamente, en cada tramo delimitado por ini y fin.

(6) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO
	O(n) puesto que siempre recorres todo el vector una sola vez
*/


bool es_regular_aux(int a[], int ini, int fin, int &num_menor, int& num_mayor) {
	int n = fin - ini + 1;
	if ( n < 3) { 
		if (n == 2) {
			num_mayor = max(a[ini],a[fin]);

			num_menor = min(a[ini], a[fin]);

			return !(a[ini] == a[fin]);
		}
		else {
			num_mayor = num_menor = a[ini];
		}

		return true;
	}

	int mid = (ini + fin) / 2;
	int elem_cent = a[mid];


	int num_menor_izq, num_menor_der;

	int num_mayor_izq, num_mayor_der;

	bool izq = es_regular_aux(a, ini, mid - 1, num_menor_izq, num_mayor_izq);
	bool der = es_regular_aux(a, mid + 1, fin, num_menor_der, num_mayor_der);

	num_menor = min(num_menor_der, num_menor_izq);
	num_menor = min(num_menor, elem_cent);

	num_mayor = max(num_mayor_izq, num_mayor_der);
	num_mayor = max(num_mayor, elem_cent);

	return elem_cent > num_mayor_izq && elem_cent > num_mayor_der
		&& num_menor_izq != a[mid] && num_menor_der != a[mid]
		&& num_menor_der != num_menor_izq && izq && der;

	//return elem_cent > num_mayor && num_mayor_izq > num_mayor &&
	//	elem_cent > num_mayor_izq && izq && der;

}


bool es_regular(int a[], int n) {
	// A IMPLEMENTAR
	int num_menor,num_mayor ;
	return es_regular_aux(a, 0, n-1, num_menor, num_mayor);
}


/* A PARTIR DE AQUI, NO MODIFICAR NADA */

const int MAX_TAM = 1000000;
const int REPS = 500;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		static int a[MAX_TAM];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		if (n == MAX_TAM) {
			for (int i = 0; i < REPS; i++) {
				es_regular(a, n);
			}
		}
		if (es_regular(a, n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}