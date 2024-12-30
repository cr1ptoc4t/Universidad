
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

bool sumdivisible(int n) {
	/* IMPLEMENTACION:
	   Esta funci�n ser� el punto de entrada a tu algoritmo.
	   Puedes implementar, adem�s, las funciones auxiliares
	   que consideres oportuno.
	   -- n: El n�mero cuya sumdivisibilidad debes determinar.
	   -- La funci�n deber� devolver 'true' si n es sumdivisible,
	   -- y 'false' en otro caso
	*/
	int dig;
	return sumdiv_aux(n, dig);

}

bool sumdiv_aux(int n, int& div,int& suma) {
	// Caso base: si el numero se reduce a 0
	if (n == 0) {
		return div == 1 || (suma % div == 0);
	}

	// Extraer el ultimo digito
	int digito = n % 10;
	suma += digito;
	div++;

	// Verificar si la suma actual es divisible por el divisor actual
	if (suma % div != 0) {
		return false;
	}

	// Llamar recursivamente con el numero reducido
	return sumdiv_aux(n / 10, div, suma);
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

