using namespace std;
#include <iostream>
#include "medicos.h"
#include "citas.h"


void procesarPeticiones(tListaCitas& lc, tListaMedicos& lm);

int main() {
	tListaMedicos lm;
	tListaCitas lc;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	inicializarListaCitas(lc);
	inicializarListaMedicos(lm);

	if(cargaListaCitas(lc)&&cargaListaMedicos(lm)){
		cout << "LISTA CITAS:" << endl;
		muestraListaCitas(lc);

		cout <<endl<< "LISTA MEDICOS:" << endl;
		muestraListaMedicos(lm);
		
		procesarPeticiones(lc, lm);

		cout << "LISTA CITAS:" << endl;
		muestraListaCitas(lc);

		cout << endl << "LISTA MEDICOS:" << endl;
		muestraListaMedicos(lm);
		cout << endl;
		
	}
	liberarCitas(lc);
	liberarMedicos(lm);
	return 0;
}

void procesarPeticiones(tListaCitas& lc, tListaMedicos& lm)
{
	int codigo_medico, libres;
	tPtrMedico ptr_medico;
	float total = 0;
	int num_citas = getNumElems(lc);

	for (int i = 0; i < num_citas; i++)
	{
		codigo_medico = getCodigoMedico(lc, i);
		ptr_medico = buscar(lm, codigo_medico);
		if (ptr_medico != nullptr)
		{
			total += getTarifaMedico(ptr_medico);
			libres = getLibresMedico(ptr_medico);
			setLibresMedico(ptr_medico, libres - 1);
			if (libres - 1 == 0)
				eliminar(lm, ptr_medico);
		}
	}
	cout << "El importe total es :" << total << " euros" << endl << endl;
}
