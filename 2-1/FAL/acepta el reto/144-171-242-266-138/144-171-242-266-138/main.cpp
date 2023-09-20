/*
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


using namespace std;

int v[100000];

//138
void p138();


//266
void p266();
void cargacuadro(string& cuadro);


//242
void p242();
long long int erasmus(long long int vect[], long long int n);
bool resuelveCaso();


//171
void p171();
int abadias(int vect[], int n);


//114
void p114();
long long factorial(int n);



int main() {
	//p266();
	//p171();
	//p114();
	p242();

	return 0;
}


void p266()
{
	int base, altura;
	cin >> base >> altura;
	while(base>0&&altura>0){
		char a1[500][500];

		//cargar

		for (int i = 0; i < base; i++) {
			for (int j = 0; j < altura; j++) {
				cin >> a1[i][j];
			}
		}

		int ndaltonicos;
		cin >> ndaltonicos;
		

		//array colores a distinguir
		for (int i = 0; i < ndaltonicos; i++) {

		}


		cin >> base >> altura;
	}
}


//138
void cargacuadro(string& cuadro) {
	int base, altura;
	cin >> base >> altura;

	for (int i = 0; i < base; i++) {
		for (int j = 0; j < altura; j++) {
			//cin >> cuadro[i][j];
		}
	}
}


int vector[10000];
void p242() {


	long long int n;
	cin >> n;

	while (n != 0) {
		long long int vect[100000];

		for (long long int i = 0; i < n; i++)
			cin >> vect[i];

		long long int ret = erasmus(vect, n);
		cout << ret << '\n';
		
		cin >> n;
	}
	//while (resuelveCaso());
}

long long int erasmus(long long int vect[], long long int n) {
	long long int ret = 0, suma = 0;
	for (long long int i = 0; i < n - 1; ++i) {
		suma += v[i];
		ret += suma * v[i + 1];

	}

	return ret;
}

//int vect[100000];

//242
bool resuelveCaso() {
	

	long long int n;
	cin >> n;
	if (n == 0)
		return false;

	long long int vect[100000];
	 
	for (long long int i = 0; i < n; i++)
		cin >> vect[i];

	long long int ret = erasmus(vect, n);
	cout << ret << '\n';

	return true;

}

void p171() {
	int vector[100000];

	int num;
	cin >> num;
	while (num != 0) {

		for (int i = 0; i < num; i++)
			cin >> vector[i];


		//cout << abadias(vector, num) << endl;
		int ret = 0;
		int actual;
		int max = 0;
		for (int i = num-1; i >= 0; i--) {
			actual = vector[i];
			if (actual > max) {
				max = actual;
				ret++;
			}
		}
		cout << ret << endl;



		cin >> num;
	}
}


void p138() {
	/*
	int ncasos, n;
	cin >> ncasos;
	for(int i=0;i<ncasos;i++){
		cin >> n;
		int numCeros = 0;
		int divCincos = n / 5;
		while (divCincos > 0) {
			numCeros += divCincos;
			divCincos /= 5;
		}
		cout << numCeros << '\n';
	}
	
}


int abadias(int vect[100000], int n) {
	int ret = 0;

	/*for (int i = 0; i < n - 1; i++) {
		int maximo = vect[i + 1];
		for (int j = i + 2; j < n; j++)
			if (maximo < vect[j])
				maximo = vect[j];
		if (maximo < vect[i])
			ret++;
	}
	
	int actual;
	int max=0;
	for(int i=n;i>=0;i--){
		actual = vect[i];
		if (actual > max) {
			max = actual;
			ret++;
		}
	}

	return ret;
}




void p114() {
	int numCasos, num;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> num;
		if (num == 0)
			cout << "1" << endl;
		else if (num < 5)
			cout << factorial(num) % 10 << endl;
		else
			cout << "0" << endl;

	}
}

long long factorial(int n) {
	long long fact = 1;
	for (int i = 1; i <= n; i++)
		fact = fact * i;

	return fact;
}

*/

#include <iostream>
#include <string>
using namespace std;

long long int erasmus(long long int v[], int n);
void solucionaCaso(int n);

int main() {
	long long int n;
	cin >> n;
	
	while (n != 0) {
		solucionaCaso(n);
		cin >> n;
	}
	
	return 0;
}


long long int erasmus(long long int v[], int n) {

	long long int ret = 0, v2 = 0;
	for (int i = 0; i < n - 1; i++) {
		v2 += v[i];
		ret += v2 * v[i + 1];
	}

	return ret;
}

void solucionaCaso(int n) {
	long long int v[100000];

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout << erasmus(v, n) << endl;
}
