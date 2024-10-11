/*
N� GRUPO: H17

NOMBRE Y APELLIDOS DE LOS MIEMBROS DEL GRUPO:
CATALINA FULLANA MORA
PETER HANNS VALDIVIESO BORJAS


SI ALGUNO DE LOS MIEMBROS NO HA PARTICIPADO,
INDICAR AQU� EL MOTIVO:
No sé, le envié un mail y no contestó

IMPORTANTE: Si no se a�adem estos datos, el ejercicio no
se corregir� (puntuar� 0)

*/

#include <iostream>

using namespace std;

/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada de la especificaci�n y el dise�o sistem�tico
del mismo.
*/


/*
   vcs: vector de valores cal�ricos.
   vns: vector de valores nutricionales.
   n: N�mero de chuches.
   u: Umbral cal�rico
*/
/*
PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  0<n<tam(vcs) && 0<n<tam(vns) && tam(vcs) = tam(vns) &&
  && PARA_TODO i: 0<=i<n : 0<vcs[i]<=u 
*/
int mejor_cajita(int vcs[], int vns[], int n, int u);
/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  max i : 0 <= ini <= i < fin : (suma j: 0 <= ini <= j< fin : vcs[j]) < u & (suma k: 0 <= ini <= k< fin : vns[j])
*/

/*7
DISE�O DEL ALGORITMO:

Paso 1. Variables
	ini y fin-> marcan el inicio y final de la ventana corredera
	suma_c y suma_n -> marcan sumas caloricas y sumas nutricionales
	max_n -> el valor mas grande que ha tenido suma_n cuando se cumple que la suma calorica es menor que el umbral

Paso 2. Invariante
	suma_c=(SUMA todo i: 0<=ini<=i<=fin : vcs[i])
	suma_n=(SUMA todo i: 0<=ini<=i<=fin : vcn[i])
	max_n=max(max_n, suma_n)
	ini<=fin<=n
Paso 3. Inicializaci�n
	ini=0, fin=ini+1
	max_n= vns[0], suma_c = vcs[0] y suma_n = vns[0] --> así nos ahorramos una iteración. el enunciado dice que minimo habrá un elemento

Paso 4. Condici�n del bucle, y c�digo tras el bucle.
	fin<n para recorrer todo el array hasta n
Paso 5. Cuerpo del bucle
	
Paso 6. Justificaci�n de que el algoritmo siempre termina.
fin n siempre termina llegando al limite del bucle (n) puesto que solo se incrementa y n no se modifica.
Paso 7. Complejidad:
	O(n)

*/
int mejor_cajita(int vcs[], int vns[], int n, int u) {
	// A IMPLEMENTAR: Devolver el mayor valor nutricionales
	// que puede conseguirse sin superar el umbral cal�rico.[
	// Recuerda: vcs[n]: vector de valores cal�ricos,
	//           vns[n]: vector de valores nutricionales,
	//           u: umbral cal�rico
	//           Debe devolverse el m�ximo valor nutricional
	//           que puede conseguirse.

	int ini = 0;
	int fin = 1;

	int suma_c = vcs[0], suma_n = vns[0];
	int max_n = vns[0];

	while(fin<n){
		if (suma_c > u) {
			suma_c -= vcs[ini];
			suma_n -= vns[ini];
			ini++;
		}
		else {
			suma_c += vcs[fin];
			suma_n += vns[fin];
			fin++;
		}

		if (!(suma_c > u))		
			max_n = max(max_n, suma_n);

		//fin++;
	}
	 

	return max_n;
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

const static int MAX_CHUCHES = 1000000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		static int calorias[MAX_CHUCHES];
		static int nutricionales[MAX_CHUCHES];
		for (int i = 0; i < n; i++) {
			cin >> calorias[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> nutricionales[i];
		}
		int umbral;
		cin >> umbral;
		cout << mejor_cajita(calorias, nutricionales, n, umbral) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}