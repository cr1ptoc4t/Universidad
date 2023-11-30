
#include <iostream>
using namespace std;

int main()
{
    return 0;
}


// problema de la mochila
// coste logarítmico
// no influye el orden
// no fraccionado
// numeros enteros

void mochila(
    float peso[],
    float valor[],
    int n,
    float capacidad,

    //solucion parcial
    bool solParcial[],
    int k,


    //marcaje
    float pesoAc,
    float valorParcial,

    //mejor solucion
    bool solOptima[],
    float& valMax

    ) {

    if (k == n) {
        //si la solucion parcial es mejor que la optima
        if (valMax<valorParcial) {
            valMax = valorParcial;
            for (int i = 0; i < n; i++)
                solOptima[i] = solParcial[i];
        }
        return;
    }


    //caso 1: añadimos el producto k+1
    solParcial[k] = false;
    mochila(peso, valor, n, capacidad,
        solParcial, k + 1, pesoAc + peso[k],
        valorParcial + valor[k],
        solOptima, valMax);


    //caso 2: no añadimos el producto k+1
    solParcial[k] = false;
    mochila(peso, valor, n, capacidad,
        solParcial, k+1, pesoAc + peso[k], valorParcial,
        solOptima, valMax);
    /*
    * PODA:
    * si detectamos que con la solucion parcial no vamos a
    * poder encontrar una solucion mejor,
    * entonces dejamos de calcular por esa rama
    */



}
