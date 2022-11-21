#include <iostream>
#include <string>
using namespace std;
const int LONGITUD_ARRAY = 30;

typedef int tArray[LONGITUD_ARRAY];

typedef enum{par, impar}tTipo;
tTipo numeroATipo(int i);
string tipoaString(int i);

int main() {
	cout << tTipo(1)<<endl;
	/*
	tArray array1;
	for (int i = 0; i < LONGITUD_ARRAY; i++) {
		array1[i] = i*i;

		cout <<array1[i]<<" es " << tipoaString(array1[i]) << endl;
	}
	return 0;
	*/
}

tTipo numeroATipo(int i) {
	return 	tTipo(!(i % 2 == 0));
}

string tipoaString(int i) {
	string str = "impar";
	if (numeroATipo(i) == 0) {
		str = "par";
	}

	return str;
}