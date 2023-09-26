using namespace std;
#include <iostream>
#include <math.h>

//TIME LIMIT

int main() {
	int n, x;
	int act;
	for (int j = 0; j < 200;j++) {
		cin >> x >> n;
		int out = 0;
		for (int i = 0; i <= n; i++) {
			act = pow(x, i) ;
			out += act% 1000007;
		}
		cout << out  << endl;
	}
}