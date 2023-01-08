#include <iostream>
#include<string>
using namespace std;


// define aquí las CONSTANTES Y TIPOS PEDIDOS 




//
// prototipos de los subprogramas pedidos en el enunciado (salvo buscar)
//
bool cargarLiga(tLiga & liga);
bool cargarJornada(tJornada & jornada, int numEquipos);
void mostrarLiga(const tLiga & liga);
void actualizarLiga(const tJornada & jornada, tLiga & liga);
void primeroYultimo(const tLiga& liga, string& primero, string& ultimo);
/* incorpora aquí el prototipo de tu subprograma buscar*/



int main(){
	tLiga liga;
	tJornada jornada;
	string primero, ultimo;
	
	if ( /* sustituye este comentario por el código necesario */ )
		cout << "carga fallida" << endl;
	else {
		cout << "CLASIFICACION...\n";
		mostrarLiga(liga);
		actualizarLiga(jornada, liga);
		cout << "\nCLASIFICACION ACTUALIZADA...\n";
		mostrarLiga(liga);
		primeroYultimo(liga, primero, ultimo);
		cout << endl;
		cout << "Primer clasificado: " << primero << endl;
		cout << "Ultimo clasificado: " << ultimo << endl;
	}
	
	return 0;
}



bool cargarLiga(tLiga & liga){
	// incluye aquí tu código

}

bool cargarJornada(tJornada & jornada, int numEquipos){
	// incluye aquí tu código

}


void mostrarLiga(const tLiga & liga){ 
	// incluye aquí tu código

}


void actualizarLiga(const tJornada & jornada, tLiga & liga) { 
	// incluye aquí tu código

}


void primeroYultimo(const tLiga & liga, string & primero, string & ultimo){ 
	// incluye aquí tu código

}

