#include <iostream>
using namespace std;
float base;
float b;

string array[3] {"a", "b", "c"};


float getBase(){
	cin>>base;
	return base;
}

int main (){
	cout<<array[2];
	b = getBase();
	cout<<b;
	return 0;
}