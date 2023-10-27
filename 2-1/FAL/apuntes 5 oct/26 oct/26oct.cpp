using namespace std;
#include <iostream>
int mcd(int a, int b);
int resuelveCaso();

int main() {
	cout << resuelveCaso() << endl;
	return 0;
}


int resuelveCaso() {

	


	return 0;
}


// { Pre : a>=b>0
int mcd(int a, int b) {
	
	if (b == 0)
		return a;

	return mcd(b, a%b);
}
// { Post: ret>0

//RECURSION FINAL ->  cuando tras la llamada recursiva no hay que realizar ningún cómputo adicional