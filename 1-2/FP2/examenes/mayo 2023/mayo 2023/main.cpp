#include <iostream>           
#include <fstream>   
#include <string>
#include "biblioteca.h"
#include "prestamos.h"
#include <locale.h>
using namespace std;

bool cargarArchivo(tBiblioteca& biblioteca);
int	menu();
void ofrecerMenu();
void procesarOpcion(tBiblioteca& biblioteca, tPrestamos& prestamos, int opcion);
void procesarOpcion1(tBiblioteca& biblioteca, tPrestamos& prestamos);
void procesarOpcion2(tBiblioteca& biblioteca, tPrestamos& prestamos);

int main()
{
	tBiblioteca biblioteca;
	tPrestamos prestamos;
	ifstream archivo;
	int opcion;
	setlocale(LC_ALL, "");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (cargarArchivo(biblioteca)) {
		mostrarBiblioteca(biblioteca);
		crearListaPrestamos(prestamos);
		opcion = menu();
		while (opcion != 0)
		{
			procesarOpcion(biblioteca, prestamos, opcion);
			opcion = menu();
		}
		liberarPrestamos(prestamos);
		liberarBiblioteca(biblioteca);
	}
	else
		cout << "Archivo no cargado." << endl;
	return 0;

}

int menu()
{
	int opcion;
	do
	{
		ofrecerMenu();
		cin >> opcion;
	} while (opcion < 0 || opcion > 4);
	return opcion;
}

bool cargarArchivo(tBiblioteca& biblioteca)
{
	ifstream archivo;
	archivo.open("entrada.txt");
	bool abierto = archivo.is_open();
	if (abierto)
	{
		cargarBiblioteca(biblioteca, archivo);
		archivo.close();
	}
	return abierto;
}

void ofrecerMenu()
{
	cout << "1.Efectuar pr?stamo" << endl;
	cout << "2.Devolver pr?stamo" << endl;
	cout << "3.Mostrar biblioteca" << endl;
	cout << "4.Mostrar pr?stamos" << endl;
	cout << "0.Salir" << endl << endl;
}

void procesarOpcion(tBiblioteca& biblioteca, tPrestamos& prestamos, int opcion)
{
	if (opcion == 1)   //Pr?stamo
		procesarOpcion1(biblioteca, prestamos);
	else if (opcion == 2)  //Devolver pr?stamo
		procesarOpcion2(biblioteca, prestamos);
	else if (opcion == 3)
		mostrarBiblioteca(biblioteca);
	else
		mostrarPrestamos(prestamos);
}

void procesarOpcion1(tBiblioteca& biblioteca, tPrestamos& prestamos)
{
	int isbn, dni, num_existentes, num_prestados;
	tPtrLibro ptr_libro;
	tPrestamo prestamo;

	cout << "Introduce ISBN: ";
	cin >> isbn;
	ptr_libro = getLibro(biblioteca, isbn);
	if (ptr_libro != nullptr)
	{
		num_existentes = getNumExistentes(ptr_libro);
		num_prestados = getNumPrestados(ptr_libro);
		if (num_existentes > num_prestados)
		{
			cout << "Introduce DNI: ";
			cin >> dni;
			prestamo = crearPrestamo(dni, isbn);
			if (insertarOrdenadoPrestamo(prestamos, prestamo))
				setNumPrestados(ptr_libro, num_prestados + 1);
			else
				cout << "El usuario ya tiene un ejemplar en pr?stamo" << endl << endl;
		}
		else
			cout << "Todos los ejemplares est?n prestados" << endl << endl;
	}
	else
		cout << "El libro no existe en la biblioteca" << endl << endl;
}


void procesarOpcion2(tBiblioteca& biblioteca, tPrestamos& prestamos)
{
	int isbn, dni, num_prestados;
	tPtrLibro ptr_libro;
	tPrestamo prestamo;

	cout << "Introduce ISBN: ";
	cin >> isbn;
	cout << "Introduce DNI: ";
	cin >> dni;
	prestamo = crearPrestamo(dni, isbn);
	if (eliminarPrestamo(prestamos, prestamo))
	{
		ptr_libro = getLibro(biblioteca, isbn);
		num_prestados = getNumPrestados(ptr_libro);
		setNumPrestados(ptr_libro, num_prestados - 1);
	}
	else
		cout << "No se ha podido efectuar la devoluci?n" << endl << endl;
}
