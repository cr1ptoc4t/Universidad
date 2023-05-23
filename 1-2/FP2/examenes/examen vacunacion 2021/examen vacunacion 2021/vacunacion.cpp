#include "vacunacion.h"
#include <iostream>
#include <fstream>
using namespace std;


int buscaDia(tListaVacunas& l, string nombreVacuna, string& nombreCentro);






void vacunar(ifstream& archivoIn, ofstream& archivoOut, tListaVacunas& l)
{
    // pon tu implementación aquí
}


void inicializarListaVacunas(tListaVacunas& l)
{
    // pon tu implementación aquí
}


void liberarListaVacunas(tListaVacunas& l) {
    // pon tu implementación aquí
}



void cargarVacunasCentros(ifstream& archivo, tListaVacunas& l) {
    // pon tu codigo aqui
}


void mostrar(tListaVacunas& l) {
    cout << "Lista de vacunas ordenadas" << endl;
    cout << "--------------------------" << endl;
    for (int i = 0; i < 31; i++) {
        cout << l[i]->nomVacuna << " ";
        for (int j = 0; j < l[i]->centros.contador; j++) {
            cout << l[i]->centros.lista[j].nomCentro << "(" << l[i]->centros.lista[j].nDosis << ") -";
        }
        cout << endl;
    }
}
