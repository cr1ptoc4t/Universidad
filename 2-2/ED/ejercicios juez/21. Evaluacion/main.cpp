#include "lista.h"
#include "DiccionarioHash.h"
#include "Diccionario.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
public:
	string alumno;
	int nota;
	Puntuacion(const string& nombre, int puntuacion) : alumno(nombre), nota(puntuacion) {}
};

// Construye una lista con las puntuaciones de aquellos alumnos cuya
// calificación final es distinta de 0. Dicha lista está ordenada
// alfabéticamente por nombre de alumno
// Parámetros:
//    bien: Lista de alumnos que han resuelto correctamente un ejercicio (si
//          un alumno ha resuelto correctamente varios ejercicios, aparecerá
//          varias veces en la lista)
//    mal: Lista de alumnos que han resuelto incorrectamente un ejercicio (si
//          un alumno ha resuelto correctamente varios ejercicios, aparecerá
//          varias veces en la lista)
//    listado: Listado de calificaciones, ordenado alfabéticamente por nombre
//          de alumno. Solo aparecen aquellos alumnos cuya calificación final 
//          es distinta de 0.

void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	Diccionario <string, int> dic;

	for (int i = 0; i < bien.longitud(); i++) {
		string alumno = bien.elem(i);
		if (dic.contiene(alumno)){
			int freq= dic.valorPara(alumno);
			dic.inserta(alumno, freq+1);
		}
		else
			dic.inserta(alumno, 1);
	}

	for (int i = 0; i < mal.longitud(); i++) {
		string alumno = mal.elem(i);
		if (dic.contiene(alumno)) {
			int freq = dic.valorPara(alumno);
			dic.inserta(alumno, freq - 1);
		}
		else
			dic.inserta(alumno, - 1);
	}

	Diccionario<string, int>::Iterator it = dic.begin();


	while (it != dic.end()) {
		if (it.valor() != 0) {
			Puntuacion punt(it.clave(), it.valor());
			listado.pon_final(punt);
		}

		it.next();
	}

}

void imprimePuntuaciones(Lista<Puntuacion>& listado) {
	Lista<Puntuacion>::ConstIterator i = listado.cbegin();
	Lista<Puntuacion>::ConstIterator e = listado.cend();
	while (i != e) {
		cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
		i.next();
	}
	cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
	string comienzo;
	while (cin >> comienzo) {
		Lista<string> bien;
		Lista<string> mal;
		Lista<Puntuacion> listado;
		leeResultados(bien, mal);
		califica(bien, mal, listado);
		imprimePuntuaciones(listado);
	}
	return 0;
}
