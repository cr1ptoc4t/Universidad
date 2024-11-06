#include <iostream>
#include <algorithm>
using namespace std;


/*
(1) Precondici�n

(2) Postcondici�n

(3) Si vas a utilizar una generalizaci�n, especificaci�n
	pre-pos de la generalizaci�n

(4) Casos no recursivos

(5) Casos recursivos

(6) Terminaci�n (expresi�n de cota)

(7) Si has usado una generalizaci�n, definici�n por
	inmersi�n de es_paracurioso

(8) Determinaci�n de la complejidad (recurrencias y su resoluci�n)


*/


bool es_parcurioso(int v[], int ini, int fin) {
	
	if (fin - ini + 1 == 1) { return true; }

	int mitad = (ini+fin) / 2;

	int npares_prim=0;
	int sumapares_prim=0;

	for (int i = ini; i <= mitad; i++) {
		if (v[i] % 2 == 0) {
			npares_prim++;
			sumapares_prim += v[i];
		}
	}


	int sumaimpares_seg=0;
	int nimpares_seg=0;
	for (int i = mitad+1; i <= fin; i++) {
		if (v[i] % 2 == 1) {
			nimpares_seg++;
			sumaimpares_seg += v[i];
		}
	}


	return npares_prim <= nimpares_seg && sumapares_prim <= sumaimpares_seg
		&& (es_parcurioso(v, ini, mitad)||es_parcurioso(v, mitad+1, fin));
}		


bool /* resul*/ es_parcurioso(int v[], int n) {
	return es_parcurioso(v, 0, n-1);
}

// NO MODIFICAR

const static int MAX_ELEMENTS = 100000;

void ejecuta_caso() {
	static int v[MAX_ELEMENTS];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (es_parcurioso(v, n)) {
		cout << "SI" << endl;;
	}
	else {
		cout << "NO" << endl;
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		ejecuta_caso();
	return 0;
}