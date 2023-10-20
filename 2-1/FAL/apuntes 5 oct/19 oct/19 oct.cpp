using namespace std;
#include <iostream>


int main() {

	return 0;
}

int fib(int n) {
	if (n <= 1)
		return n;

	return fib(n - 1) + fib(n - 2);
}

int fact(int n) {
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}


//ordenacion de un vector de forma recursiva
//o(n log n)
//Merge Sort // quicksort
void ordenar(int v[], int a, int b) {
	if (a >= b)
		return;

	int m = (a + b) / 2;

	ordenar(v, a, a + m);
	ordenar(v, a + m, b);
	mezcla(v, a, m, b);
}


//merge
void mezcla(int v[], int a, int m, int b) {

}
