#include <iostream>
using namespace std;

bool compruebaNumero(int n);

int main() {
	int suma = 0;
	for (int i = 100; i < 1000; i++) {
		if(compruebaNumero(i)){
			suma++;
		}
	}

	cout << "hay un total de " << suma << " numeros" << endl;
}

bool compruebaNumero(int n) {
	int d1 = n / 100;
	int d2 = n / 10 - d1*10;
	int d3 = n - (d1 * 100 + d2 * 10);

	cout <<n <<"-- " << d1 << ", " << d2 << ", " << d3 << endl;

	bool num = false;
	if (pow(d1, 3)+ pow(d2, 3)+ pow(d3, 3)== n) {
		cout << "el numero " << n << " tambien se puede escribir como: " << d1 << "^3 + " << d2 << "^3 +" << d3 << "^3" << endl;
		num = true;
	}
	return num;
}