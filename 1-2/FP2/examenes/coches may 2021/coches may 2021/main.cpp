
using namespace std;
#include <iostream>
#include <fstream>

#include "taller.h"

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  // para comprobar las fugas de memoria

    // Crea la lista de coches
    ifstream archivo;
    archivo.open("coche.txt");
    if (archivo.is_open()) {
        tListaCoches lc;
        iniciarListaCoches(lc);
        cargarCoches(archivo, lc);
        mostrarListaCoches(lc);
        
        // Crea la lista de la seccion del motor
        tListaSeccion lmotor = crearListaSeccion(lc, "Motor");
        cout << "lista de coches que se van a arreglar del motor" << endl;
        mostrarListaSeccion(lmotor);
        // Crea la lista de la seccion del chasis
        tListaSeccion lchasis = crearListaSeccion(lc, "Chasis");
        cout << "lista de coches que se van a arreglar del chasis" << endl;
        mostrarListaSeccion(lchasis);
        // Se termina el trabajo en la seccion del chasis
        marcarTerminados(lchasis);
        mostrarListaCoches(lc);

        // Se pregunta si varios coches están ya finalizados
        cout << "sobre cuántos coches quieres preguntar si están terminados? ";
        int numPreguntas;
        cin >> numPreguntas;
        for (int i = 0; i < numPreguntas; ++i) {
            string matricula;
            cout << "Matricula ";
            cin >> matricula;
            if (finReparacion(lc, matricula))
                cout << "SI\n";
            else cout << "NO\n";
        }
        marcarTerminados(lmotor);
        
        //mostrarListaCoches(lc);
        liberaListaCoches(lc);
       
    }
    return 0;
}