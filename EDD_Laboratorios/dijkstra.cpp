#include <climits>
#include <iostream>


using namespace std;

const int V = 9;

// Funcion para encontrar el vertice con el valor de distancia minimo, del conjunto de vertices aun no incluidos en el arbol del camino mas corto.

int minDistance(int dist[], bool sptSet[]){
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;	
			
	return min_index;
}

// Funcion para imprimir la matriz de distancias construida

void printSolution(int dist[]){
	cout << "Vertice \t Distancia desde la Fuente" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t " << dist [i] << endl;
		
}

/*
Función algoritmo de fuente única de Dijkstra: camino más corto de
Dijkstra para un grafo representado mediante representación de matriz de
adyacencia
*/

void dijkstra( int graph[V][V], int src){

	int dist[V]; //La matriz de salida. dist[i] tendrá la distancia más corta desde src a i
	bool sptSet[V]; // sptSet[i] será verdadero si el vértice i está incluido en el árbol del camino mas corto o la distancia mas corta de src a i esta finalizada.

	// Inicializa todas las distancias INFINITE y stpSet[] como false
	
	for (int i = 0; i < V; i++)
	dist[i] = INT_MAX, sptSet[i] = false;
	
	// La distancia del vértice de origen respecto a sí mismo es siempre 0
	
	dist[src] = 0;
	
	// Encontrar el camino mas corto para todos los vertices
	
	for (int count = 0; count < V - 1; count++) {
	
		// Elige el vértice de distancia mínima del conjunto de vértices aún no procesados. u essiempre igual a src en la primera iteración.
		
		int u = minDistance(dist, sptSet);
		
		// Marcar el vértice elegido como procesado
		
		sptSet[u] = true;
		
		// Actualiza el valor dist de los vértices adyacentes al vértice elegido.
		
		for (int v = 0; v < V; v++)
		
		// Actualizar dist[v] sólo si no está en sptSet, hay una arista de u a v, y el peso
		// total de la ruta de src a v a través de u es menor que el valor actual de
		
		if (!sptSet[v] && graph[u][v]
		&& dist[u] != INT_MAX
		&& dist[u] + graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}
	
	// Imprimir la matriz de distancias construida
	
	printSolution(dist);
}

int main(){
	/* Grafo */
	int graph[V][V] = {     { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
				{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
				{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
				{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
				{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
				{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
				{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
				{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
				{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	
	// Llamado a la funcion con el algoritmos dijkstra
	dijkstra(graph, 0);
	return 0;
}

