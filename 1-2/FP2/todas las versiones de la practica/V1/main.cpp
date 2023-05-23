//Catalina Fullana Mora  --  Alba Galiano Campillo
#include <iostream>
#include <fstream>
#include "reglasJuego.h"

using namespace std;

int main() {
    tTablero tablero;
    ifstream archivo;
    int a=0, b=0, numPasos = 1;

    archivo.open("tablero.txt");
    if (leerTablero(archivo, tablero)) {
        mostrarTablero(tablero);

        while (!(estaTerminado(tablero) || esPosQuit(a, b))) {
            cout << "Donde quieres poner la bombilla " << numPasos << "? ";
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
        }else {
            cout << "Has completado el juego" << endl;
            mostrarTablero(tablero);
        }
    }
    return 0;
}
