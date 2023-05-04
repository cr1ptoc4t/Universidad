//ALBA GALIANO CAMPILLO -- CATALINA FULLANA MORA
#include <iostream>
#include <fstream>
#include "reglasJuego.h"
#include "listaPartidas.h"

using namespace std;


int  elegirPartida(const tListaPartidas& lp);

int main() {
    ifstream archivoEntrada;
    ofstream archivoSalida;
    tListaPartidas lp;
    string archivo;
    int partida, nPasos=0;

    iniciaListaPartidas(lp);
    archivoEntrada.open("tableros.txt");
    cargarListaPartidas(archivoEntrada, lp);
    archivoEntrada.close();
    partida = elegirPartida(lp);

    if (!juega(*lp.datos[partida], nPasos))
        eliminarPartida(lp, *lp.datos[partida]);
    else
        actualizaBombillas(*lp.datos[partida]);
       

    cout << "Donde quieres guardar las partidas?" << endl;
    cin >> archivo;
    archivoSalida.open(archivo);
    guardarListaPartidas(archivoSalida, lp);
    destruyeListaPartidas(lp);
    archivoSalida.close();
    return 0;
}

int elegirPartida(const tListaPartidas& lp) {
    int nivel, i = 0;
    cout << "Que nivel quieres jugar? ";
    cin >> nivel;

    //if (nivel < getNivel(*dameElem(lp, i)))                 
        while (i < lp.nElem && getNivel(*dameElem(lp, i)) < nivel)
            i++;
    //else i = lp.nElem-1;
        if (i > getNivel(*dameElem(lp, i)))
            i = lp.nElem - 1;

    
    return i;
}