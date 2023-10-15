#include <iostream>
#include <cmath>
#include <string>
using namespace std;


string resuelveCaso() {
	int d, n;
	int act, ant, desnivel=0;

	string basura;

	cin >> d >> n;
	
	int i = 1;
	cin >> ant;
	while (i < n && desnivel<= d) {
		cin >> act;

		if (act <= ant)
			desnivel = 0;
		else
			desnivel += act - ant;

		i++;
		ant = act;
	}
	string ret;

	if (desnivel>d) {
		ret=  "NO APTA" ;
		if(i!=n)
			getline(cin, basura);
	}
	else
		ret= "APTA";
	return ret;
}

bool casoDePrueba() {


		if (!cin)
			return false;
		else {
			cout << resuelveCaso() << '\n';

			return true;
		}

} // casoDePrueba

int main() {

	while (casoDePrueba());

	return 0;

} // main
