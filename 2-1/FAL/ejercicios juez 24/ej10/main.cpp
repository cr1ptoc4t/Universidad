
#include <iostream>

using namespace std;


/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- parámetro (en caso de que utilices una generalización), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
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
	// Caso base: si el número es menor que 10, tiene solo un dígito
	if (numero < 10) {
		return 1;
	}
	// Llamada recursiva: quita un dígito dividiendo entre 10 y suma 1 al resultado
	return 1 + contarDigitos(numero / 10);
}

bool sumdivisible(int n) {
	/* IMPLEMENTACION:
	   Esta función será el punto de entrada a tu algoritmo.
	   Puedes implementar, además, las funciones auxiliares
	   que consideres oportuno.
	   -- n: El número cuya sumdivisibilidad debes determinar.
	   -- La función deberá devolver 'true' si n es sumdivisible,
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

