#include "citas.h"

void mostrarListaCitas(const tListaCitas lm)
{
	cout << "    *****   LISTA DE PETICIONES DE CITAS PENDIENTES DE PROCESAR   *****" << endl<<endl;

	for (int i = 0; i < lm.cont;  i++) {
		cout << lm.citas[i].codigoMedico << " - " << lm.citas[i].paciente << endl;
	}
	//importe total
}

void inicializarListaCitas(tListaCitas& listaCitas)
{
	listaCitas.cont = 0;
	listaCitas.capacidad = 20;
	listaCitas.citas = new tCita[listaCitas.capacidad];
}
void ampliar(tListaCitas& listaCitas)
{
	//crear auxiliar
	tCita* aux = new tCita[listaCitas.capacidad * 2];
	
	//pegar auxiliar en nueva con mas capacidad
	for (int i = 0; i < listaCitas.cont; i++)
		aux[i] = listaCitas.citas[i];

	//eliminar ambas
	delete[] listaCitas.citas;
	listaCitas.citas = aux;
	listaCitas.capacidad *= 2;
	aux = nullptr;
}
bool leerCitas(tListaCitas& lista) {
	bool cargado = true;
	ifstream entrada;
	int codigo;
	char espacio;

	entrada.open("Citas.txt");
	if (entrada.is_open())
	{
		entrada >> codigo;
		while (codigo != -1)
		{
			if (lista.cont == lista.capacidad)
				ampliar(lista);

			lista.citas[lista.cont].codigoMedico = codigo;
			entrada.get(espacio);
			getline(entrada, lista.citas[lista.cont].paciente);
			lista.cont++;
			entrada >> codigo;
		}
		entrada.close();
	}
	else {
		cout << "Error, no se pudo abrir el archivo 'Citas.txt'" << endl;
		cargado = false;
	}

	return cargado;
}

void liberarMemoriaC(tListaCitas& lc) {
	delete[] lc.citas;
	lc.citas = nullptr;
	lc.cont = 0;
}
