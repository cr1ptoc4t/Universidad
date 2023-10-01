using namespace std;
#include <iostream>

//int potencia(int b, int e);

int main() {
	int n, x;
	while (true) {
		cin >> x >> n;
		int out = 1,suma = 1;
		for (int i = 0; i < n; i++) {
			out = (out * x) % 1000007;
			suma = (suma + out) % 1000007;
		}
		cout << suma  << endl;
	}
	return 0;
}
/*
int potencia(int b, int e){
	int ret = 1;
	for (int i = 0; i < e; i++){
		ret = (ret*b)% 1000007;

	}
	return ret;
}
*/