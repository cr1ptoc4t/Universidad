#include "medico.h"
#include <fstream>
bool leerMedicos(tListaMedicos& lista)
{
	bool cargado = true;
	ifstream entrada;
	tMedico aux;
	int codigo;

	entrada.open("medicos.txt");

	if (entrada.is_open())
	{
		entrada >> codigo;
		while (codigo != -1 && lista.cont < MAX_MEDICOS)
		{
			aux.nCol = codigo;
			entrada >> aux.nCitasLib >> aux.tarifa;
			lista.array_medicos[lista.cont] = new tMedico(aux);
			lista.cont++;
			entrada >> codigo;
		}
		entrada.close();
	}
	else
	{
		cout << "Error, no se pudo abrir el archivo 'Medicos.txt'" << endl;
		cargado = false;
	}
	return cargado;
}

void inicializarListaMedicos(tListaMedicos& listaMed) {
	listaMed.cont = 0;
}

void mostrarListaMedicos(const tListaMedicos lm) {
	cout << "    *****   LISTA DE MEDICOS    *****    " << endl<<endl;
	cout << "=========================================" << endl;
	for (int i = 0; i < lm.cont;i++) {
		cout << lm.array_medicos[i]->nCol << " " << lm.array_medicos[i]->nCitasLib << " " << lm.array_medicos[i]->tarifa << endl;
	}
	cout << "=========================================" << endl;

}

void liberarMemoriaM(tListaMedicos& lm) {
	for (int i = 0; i < lm.cont; i++)
		delete lm.array_medicos[i];

	lm.cont = 0;
}


int buscarMedico(tListaMedicos lm, int codigo) {
	//busqueda recursiva
	return buscarMedicoAux(lm, codigo, 0, lm.cont);

}

int buscarMedicoAux(const tListaMedicos lm, int codigo, int inicio, int fin) {
	int mitad = (inicio + fin) / 2;
	int pos = -1;
	if (inicio<=fin) {

		if (lm.array_medicos[mitad]->nCol == codigo)
			pos = mitad;
		else if (lm.array_medicos[mitad]->nCol > codigo)
			pos = buscarMedicoAux(lm, codigo, mitad + 1, fin);
		else
			pos = buscarMedicoAux(lm, codigo, inicio, mitad - 1);

	}
	return pos;
}

void eliminar(tListaMedicos & listaMedicos, tMedico* ptr_medico)
	{

		int pos = buscarMedico(listaMedicos, ptr_medico->nCol);
		delete ptr_medico;
		for (int i = pos + 1; i < listaMedicos.cont; i++)
			listaMedicos.array_medicos[i - 1] = listaMedicos.array_medicos[i];
		listaMedicos.cont--;
}
