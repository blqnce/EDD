
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Funcion para encontrar el vertice con el valor minimo

int minKey(vector<int> &key, vector<bool> &mstSet) {
	int min = INT_MAX, min_index;
	for (int v = 0; v < mstSet.size(); v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

//Funcion para imprimir el Arbol de Expansion Minima encontrado

void printMST(vector<int> &parent, vector<vector<int>> &graph) {
	cout << "Arista \tPeso\n";
	for (int i = 1; i < graph.size(); i++)
		cout << parent[i] << " - " << i << " \t"
	<< graph[parent[i]][i] << " \n";
}

//Funcion para implementar el algoritmo de Prim y encontrar su MST (Arbol de EXpansion Minima)

void primMST(vector<vector<int>> &graph) {
	int V = graph.size();
	vector<int> parent(V);
	vector<int> key(V);
	vector<bool> mstSet(V);
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	
	printMST(parent, graph);
	
}

int main() {

	//Grafo a utilizar implementado mediante una matriz de adyacencia.
	
  	vector<vector<int>> graph = { 	{ 0, 2, 0, 6, 0 },
                        		{ 2, 0, 3, 8, 5 },
                        		{ 0, 3, 0, 0, 7 },
                        		{ 6, 8, 0, 0, 9 },
                        		{ 0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;
}
