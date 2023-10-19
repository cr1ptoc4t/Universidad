using namespace std;
#include <iostream>
bool crecienteYDivertido(int v[], int n, int d);
bool quasiFib(int v[], int n, int k);
void ordenar(int v[], int a, int b);
int fact(int n);
int fib(int n);
void mezcla(int v[], int a, int m, int b);


int main() {

}

//	el vector entero sigue la secuencia de quasifib??

// { Pre: 2<=n<= longitud(v)
//		P.t. i:0 <=i<=n
// }
bool quasiFib(int v[], int n, int k) {
	int i = 2;
	int sumaAcu = v[0]+ v[1];

	if (v[0] != v[1] || sumaAcu > k)
		return false;

	while (i < n &&
		sumaAcu + v[i] <= k &&
		(v[i] == v[i-1] ||(v[i] ==v[i-1]+ v[i-2]))
		) {
		sumaAcu += v[i];
		i++;
	}
	return i == n;
}


//algoritmo d divertido

bool crecienteYDivertido(int v[], int n, int d) {
	int i = 0;

	while (i < n) i++;

	return i == n;
}

// 19/10
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
	
	ordenar(v,a, a+m);
	ordenar(v,a+m,b);
	mezcla(v,a,m,b);
}


//merge
void mezcla(int v[], int a, int m, int b) {

}