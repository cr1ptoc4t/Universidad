// NO MODIFIQUES NADA DE LO QUE APARECE EN ESTE FICHERO

#include <iostream>
#include <string>
using namespace std;
#include "yoMeVacuno.h"


void registraCentro(YoMeVacuno& vacunacion) {
	tIdCentro id;
	tDireccion direccion;
	cin >> id >> direccion;
	try {
		vacunacion.registra_centro(id, direccion);
		cout << "REGISTRO_CENTRO_OK" << endl;
	}
	catch (ECentroDuplicado) {
		cout << "ID_CENTRO_DUPLICADO" << endl;
	}
}


void registraCiudadano(YoMeVacuno& vacunacion) {
	tIdCiudadano id;
	tAnio anio;
	cin >> id >> anio;
	try {
		vacunacion.registra_ciudadano(id, anio);
		cout << "REGISTRO_CIUDADANO_OK" << endl;
	}
	catch (ECiudadanoDuplicado) {
		cout << "ID_CIUDADANO_DUPLICADO" << endl;
	}
}


void registraAnioVacunas(YoMeVacuno& vacunacion) {
	tNumVacunas nv;
	tAnio anio;
	cin >> anio >> nv;
	vacunacion.fija_Anio_NumVacunas(anio, nv);
	cout << "FIJADOS_ANIO_NUMVACUNAS" << endl;
}


void pideCita(YoMeVacuno& vacunacion) {
	tIdCiudadano id;
	cin >> id;
	try {
		vacunacion.pide_cita(id);
		cout << "REGISTRO_CITA_OK" << endl;
	}
	catch (ECiudadanoInexistente) {
		cout << "ERROR_REGISTRO_CITA" << endl;
	}
	catch (EAnioErroneo) {
		cout << "ERROR_REGISTRO_CITA" << endl;
	}
	catch (EExisteCita) {
		cout << "ERROR_REGISTRO_CITA" << endl;
	}
}


void enEspera(YoMeVacuno& vacunacion) {
	if (vacunacion.en_espera())
		cout << "HAY_PETICIONES" << endl;
	else
		cout << "NO_HAY_PETICIONES" << endl;
}


void mostrarLista(const Lista<Asignacion>& l) {
	Lista<Asignacion>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem().dameCiudadano() << " - " << it.elem().dameCentro()
			<< " - " << it.elem().dameDireccion() << " // ";
		it.next();
	}
}

void atiendeSolicitudes(YoMeVacuno& vacunacion) {
	try {
		cout << "ASIGNACIONES: ";
		mostrarLista(vacunacion.atiende_solicitudes());
		cout << endl;
	}
	catch (EErrorDeAtencion) {
		cout << "NO_HAY_CENTROS_ACTIVOS" << endl;
	}

}

void administraVacuna(YoMeVacuno& vacunacion) {
	tIdCentro id;
	cin >> id;
	try {
		if (vacunacion.administra_vacuna(id))
			cout << "ADMINISTRADA" << endl;
		else
			cout << "NO_ADMINISTRADA" << endl;
	}
	catch (ECentroInexistente) {
		cout << "CENTRO_INEXISTENTE" << endl;
	}
}


int main() {
	tAnio anio;
	tNumVacunas n;
	cin >> anio;
	cin >> n;
	YoMeVacuno vacunacion(anio, n);
	string comando;

	while (cin >> comando) {
		if (comando == "registraCentro") registraCentro(vacunacion);
		else if (comando == "registraCiudadano") registraCiudadano(vacunacion);
		else if (comando == "anioYvacunas") registraAnioVacunas(vacunacion);
		else if (comando == "pideCita") pideCita(vacunacion);
		else if (comando == "enEspera") enEspera(vacunacion);
		else if (comando == "atiendeSolicitudes") atiendeSolicitudes(vacunacion);
		else if (comando == "administra") administraVacuna(vacunacion);
	}
	return 0;
}


