using namespace std;
#include <iostream>

void escribe_suma(int n);

int main() {

	return 0;
}

void escribe_suma(int n) {
	Pila <int> ds;
	while (n > 9) {
		desapila(n % 10);
		n /= 10;
	}

	cout << n;
	s = n;



}