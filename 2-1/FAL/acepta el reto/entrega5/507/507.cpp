using namespace std;
#include <iostream>

int main() {
	int n, pmax;
    int act;
	int v[200000];
	cin >> n >> pmax;
	while(n!=0){
        for (int i = 0; i < n; i++) {
            cin >> act;

            //buscar indice
            int indice =0;
            while (v[indice]>0 && v[indice] <= act && indice < n) indice++;

            
            for(int j=i;j>indice;j--)
                v[j] = v[j-1];


            v[indice] = act;
        }

        /*
		int total = 0;
        bool desorden = true;
        //quickSort(v, 0, n);
        for (int j = 0; j < n - 1; j++)
            for(int i=0;i<n-1;i++)
                if (v[i + 1] < v[i]) {
                    int temp = v[i + 1];
                    v[i+1] = v[i];
                    v[i] = temp;
                    desorden = true;
                }
       

        bool si = true;
        int i = 0;
        int total = 0;
        while (i<n&&si) {
            int j = i+1;
            while (j < n&&si) {
                if (v[i] + v[j] > pmax) { 
                    si = false; 
                }
                else total++;
                j++;
            }
            i++;
        }
         */
        //bool si = true, si2=true;

        int i = 0;
        int total = 0;
        while (i < n && v[i]<pmax) {
            int j = i + 1;
            while (j < n && v[i]+v[j]<=pmax) {
                total++;
                j++;
            }
            i++;
        }

		cout << total << endl;
        for (int i = 0; i < n; i++)
            v[i] = -1;
        cin >> n >> pmax;

	}
}