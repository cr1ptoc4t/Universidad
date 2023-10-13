#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void resuelveCaso(int d, int n);

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	while(true)
		resuelveCaso(d,n);
	return 0;
} 


void resuelveCaso(int d, int n) {
	string basura;
	int act, ant, desnivel=0;
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
	

	if (desnivel>d) {
		cout << "NO APTA" << endl;
		if(i!=n)
			getline(cin, basura);
	}
	else
		cout << "APTA" << endl;

}