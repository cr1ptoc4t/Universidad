using namespace std;
#include <iostream>
bool crecienteYDivertido(int v[], int n, int d);
bool quasiFib(int v[], int n, int k);
void ordenar(int v[], int a, int b);
int fact(int n);
int fib(int n);
void mezcla(int v[], int a, int m, int b);
long long int digitos(long long int n);

long long cuantosUnos(long long n, long long& total);

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

long long int digitos(long long int n)
{
	int dig = 0;
	while (n > 0) {
		
		n /= 10;
		dig++;
	}
	return dig;
}
