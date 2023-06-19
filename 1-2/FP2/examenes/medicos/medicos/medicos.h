using namespace std;
#include <iostream>
#include <fstream>

const int MAX_MEDICOS = 100;

struct tMedico {
	int colegiado;
	int citasLibres;
	int importe;
};


typedef tMedico* tPtrMedico;
struct tListaMedicos {
	tPtrMedico lista [MAX_MEDICOS];
	int cont;
};

void inicializarListaMedicos(tListaMedicos& lm);
bool cargaListaMedicos(tListaMedicos& lm);
void muestraListaMedicos(tListaMedicos& lm);
void liberarMedicos(tListaMedicos& lm);
int buscarPosMedico(const tListaMedicos& lm, int codMed);


int getTarifaMedico(tPtrMedico ptr_medico);
int getLibresMedico(tPtrMedico ptr_medico);
void setLibresMedico(tPtrMedico ptr_medico, int libres);
tPtrMedico buscar(const tListaMedicos& listaMedicos, int codigo);
void eliminar(tListaMedicos& listaMedicos, tPtrMedico ptr_medico);