#include <iostream>
#include <fstream>
using namespace std;
#include "vacunacion.h"
#include "checkML.h"




int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  // para comprobar las fugas de memoria
    ifstream archivo;
    archivo.open("vacunasCentros.txt");
    if (archivo.is_open()) {

        // carga lista de vacunas

        // muestra lista de vacunas

        archivo.close();
        archivo.open("preferencias.txt");
        if (archivo.is_open()) {
            // llama a vacunar y haz las operaciones
            // correspondientes con los ficheros que te hagan falta
        }
        else cout << "ERROR al abrir el fichero de preferencias " << endl;
        // libera memoria si es necesario
    }
    else cout << "ERROR al abrir el fichero de vacunaciones";

    return 0;
}


