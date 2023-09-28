using namespace std;
#include <iostream>

int main() {
	int ncasos, ndecimos, npares=0, num;
	cin >> ncasos;
	
	for (int i = 0; i < ncasos; i++) {
		cin >> ndecimos;
		npares = 0;
		for (int j = 0; j < ndecimos; j++) {
			cin >> num;
			if (num % 2 == 0)
				npares++;
		}
		cout << npares << endl;
	}

}