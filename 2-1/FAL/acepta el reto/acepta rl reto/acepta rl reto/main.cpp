using namespace std;
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

bool mismasLetras(string frase1, string frase2);
void leer(string& frase);
int main() {
    
    
    int ncasos;

    cin >> ncasos;

    string frase1,frase2;
    getchar();

    for (int i = 0; i < ncasos;i++) {
        leer(frase1);
        leer(frase2);
        if(mismasLetras(frase1,frase2)){
            cout<<"SI"<<endl;
        } else{
            cout<<"NO"<<endl;
        }

    }

    return 0;

}

bool mismasLetras(string frase1, string frase2)
{

    return frase1==frase2;
}

void leer(string& frase)
{
    char car;
    car = getchar();
    while (car != '\n') {
        if (car >= 'A' && car <= 'Z') {
            frase.push_back(car + 32);
        }
        else if (car >= 'a' && car <= 'z') {
            frase.push_back(car);
        }
        car = getchar();
    }
}


/*
    int ncasos, year;

    cin >> ncasos;

    while (ncasos> 0) {

        cin >> year;
        if (year>0) {
            year--;
        }
        cout << year << endl;

        ncasos--;
    }


    */
    /*
    int ncasos, ncarriles, altura;
    int min_abs=99999;
    cin >> ncasos;

    while (ncasos != 0) {
        //cout << endl;
        //cin >> npuentes;
        min_abs = 99999;

        for (int i = 0; i < ncasos;i++) {
            int max = 0;
            cin >> ncarriles;
            for (int j = 0; j < ncarriles; j++) {
                cin >> altura;
                //buscar el minimo
                if (altura > max) max = altura;
            }

            if (max < min_abs) {
                min_abs = max;
            }
        }
        cout << min_abs << endl;

        cin >> ncasos;
    }

    */