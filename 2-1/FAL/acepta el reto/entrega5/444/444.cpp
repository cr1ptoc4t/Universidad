using namespace std;
#include <iostream>
int aguanta(int v[], int n, int k);
int main() {
	int n, k;
	int v[100000];
	cin >> n >> k;
	while (!(n==0 && k==0)) {

		for (int i = 0; i < n; i++){
			cin >> v[i];
		}

		//analisis del array
		cout<<aguanta(v, n,k)<<endl;



		cin >> n >> k;
	}

	return 0;
}

int aguanta(int v[], int n, int k)
{
	int kini = k;
	int contador=1,max=0;
	int j = 0;
	while (v[j] == 0)j++;
	if(j!=n && n>0){
		for (int i = j+1; i < n; i++) {
			if (v[i] == 1){
				contador++;
				k=kini;
			}
			else if (v[i] == 0 && k >0){
				contador++;
				k--;
			}
			else if (k == 0 && v[i] == 0 && contador > max){
				max = contador;
				contador = 0;
				k = kini;
			}

		}
		if (contador > max)
			max = contador;
	}
	else {
		max = 0;
	}
	return max;
}
