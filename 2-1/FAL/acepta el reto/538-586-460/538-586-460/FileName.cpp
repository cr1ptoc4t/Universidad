
#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;

//string process(string num);
//void p460();
//int p460v2();
void p586();
void solucionaCaso();

int main() {
	/*
	int edad, antiguedad;

	cin >> edad >> antiguedad;
	while (!edad==0&&antiguedad==0)) {
		if (edad>=antiguedad) {
			cout << "CUERDO" << endl;
		}
		else {
			cout << "SENIL" << endl;
		}

		cin >> edad >> antiguedad;
	}
	
	//*/


	/*
	int ncasos;
	cin >> ncasos;
	for (int i = 0; i < ncasos;i++) {
		int ncal;
		cin >> ncal;
		for (int j = 0; j < ncal; j++) {
			
		}
	}
	
	while (true){
		int num;
		cin >> num;
		int i=0;
		int num2=0;
		while (num>0) {

			num2 = num2 % 10 + num / 10;
			num = num / 10;
		}
		cout << num2 << endl;
	}
	*/

	//586
	/*
	int ncasos, ncals;
	int a;
	cin >> ncasos;
	for (int i = 0; i < ncasos;i++) {
		a = 0;
		cin >> ncals;
		//????
		for (int j = 0; j < ncals; j++) {
			//?????
		}
		//qsort???
		//a=...;
		cout << a << endl;
		

	}

	*/
	//raíz de 10
	p586();
	//p460v2();
}

/*
void p460() {
	string num;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		cout << process(num) << endl;
	}
}

int p460v2()
{
	char n[102];
	while (true) {
		if (cin >> n) {
			for (int i = 0; i < strlen(n); i++) {
				if (i == strlen(n) - 1)		cout << n[i] << endl;
				else	cout << n[i] << '0';
			}
		}
		else {
			return 0;
		}
	}
}

string process(string num) {
	int digitos = num.length();
	string final=num;
	int n = digitos;
	if(digitos>1){
		while (n>1) {
			final = num.insert(n-1, "0");
			n--;
		}
	}
	return final;
}
*/
void p586(){
	int ncasos;
	int a;
	cin >> ncasos;
	for (int i = 0; i < ncasos; i++) {
		solucionaCaso();
	}

}
void solucionaCaso() {
	int nanyos;
	cin >> nanyos;
	int anyos[60];
	int actual;
	for (int i = 0; i < nanyos; i++) {
		cin >> actual;
		
		anyos[i] = actual;
	}
	int temp;
	int faltan = 0;
	
	//sort
	bool sort = true;
	/*
	while (sort){
		
		for (int i = 0; i < nanyos-1; i++) {
			sort = false;
			if (anyos[i] > anyos[i + 1]) {
				temp = anyos[i + 1];
				anyos[i+1] = anyos[i];
				anyos[i] = temp;
				sort = true;
			}
		}
	}
	*/


	//selection sort
	for (int i = 0; i < nanyos - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < nanyos; j++) {
			if (anyos[j] < anyos[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			int temp = anyos[i];
			anyos[i] = anyos[minIndex];
			anyos[minIndex] = temp;
		}
	}

	for (int i = 0; i < nanyos-1; i++) {
		faltan += anyos[i+1]-anyos[i]-1;
	}
	cout << faltan << endl;
}