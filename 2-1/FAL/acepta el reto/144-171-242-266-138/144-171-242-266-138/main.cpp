#include <iostream>
using namespace std;

int v[100000];

//138
void p138();


//266
void p266();
void cargacuadro(string& cuadro);


//242
void p242();
int erasmus(int vect[], int n);
bool resuelveCaso();


//171
void p171();
int abadias(int vect[], int n);


//114
void p114();
long long factorial(int n);



int main() {
	p266();
	//p171();
	//p114();

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
void p242()
{
	int num;
	cin >> num;
	while (num != 0) {
		for (int i = 0; i < num; i++)
			cin >> vector[i];

		resuelveCaso();

		cin >> num;
	}
}

int erasmus(int vect[], int n) {
	long long ret = 0;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ret += v[i] * v[j];

	return 0;
}


//242
bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int ret = erasmus(v, n);
}

void p171() {
	int vector[100000];

	int num;
	cin >> num;
	while (num != 0) {

		for (int i = 0; i < num; i++)
			cin >> vector[i];

		cout << abadias(vector, num)+1 << endl;
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
	*/
}


int abadias(int vect[], int n) {
	int ret = 0;

	for (int i = 0; i < n - 1; i++) {
		int maximo = vect[i + 1];
		for (int j = i + 2; j < n; j++)
			if (maximo < vect[j])
				maximo = vect[j];
		if (maximo < vect[i])
			ret++;
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
