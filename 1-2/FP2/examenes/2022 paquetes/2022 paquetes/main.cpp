using namespace std;
#include <iostream>
#include <fstream>
#include <string>

#include "paquetes.h"
#include "furgonetas.h"


void cargarPaquetes(tListaFurgonetas& listaFurgonetas, tListaPaquetes& listaPaquetes);
int main()
{
	tListaPaquetes lpaquetes;
	tListaFurgonetas lfurgos;
	if (cargarPaquetes(lpaquetes))
	{
		cout << " - LISTA DE PAQUETES AL COMIENZO -" << endl;
		mostrarPaquetes(lpaquetes);
		cout << "----------------------------------" << endl;
		if (cargarCodigos(lfurgos)) {
			cout << " - LISTA DE FURGONETAS AL COMIENZO -" << endl;
			mostrarFurgonetas(lfurgos);
			cout << "------------------------------------" << endl;
			cargarPaquetes(lfurgos, lpaquetes);
			cout << "- LISTA DE PAQUETES TRAS LA CARGA EN FURGONETAS - " << endl;
			mostrarPaquetes(lpaquetes);
			cout << "-------------------------------------------------" << endl;
			cout << "- LISTA DE FURGONETAS TRAS LA CARGA DE PAQUETES - " << endl;
			
			mostrarFurgonetas(lfurgos);
			cout << "-------------------------------------------------" << endl;
			
			recogerPaquete(lpaquetes);
			cout << "- LISTA DE PAQUETES TRAS LA RECOGIDA EN MANO -" << endl;
			mostrarPaquetes(lpaquetes);
			cout << "----------------------------------------------" << endl;
			//liberarFurgonetas(lfurgos);
		}
		//liberarPaquetes(lpaquetes);
	}
	//_CrtDumpMemoryLeaks(); // detección de fugas de memoria
	return 0;
}


void cargarPaquetes(tListaFurgonetas& listaFurgonetas, tListaPaquetes& listaPaquetes){
	string id_paquete;
	int codigo_postal;
	int num_paquetes = getCont(listaPaquetes);
	for (int i = 0; i < num_paquetes; i++)
	{
		codigo_postal = getCodigoPostalPaquete(listaPaquetes, i);
		int pos = buscarFurgoneta(listaFurgonetas, codigo_postal);
		if (pos != -1 && getNumCargados(listaFurgonetas, pos) < MAX_PAQUETES)
		{
			setCargado(listaPaquetes, i);
			id_paquete = getId(listaPaquetes, i);
			setIdPaquete(listaFurgonetas, pos, id_paquete);
			listaFurgonetas[pos].lc.cont++;
		}
	}
}