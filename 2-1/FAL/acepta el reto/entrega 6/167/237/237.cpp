using namespace std;
#include <iostream>
#include <string>

bool esPolidivisible(long long int n, int tamano);
int numDigitos(long long int n);

bool resuelveCaso2() {
	int numero;

	if (!cin)
		return false;
	

	cin >> numero;

	int tamano = numDigitos(numero);

	bool polidiv = esPolidivisible(numero, tamano);

	if (polidiv)
		cout << "POLIDIVISIBLE\n";
	else
		cout << "NO POLIDIVISIBLE\n";

	return true;

}

bool resuelveCaso() {
	long long int num;
	cin >> num;
	string numero;
	numero = to_string(num);
	if (!cin)
		return false;

	bool poli = esPolidivisible(num, numero.size());

	if (poli) cout << "POLIDIVISIBLE\n";
	else cout << "NO POLIDIVISIBLE\n";
	return true;
}


int main() {
	
	while (resuelveCaso())
		;

	return 0;
}


bool esPolidivisible(long long int n, int tamano) {
	if (tamano==1) {
		return true;
	}

	return (n % tamano == 0 && esPolidivisible(n / 10, tamano - 1));
}

int numDigitos(long long int n) {
	int ret = 1;
	while (n >= 10) {
		n /= 10;
		ret++;
	}
	return ret;
}