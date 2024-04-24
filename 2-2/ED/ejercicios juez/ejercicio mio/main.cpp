using namespace std;
#include <iostream>
#include "lista.h"
#include "DiccionarioHash.h"
#include <iostream>
#include <string>

//string palabra = "el cielo se esta tinendo de negro y el negro combina con todo";
string palabra = "coloreamos de dias felices dias que no lo fueron tanto y nos resultan irrepetibles para lo bueno y para lo malo"; //y a mi me parece discutible porque he regresado al pasado he vuelto en una maquina del tiempo la verdad es que no fue para tanto";
//la historia es la misma de siempre o demasiados sentimientos o no los suficientes estoy a un paso de ser feliz pero estoy rodeao de paredes que me impiden moverme que me impiden dormir que me impiden moverme y no puedo ser feliz estoy llorando pero estoy contento las lagrimas me hacen mas joven y el cielo se esta tinendo de negro y el negro combina con todo con mi futuro, con tu pelo con tus besos, con el gobierno con los dioses, con los recuerdos de tu cara, de tu cara estoy llorando pero estoy contento";
//string palabra = "bbbbbbb";

void cargaLetras(Lista<string>& letras);

int main() {
	Lista<string> letras;
	cargaLetras(letras);

	string pal_a_medias="";
	for (int r = 0; r < 1000; r++) {
		cout << endl;
	}

	for (int i = 0; i < palabra.length(); i++) {
		int l = 0;

		while (letras.longitud() > l && (letras.elem(l)[0] != palabra[i])) {
			//cout << letras.elem(l) << palabra[i] <<endl<<endl;

			cout << pal_a_medias + letras.elem(l) << endl;
			l++;
			for (int r = 0; r < 10000000/2; r++);
		}
		

		pal_a_medias += letras.elem(l);
		cout << pal_a_medias << "\n";
	}

	for (int r = 0; r < 1000000000000000; r++);



	/*

	for(int l =0 ; l<letras.longitud(); l++){
		int i = 0;
		while (palabra.length() > l && letras.longitud() > i && letras.elem(i) != (palabra[l]+"")) {
			//cout <<letras.elem(i)<<"   " << letra[l]<<endl;
			cout << pal_a_medias + letras.elem(i)<<endl;
			i++;
		}
		if(palabra.length() > l && letras.longitud() > i)
			pal_a_medias += letras.elem(i);
		cout << pal_a_medias<<"\n";
	}*/

	return 0;
}

void cargaLetras(Lista<string>& letras)
{
	for (char letra = 'a'; letra <= 'z'; ++letra) {
		letras.pon_final(string(1, letra));
		//cout << letra;
	}
	letras.pon_final(" ");

}
