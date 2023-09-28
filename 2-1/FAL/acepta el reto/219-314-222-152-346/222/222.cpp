using namespace std;
#include <iostream>
#include <math.h>

int potencia(int x, int y);

int main() {
	int n, x;
	long long int act;
	while (true) {
		cin >> x >> n;
		long long int out = 0;
		for (int i = 0; i <= n; i++) {
			act = pow(x, i) ;
			act = act%1000007;
			out += act;
		}

		cout << out%1000007  << endl;
	}
}

int potencia(int x, int y){

	return x;
}
