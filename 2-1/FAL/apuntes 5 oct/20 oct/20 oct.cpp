using namespace std;
#include <iostream>

int main() {

	return 0;
}



//cuantos numeros no tienen 1s en el intervalo (0,n)

//este mira solo para un caso si tiene oo no 1
long long cuantosUnos(long long n, long long& total) {

	if (n == 1) {
		return total + 1;
	}
	// despiezar hasta encontrar unos o terminar los digitos
	int ndigitos = digitos(n);
	int i = 0;
	int num = n;
	while (i < ndigitos && num % 10 != 1) {
		i++;
		num /= 2;
	}
	if (i != ndigitos) total++;

	return cuantosUnos(n - 1, total);
}



long long cuantosSinUnos(long long n) {


	long long ret = 0;
	long long aux = cuantosSinUnos(n / 10);
	ret += 9 * aux;

	if (sinUnos(n / 10)) {
		int d = n % 10;
		ret += d - (d > 1);
	}

	return ret;
}

bool sinUnos(long long n) {
	while (n > 0 && n % 10 != 1)
		n /= 10;
	return n == 0;
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
