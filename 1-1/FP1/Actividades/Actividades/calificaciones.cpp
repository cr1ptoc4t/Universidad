#include <iostream>
using namespace std;

typedef enum { noPresentado, suspenso, aprobado, notable, sobresaliente, matriculaDeHonor } tCalificacion;

tCalificacion notaACalificacion(double nota);
string notaAString(double nota);


int main() {
	

	


	double nota1 = -1, nota2 = -1;
	cout << "introduce la primera nota: ";
	cin >> nota1;
	while (!(nota1 >= 0 && nota1 <= 10)) {
		cout << "ERROR: DEBE PERTENECER AL INTERVALO [0,10], VUELVE A INTENTARLO:";
		cin >> nota1;
	}
	cout << "nota 1 = " << nota1 << endl;
	cout << endl;


	cout << "introduce la segunda nota: ";
	cin >> nota2;
	while (!(nota2 >= 0 && nota2 <= 10)) {
		cout << "ERROR: DEBE PERTENECER AL INTERVALO [0,10], VUELVE A INTENTARLO:";
		cin >> nota2;
	}
	cout << "nota 2 = " << nota2 << endl;
	cout << endl;


	cout << "nota 1: " << nota1 << ", calificación: " <<notaAString(nota1) << endl;
	cout << "nota 2: " << nota2 << ", calificación: " << notaAString(nota2) << endl;

}


tCalificacion notaACalificacion(double nota) {
	tCalificacion calif=tCalificacion(0);
	if (nota == 0) {
		calif = tCalificacion(0); //no presentado
	}
	else if (nota > 0 && nota < 5) {
		calif = tCalificacion(1); //suspenso
	}
	else if (nota >= 5 && nota < 7) {
		calif = tCalificacion(2); //aprobado
	}
	else if (nota >= 7 && nota < 8) {
		calif = tCalificacion(3); //notable
	}
	else if (nota >= 8 && nota < 9) {
		calif = tCalificacion(4);
	}
	else if (nota >= 9) {
		calif = tCalificacion(5);
	}
	return calif;
}

string notaAString(double nota) {
	string str = "no presentado";

	if (notaACalificacion(nota) == tCalificacion(1)) {
		str = "suspenso";
	}
	else if (notaACalificacion(nota) == tCalificacion(2)) {
		str = "aprobado";
	}
	else if (notaACalificacion(nota) == tCalificacion(3)) {
		str = "notable";
	}
	else if (notaACalificacion(nota) == tCalificacion(4)) {
		str = "sobresaliente";
	}
	else if (notaACalificacion(nota) == tCalificacion(5)) {
		str = "matricula";
	}

	return str;
}