#include <iostream>
using namespace std;

int main() {
	int num, act;
	int v [1000000];
	cin >> num;
	while (num != 0) {
		int suma = 0;
		int j = 0;
		for (int i = 0; i < num; i++)
			cin >> v[i];

		while (j < num && suma != 0){
			j++;
			suma += v[j];
		}
		cin >> num;
		cout << suma << endl;
	}
	return 0;
}