using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>

const int MAX_HOSPITALES = 10;
const int MAX_NINNOS = 50;

struct tCita {
	string CIPA;
	string nombre;
};

struct tListaCitas {
	int cont;
	tCita lista[MAX_NINNOS];
};

struct tHospital{
	string nombre;
	char turno;
	tListaCitas listaCitas;
};

struct tListaHospitales {
	int cont;
	tHospital listaHospi[MAX_HOSPITALES];
};

void estadoSistema(tListaHospitales listaHosp);
void cargar(tListaHospitales& lh);
bool buscarCIPA(const tListaHospitales lista, string CIPA);
int buscarHospital(tListaHospitales lista, string nombre);
void insertarListaCitas(tListaCitas lista, tCita cita);
int localizarHospitalMasLibre(tListaHospitales lista);
void pedirCita(tListaHospitales& listaHosp);
int menu();


int main() {
	tListaHospitales lh;
	int opcion;

	setlocale(LC_ALL, "spanish");

	cargar(lh);
	opcion = menu();
	while (opcion != 0) {
		switch (opcion) {
		case 1:
			pedirCita(lh);
			break;
		case 2:
			estadoSistema(lh);
			break;
			/*case 3:
				cout << "Introduzca el turno (M, T, I): ";
				cin >> turno;
				turno = toupper(turno);
				disponibles(lh, turno);
				break;*/
		}
		opcion = menu();
	}
	return 0;
}

void cargar(tListaHospitales& lh) {
	 ifstream fh;

    fh.open("hospitales.txt");
    if (fh.is_open()) {
        fh >> lh.cont;
        for (int i = 0; i < lh.cont; i++) {
            fh >> lh.listaHospi[i].nombre >> lh.listaHospi[i].turno;
            lh.listaHospi[i].listaCitas.cont = 0;
        }
        fh.close();
    }
    else lh.cont = 0;
}

bool buscarCIPA(const tListaHospitales lista, string CIPA) {
	bool existe = false;
	for (int i = 0; i < MAX_HOSPITALES;i++) {
		for (int j=0;j<MAX_NINNOS;j++)
			if (lista.listaHospi[i].listaCitas.lista[j].CIPA==CIPA) existe = true;
	}
	return existe;
}

int buscarHospital(tListaHospitales lista, string nombre) {
	int pos = -1;

	for (int i = 0; i < MAX_HOSPITALES; i++) {
		if (lista.listaHospi[i].nombre == nombre) pos = i;
	}
	return pos;
}

void insertarListaCitas(tListaCitas lista, tCita cita) {
	lista.lista[lista.cont] = cita;
}

int localizarHospitalMasLibre(tListaHospitales lista) {
	int indiceMayorNum = 0;
	for (int i = 0; i < lista.cont;i++) {
		if (lista.listaHospi[i].listaCitas.cont < lista.listaHospi[indiceMayorNum].listaCitas.cont) indiceMayorNum = i;
	}
	return indiceMayorNum;
}

void pedirCita(tListaHospitales& listaHosp) {
	string cipa, nombre, hospital;
	int hospitalAsignado;
	
	cout << "introduce el nombre del ni�o: ";
	cin >> nombre;
	cout << "introduce el cipa ";
	cin >> cipa;
	
	if(!buscarCIPA(listaHosp, cipa)){
		cout << "en que hospital?";
		cin >> hospital;
		if (buscarHospital(listaHosp, hospital)!=-1 && listaHosp.listaHospi[buscarHospital(listaHosp, hospital)].listaCitas.cont<MAX_NINNOS) {
			hospitalAsignado = buscarHospital(listaHosp, hospital);
		}
		else {
			hospitalAsignado=localizarHospitalMasLibre(listaHosp);
		}
		cout << "Hospital asignado: " << listaHosp.listaHospi[hospitalAsignado].nombre;
		cout << "no de puesto: " << listaHosp.listaHospi[hospitalAsignado].listaCitas.cont;
		cout << "turno" << listaHosp.listaHospi[hospitalAsignado].turno;

	} else { cout << "ya existe una cita asignada a este CIPA"; }
}


void estadoSistema(tListaHospitales listaHosp) {
	for (int i = 0; i < MAX_HOSPITALES;i++) {
		cout<< listaHosp.listaHospi[i].nombre<< " " << listaHosp.listaHospi[i].turno<<endl;
		for (int j = 0; j < MAX_NINNOS; j++) {
			cout << " " << listaHosp.listaHospi[i].listaCitas.lista[j].CIPA << " " << listaHosp.listaHospi[i].listaCitas.lista[j].nombre;
		}
		cout << endl;
	}
}

int menu() {
	int opcion;

	cout << "\n1. Pedir cita - ";
	cout << "2. Estado del sistema - ";
	//cout << "3. Hospitales con citas libres - ";
	cout << "0. Salir\n";
	do {
		cout << "Opcion (entre 0 y 2): ";
		cin >> opcion;
	} while (opcion < 0 || opcion > 2);
	cout << endl;


	return opcion;
}