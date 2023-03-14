/*---------------------------------------------------------------------
**
**  Fichero:
**    pr4.c  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 4
**
**-------------------------------------------------------------------*/


#define N 5

//nuestros dos vectores de N componentes
int U[N] = {5, 2, -3, 7, 6};
int V[N] = {6, -1, 1, 0, 3};
//variable que almacenará el resultado: 1 si U es mayor, 0 si es V
char mayor_u;

/**
 * Función que guarda un valor en el puntero proporcionado
 */
void guardar(char valor, char * ubicación) {
	*ubicación = valor;
}

/**
 * Función simple que multiplica dos números iterativamente
 */
int mul(int a, int b) {
	int res = 0, sign = 0;
	if (a < 0) {
		sign = 1;
		a = -a;
	}
	while (a--) res += b;
	if (sign)
		return -res;
	else
		return res;
}

/**
 * Función simple que obtiene la raíz cuadrada iterativamente
 */
int i_sqrt(int a) {
	int root = 0;
	while (mul(root, root) < a) {
		root++;
	}
	return root;
}

/**
 * Calculamos distancia euclídea. Sumamos todos los cuadrados
 * y terminamos sacando la raíz cuadrada (entera)
 */
int eucl_dist(int w [], int size) {
	int acc = 0;
	for (int i = 0; i < size; i++) {
		acc += mul(w[i], w[i]);
	}
	return i_sqrt(acc);
}

/**
 * Punto de entrada al programa
 */
void main() {
	//calculamos la distancia euclídea al origen
	int d_u = eucl_dist(U, N);
	int d_v = eucl_dist(V, N);
	//vemos si U estaba más lejos
	char mayor = d_u > d_v;
	guardar(mayor, &mayor_u);

	while(1); //quedo en un bucle infinito
}
