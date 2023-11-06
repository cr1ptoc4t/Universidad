// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;
int v[4][4];



int main() {
   

    while (leer())
        ;

    return 0;

} // main


bool leer() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!(a==0&&b==0&&c==0&&d==0)) {

        calcula(a,b,c,d);

    }
    return false;
}

bool calcula(int pi, int di, int pd, int dd) {

    if (pi == 0 && di == 0 && pd == 0 && dd == 0)
        return true;
   
    if(pi==0)
        //calculamos submovil izq
    

    if(pd==0)
        //calculamos submovil der

    return false;
}