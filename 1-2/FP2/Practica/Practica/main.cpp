
#include <iostream>
#include <fstream>
#include "reglasJuego.h"
#include "listaPartidas.h"

using namespace std;

int main() {
    tTablero tablero;
    ifstream archivo;
    tListaPartidas lp;

    //iniciaListaPartidas(lp);
    //cargarListaPartidas(archivo, lp);
    //seleccionar nuvel
    //elige partida
    //juega();
    //si se ha terminado --> eliminar de lp
    //se guarda la lista de partidas en un fichero
    //destruyelistaPartidas();



   
    int a=0, b=0, numPasos = 1;

    archivo.open("tablero.txt");
    if (leerTablero(archivo, tablero)) {
        mostrarTablero(tablero);

        while (!(estaTerminado(tablero) || esPosQuit(a, b))) {
            //cout << "Donde quieres poner la bombilla " << numPasos << "? ";
            cout << "Pos: ";
            cin >> a >> b;

            if (esPosReset(a, b)) {
                numPasos = 1;
            }

            ejecutarPos(tablero, a, b);
            mostrarTablero(tablero);
            numPasos++;
        }

        if (esPosQuit(a, b)) {
            cout << "Gracias por jugar, nos vemos a la proxima" << endl;
        }
        else {
            cout << "Has completado el juego" << endl;
            mostrarTablero(tablero);
        }
    }
    else cout << "problema en la carga del tablero";
    return 0;
}
