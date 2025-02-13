/***********************************************

  * Fecha : 29 enero 2025
  * Autor : Esteban Navas
  * Materia : Estructura de Datos
  * Topico: Programacion mdoular, C**, Complejidad Algoritmica
  * PONTIFICIA UNIVERSIDAD JAVERIANA

************************************************/
#include <iostream>
using namespace std;	

void initMatriz(int **a, int **b, int **c, int n);
void imprimirMatriz(int **m, int n);
void multiMatrices(int **a, int **b, int **c, int n);

int main(){
	int N = 5;
	int i, j, k;
	int **mA = new int *[N];
	int **mB = new int *[N];
	int **mC = new int *[N];

	//Se inicializa cada matriz
	
	initMatriz(mA, mB, mC, N);

	//Se imprimen las matrices
    
    imprimirMatriz(mA, N);
    imprimirMatriz(mB, N);
	
	multiMatrices(mA,mB,mC,N);
		
	//Se imprime la multiplicacion de las matrices
	
	imprimirMatriz(mC, N);

	return 0;
}

void initMatriz(int **a, int **b, int **c, int n){
	int i,j;
	for(i=0; i<n; i++){
		a[i] = new int [n];
		b[i] = new int [n];
		c[i] = new int [n];
	}
	
	//Se inicializa cada matriz
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			a[i][j] = 2*i;
			b[i][j] = i+j;
			c[i][j] = 0; 
		}
	}

}

void imprimirMatriz(int **m, int n){
    cout << "Matriz:" << endl;
    	for(int i=0; i<N; i++){
    		for(int j=0; j<N; j++){
    			cout << " " << m[i][j]; 
    		}
  		cout << "\n";
	}
}

multiMatrices(int **a, int **b, int **c, int n){
    for(int i=0; i<N; i++){ 				//Filas
		for(int j=0; j<N; j++){ 			//Columnas
			int suma = 0;
			for(int k=0; k<N; k++){				
				suma += mA[i][k] * mB[k][j];				
			}
			mC[i][j] = suma; 
		}
	
	}
}
