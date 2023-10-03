
using namespace std;
#include <iostream>

int main() {
	int n;
	int val;
	cin >> n;
	while (n!=0) {
		int maxGlobal = 0;
		int maxNinos = 0;
		int ninos = 1;

		for (int i = 0; i < n; i++) {
			cin >> val;
			if (val > maxGlobal) maxGlobal = val;
			if (val <= maxNinos) {
				ninos = i + 1;
				maxNinos = maxGlobal;
			}
		}

		cout << ninos << '\n';

		cin >> n;
	}
	return 0;
}
