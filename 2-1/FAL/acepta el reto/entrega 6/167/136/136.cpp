using namespace std;
#include <iostream>

bool procesaCaso();

int main() {

	while (procesaCaso())
		;

	return 0;
}

bool procesaCaso() {
	int fuerza, eslabones;

	cin >> fuerza >> eslabones;

	if(fuerza<=0)
		return false;	

	//código


	return true;
}