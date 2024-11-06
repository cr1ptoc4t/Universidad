
#include <iostream>

using namespace std;


/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado.
-- Escribe y resuelve las ecuaciones de recurrencia.

*/


bool sumdiv_aux(int n, int ndig) {
	
	if (ndig == 1) return true;
	
	//int ndig = 0;
	int copia = n;
	int suma = 0;

	while (copia > 0) {
		suma += copia % 10;
		copia /= 10;
		//ndig++;
	}

	return suma%ndig == 0 && sumdiv_aux(n/10, ndig-1);
	


}
int contarDigitos(int numero) {
	// Caso base: si el n�mero es menor que 10, tiene solo un d�gito
	if (numero < 10) {
		return 1;
	}
	// Llamada recursiva: quita un d�gito dividiendo entre 10 y suma 1 al resultado
	return 1 + contarDigitos(numero / 10);
}

bool sumdivisible(int n) {
	/* IMPLEMENTACION:
	   Esta funci�n ser� el punto de entrada a tu algoritmo.
	   Puedes implementar, adem�s, las funciones auxiliares
	   que consideres oportuno.
	   -- n: El n�mero cuya sumdivisibilidad debes determinar.
	   -- La funci�n deber� devolver 'true' si n es sumdivisible,
	   -- y 'false' en otro caso
	*/
	int numdig = contarDigitos(n);
	return sumdiv_aux(n, numdig);
}

/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA:
   NO MODIFICAR */

int main() {
	int n;
	do {
		cin >> n;
		if (n > 0) {
			if (sumdivisible(n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n > 0);
}

