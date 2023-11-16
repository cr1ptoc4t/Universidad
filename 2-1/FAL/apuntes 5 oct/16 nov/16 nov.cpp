using namespace std;
#include <iostream>


long long cuantosEntretenidos(long long n);
bool entretenido(int num);


int main() {
	
}


long long cuantosEntretenidos(long long n) {
	long long raiz = n / 10;
	int digito = n % 10;
	long long ret=cuantosEntretenidos(raiz);
	ret *= 9;
	ret++;

	if (entretenido(raiz))
	{
		ret += digito;
		if (digito > raiz % 10)
			--ret;
	}
}

bool entretenido(int num) {
	return false;
}



//