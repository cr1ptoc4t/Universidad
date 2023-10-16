using namespace std;
#include <iostream>

bool esPolidivisible(long long n);
int numDigitos(long long n);

int main() {
	int numero;
	while (cin) {
		cin >> numero;
		if (esPolidivisible(numero))
			cout << "POLIDIVISIBLE" << endl;
		else
			cout << "NO POLIDIVISIBLE" << endl;
	}

	return 0;
}


bool esPolidivisible(long long n) {
	if (n < 10) {
		return true;
	}
	int nd = numDigitos(n);
	return (n % nd == 0 && esPolidivisible(n / 10));
}

int numDigitos(long long n) {
	int ret = 1;
	while (n > 10) {
		n /= 10;
		ret++;
	}
	return ret;
}