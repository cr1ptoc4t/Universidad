using namespace std;
#include <iostream>

int moda(int v[], int n);
int partition(int a[], int start, int end);
void quicksort(int a[], int start, int end);

int main() {
	int v[25000];
	int n;

	cin >> n;

	while(n!=0){
		//leer entrada vector
		for (int i = 0; i < n; i++)
			cin >> v[i];

		//ordenar vector
		quicksort(v, 0, n-1);

		cout << moda(v, n) << endl;
		cin >> n;
	}
	return 0;
}

//supone que está ordenado
int moda(int v[], int n) {

	if (n == 1)
		return v[0];

	int freq[25000][2];
	int j = -1;	

	for (int i = 0; i < n; i++) {

		if (i == 0 ||v[i]!=v[i-1]) {
			j++;
			freq[j][0] = v[i];	//EL 0 ES EL NUMERO
			freq[j][1] = 1;		//EL 1 ES LA FRECUENCIA
		}
		else {
			freq[j][1]++;
		}
	}
	//	j es el numero de numeros totales NO REPETIDOS
	j++;
	//busca el indice de la mayor frecuencia
	int mayor=0;
	for (int i = 0; i < j; i++) {
		if (freq[i][1] > freq[mayor][1])
			mayor = i;
	}

	return freq[mayor][0];
}



int partition(int a[], int start, int end)
{
	int pivot = a[end];

	int pIndex = start;

	for (int i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	swap(a[pIndex], a[end]);

	return pIndex;
}
void quicksort(int a[], int start, int end)
{
	if (start >= end) {
		return;
	}

	int pivot = partition(a, start, end);

	
	quicksort(a, start, pivot - 1);
	quicksort(a, pivot + 1, end);
}