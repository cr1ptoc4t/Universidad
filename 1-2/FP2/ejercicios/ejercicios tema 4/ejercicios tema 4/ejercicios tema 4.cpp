// ejercicios tema 4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
using namespace std;
#include <iostream>
#include <fstream>   
#include <string>

typedef struct {
    int num;
    char car;
} tRegistro;
const int N = 10;
typedef struct {
    tRegistro elementos[N];
    int cont;
} tLista;
typedef const tRegistro* tPtr;
typedef struct {
    tPtr punt[N];
    int cont;
} tListaPtr;

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();


bool cargarLista(tLista& lista, string nomFich);
void mostrarLista(const tLista& lista);
void crearListaPunteros(tLista& lista, tListaPtr& lista_punt);
void porNum(tListaPtr& lista_punt);
void porCar(tListaPtr& lista_punt);
void mostrarListaPunteros(const tListaPtr& lista_punt);



int main()
{
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    ejercicio4();


}


void ejercicio1() {
    int x = 5, y = 12, z;
    int* p1, * p2, * p3;
    p1 = &x;
    p2 = &y;
    z = *p1 * *p2; //5x12; 60
    p3 = &z;    
    (*p3)++; //61
    cout << *p1 << " " << *p2 << " " << *p3<<endl;//5, 12 , 61
}

void ejercicio2() {
    int dato = 5;
    int * p1, * p2;
    p1 = &dato;
    p2 = p1;
    cout << *p2<<endl;
}

void ejercicio3() {
    double d = 5.4, e = 1.2, f = 0.9;
    double * p1, * p2, * p3;
    p1 = &d;
    (*p1) = (*p1) + 3;
    p2 = &e;
    p3 = &f;
    (*p3) = (*p1) + (*p2);
    cout << *p1 << " " << *p2 << " " << *p3 << endl;
}

void ejercicio4() {
    tRegistro reg;
    tLista lista;
    tListaPtr lista_punt;
    if (cargarLista(lista, "datos.txt"))
    {
        mostrarLista(lista);
        system("pause");
        crearListaPunteros(lista, lista_punt);
        porNum(lista_punt);
        cout << "Lista ordenada por numero" << endl << endl;
        mostrarListaPunteros(lista_punt);
        system("pause");
        porCar(lista_punt);
        cout << "Lista ordenada por caracter" << endl << endl;
        mostrarListaPunteros(lista_punt);
    }
    else
        cout << "Fichero no abierto" << endl;
}

bool cargarLista(tLista& lista, string nomFich) {

    tRegistro registro;
    ifstream archivo;
   
    int cont = 0;
    archivo.open(nomFich);
    bool abierto = archivo.is_open();
    if (abierto)
    {
        archivo >> registro.num >> registro.car;
        while (!archivo.fail() && cont < N)
        {
            lista.elementos[cont] = registro;
            cont++;
            archivo >> registro.num >> registro.car;
        }
        lista.cont = cont;
        archivo.close();
    }
    return abierto;
}

void mostrarLista(const tLista& lista) {
    for (int i = 0; i < lista.cont; i++)
        cout << lista.elementos[i].num << " " << lista.elementos[i].car << endl;
}

void crearListaPunteros(tLista& lista, tListaPtr& lista_punt) {
    for (int i = 0; i < lista.cont; i++)
        lista_punt.punt[i] = &lista.elementos[i];
}

void porNum(tListaPtr& lista_punt) {

}

void porCar(tListaPtr& lista_punt) {
}

void mostrarListaPunteros(const tListaPtr& lista_punt) {
}
