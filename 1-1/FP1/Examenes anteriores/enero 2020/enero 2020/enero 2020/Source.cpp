#include <iostream>
#include <string>
#include <fstream>
using namespace std;



const int MAX_ESTANTERIAS = 15;
const int MAX_LIBROS = 100;

typedef enum { FISICA, MATEMATICAS, INFORMATICA }tArea;

typedef struct {
	tArea area;
	int pag;
	string titulo;
}tLibro;

typedef struct {
	tLibro listaLibros[MAX_LIBROS];
	int cont;
}tListaLibros;

typedef struct {
	tListaLibros ll;
	tArea area;
	int capacidad;
	int paginasDisp;
}tEstanteria;

typedef struct {
	tEstanteria listaEstanterias[MAX_ESTANTERIAS];
	int cont;
}tBiblioteca;


tArea strToArea(string str);
tLibro mayor(tListaLibros& listaLibros);
string areaToStr(tArea area);


bool cargaBibilioteca(tBiblioteca& biblioteca);
bool cargaLibros(tListaLibros& libros);

int	buscarEstanteria(const tBiblioteca& biblioteca, tLibro	libro);

void asignar(tBiblioteca& biblioteca, tListaLibros& listaLibros, tListaLibros& sinColocar);
void borrarLibro(tListaLibros& listaLibros, int	indice);
void mostrarLibros(const tListaLibros& listaLibros);
void mostrarBiblioteca(const tBiblioteca& biblioteca);


void inicializarEstanterias(tBiblioteca& biblioteca);

int main() {
	tBiblioteca biblioteca;
	tListaLibros listaLib, sinColocar;
	sinColocar.cont = 0;
	inicializarEstanterias(biblioteca);
	if (!cargaBibilioteca(biblioteca)) {
		cout << "error en carga de biblioteca" << endl;
	}
	else {
		if (!cargaLibros(listaLib)) {
			cout << "error en carga libros" << endl;
		}
		else {
			
			//mostrarBiblioteca(biblioteca);
			asignar(biblioteca, listaLib, sinColocar);
			mostrarBiblioteca(biblioteca);

			cout << "no se han podido colocar"<< endl;
			mostrarLibros(sinColocar);
		}
	}


	return 0;
}

bool cargaBibilioteca(tBiblioteca& biblioteca) {
	bool cargado = false;
	ifstream archivo;
	archivo.open("biblioteca.txt");
	string area;

	if (archivo.is_open()) {
		archivo >> biblioteca.cont;
		int i = 0;
		archivo >> area;
		while (area != "XXX") {
			biblioteca.listaEstanterias[i].area = strToArea (area);
			archivo >> biblioteca.listaEstanterias[i].capacidad;
			archivo >> area;
			i++;
		}
		archivo.close();
		cargado = true;
	}

	return cargado;
}

bool cargaLibros(tListaLibros& libros) {
	bool cargado = false;
	ifstream archivo;
	archivo.open("libros.txt");

	if (archivo.is_open()) {
		string area, str;
		libros.cont = 0;
		archivo >> area;
		while (area != "XXX") {
			libros.listaLibros[libros.cont].area = strToArea(area);
			archivo >> libros.listaLibros[libros.cont].pag;
			getline(archivo, libros.listaLibros[libros.cont].titulo);
			archivo >> area;
			libros.cont++;
		}
		archivo.close();
		cargado = true;
	}

	return cargado;
}

tArea strToArea(string str) {
	tArea area;

	if (str == "Fis") area = FISICA;
	else if (str == "Mat") area = MATEMATICAS;
	else if (str == "Inf") area = INFORMATICA;

	return area;
}

void borrarLibro(tListaLibros& listaLibros, int indice) {
	for (int i = indice; i<listaLibros.cont;i++) {
		listaLibros.listaLibros[i] = listaLibros.listaLibros[i+1];
	}
	listaLibros.cont--;
}

tLibro mayor(tListaLibros& listaLibros) {
	int max=0;
	for (int i = 0; i < listaLibros.cont; i++) {
		if (listaLibros.listaLibros[i].pag> listaLibros.listaLibros[max].pag) {
			max = i;
		}
	}
	tLibro libro = listaLibros.listaLibros[max];

	borrarLibro(listaLibros, max);

	return libro;
}

int buscarEstanteria(const tBiblioteca& biblioteca, tLibro libro) {
	bool encontrado = false;
	int i = 0;
	int indice = -1;
	int j = 0;
	while (!encontrado && i<biblioteca.cont) {
		if (biblioteca.listaEstanterias[i].area == libro.area && biblioteca.listaEstanterias[i].capacidad > libro.pag) {
			encontrado = true;
			
			indice = i;
		}
		i++;
	}

	if (i==biblioteca.cont) indice = -1;

	return indice;
}

void asignar(tBiblioteca& biblioteca, tListaLibros& listaLibros, tListaLibros& sinColocar) {
	int aux;
	for (int i = 0; i < listaLibros.cont;i++) {
		aux = buscarEstanteria (biblioteca, mayor(listaLibros));
		if(aux==-1){
			sinColocar.listaLibros[sinColocar.cont] = listaLibros.listaLibros[i];
			sinColocar.cont++;
		}
		else {
			biblioteca.listaEstanterias[aux].ll.cont++;
			biblioteca.listaEstanterias[aux].ll.listaLibros[biblioteca.listaEstanterias[aux].ll.cont] = listaLibros.listaLibros[i];
			biblioteca.listaEstanterias[aux].capacidad = biblioteca.listaEstanterias[aux].capacidad - listaLibros.listaLibros[i].pag;
			//biblioteca.listaEstanterias[i].capacidad = biblioteca.listaEstanterias[i].capacidad - libro.pag;
		}
	}
}

string areaToStr(tArea area) {
	string str;
	if (area == FISICA) str = "Fis";
	else if (area == MATEMATICAS) str = "Mat";
	else if (area == INFORMATICA) str = "Inf";

	return str;
}

void mostrarLibros(const tListaLibros& listaLibros) {
	cout << endl;
	for (int i = 0; i < listaLibros.cont;i++) {
		cout << i <<" " << areaToStr(listaLibros.listaLibros[i].area) << " " << listaLibros.listaLibros[i].pag << listaLibros.listaLibros[i].titulo << " " << endl;
	}
}

void mostrarBiblioteca(const tBiblioteca& biblioteca) {
	for (int i = 0; i < biblioteca.cont;i++) {
		cout << areaToStr(biblioteca.listaEstanterias[i].area) << " - " <<endl; //funcion suma pag
			for (int j = 0; j < biblioteca.listaEstanterias[i].ll.cont ;j++) {
				cout<< j+1 << biblioteca.listaEstanterias[i].ll.listaLibros[j].titulo<< " ("<< biblioteca.listaEstanterias[i].ll.listaLibros[j].pag<<" paginas)" << endl;
			}
	}
}

void inicializarEstanterias(tBiblioteca& biblioteca) {
	for (int i = 0; i < MAX_ESTANTERIAS;i++) {
		biblioteca.listaEstanterias[i].ll.cont = 0;
	}
}