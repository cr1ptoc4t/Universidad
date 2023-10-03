#include <iostream>
using namespace std;

int main() {
	int num, act;
	int v [100000];
	cin >> num;
	while (num != 0) {
		int dia = 1;
		int suma = 0;
		int j = 0;
		for (int i = 0; i < num; i++)
			cin >> v[i];

		while (j < num-1 && (suma != 0||j==0)){
			j++;
			suma += v[j];
			dia++;
		}
		if (suma == 0)
			cout << dia << endl;
		else
			cout << 0 << endl;

		cin >> num;
	}
	return 0;
}