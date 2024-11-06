#include <iostream>
using namespace std;

/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado. o(n)
-- Escribe y resuelve las ecuaciones de recurrencia.

*/
int contarDigitos(int numero) {
	// Caso base: si el número es menor que 10, tiene solo un dígito
	if (numero < 10) {
		return 1;
	}
	// Llamada recursiva: quita un dígito dividiendo entre 10 y suma 1 al resultado
	return 1 + contarDigitos(numero / 10);
}

int potencia(int base, int exponente) {
	int resultado = 1;
	for (int i = 0; i < exponente; ++i) {
		resultado *= base;  // Multiplica la base por sí misma 'exponente' veces
	}
	return resultado;
}

bool es_interesante_recursivo(unsigned int n, int ndigitos, int suma_significat) {
	
	if (n < 10) return true;

	int num_act = n/potencia(10, ndigitos-1);
	
	if (num_act == 0) return false;

	int suma_menos_sig = 0;
	int num_sig = n % potencia(10, ndigitos - 1);
	
	int copia = num_sig;
	while (copia>0) {
		suma_menos_sig += copia%10;
		copia /= 10;
	}
	bool condicion = (suma_significat == 0 || suma_significat % num_act == 0) && (suma_menos_sig == 0 || suma_menos_sig % num_act  == 0);
	//cout << "numero act: " << num_act << " num sig: " << num_sig << "suma_sig:" << suma_significat
	//	<< "condicion" << condicion << endl;
	return condicion && es_interesante_recursivo(num_sig,ndigitos-1,suma_significat+num_act );
}

bool es_interesante(unsigned int n) {
	int ndigitos = contarDigitos(n);
    return es_interesante_recursivo(n,ndigitos, 0);
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}