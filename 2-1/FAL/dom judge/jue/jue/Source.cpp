#include <iostream>
using namespace std;

const int LONG = 20000;
int misterio(int v[], int n);

int main() {
	int n, ncasos;
	int v[LONG];
	cin >> ncasos;
	for(int j=0; j<ncasos;j++){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i];

		cout << misterio(v, n) << endl;

	}


	return 0;
}

int misterio(int v[], int n) {
	int max1=-100000;
	int max2=-100000;

	for (int i = 0; i < n; i++){
		if (v[i] > max2){
			if (v[i] > max1) {
				max2 = max1;
				max1 = v[i];
			}
			else{
				max2 = v[i];
			}
		}
	}
	return max1 + max2;
}