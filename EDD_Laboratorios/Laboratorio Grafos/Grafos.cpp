/*
Laboratorio en clase (Recorridos de euler y hamilton)
Desarrollado por:
Angel Eduardo Morales Abril
Esteban Alfonso Navas Suarez
*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include<stdio.h>
using namespace std;

int n;

/*
  Pruebas del sistema

  Grafo #1:
    Vertices: 4
    Edges: 4
    Conexiones: (0,1), (1,2), (2,3), (3,0)
      Resultados: 
        Euler:
          Circuito de euler encontrado:
            0-1 1-2 2-3 3-0
        Hamilton:
          Ciclo de hamilton encontrado:
          0-1 3-0
          1-2 3-0
          2-3 3-0
    Conclusiones:
    Se encuentran resultados satisfactorios mediante una verificacion a mano de los recorridos del grafo, estos 
    son correctos debido a que cada vertice cuenta con un numero de conexiones par.
  Grafo #2:
  Vertices: 5
  Edges: 4
  Conexiones: (0,1), (1,2), (2,3), (2,4)
    Resultados: 
      Euler:
        El grafo no contiene camino o circuito de euler
      Hamilton:
        El grafo no contiene camino o ruta de hamilton
  Conclusiones:
    Se encuentran resultados correctos de acuerdo con una verificacion en papel dentro del grafo, teniendo
    en cuenta que el grafo tiene un vertice con un numero de aristas impar, en esto caso ese seria el vertice 
    numero 2.
*/

// Declaracion datos y metodos utilizados para la clase Euler utilizados para Identificar y Imprimir Grafos tipo Euler

class Euler {
  int V;
  list<int> *adj;   
public:
  Euler(int V)  { this->V = V;  adj = new list<int>[V]; }
  ~Euler()      { delete [] adj;  }
  void addEdge(int u, int v) {  adj[u].push_back(v); adj[v].push_back(u); }
  void rmvEdge(int u, int v);
  void printEulerTour();
  void printEulerUtil(int s);
  int DFSCount(int v, bool visited[]);
  bool isValidNextEdge(int u, int v);
  int iseuler(int[]);
};

// Funcion auxiliar para registrar el ultimo vertice de el camino o circuito Euler para permitir la impresion de el camino encontrado

void Euler::printEulerTour() {
  int u = 0;

  for (int i = 0; i < V; i++) {
    if (adj[i].size() & 1) {
      u = i; break;  
    }
  }

  printEulerUtil(u);

  cout << endl;
}
 
 // Funcion recursiva para imprimir circuitos de Euler
 
void Euler::printEulerUtil(int u) {
  list<int>::iterator i;

  for (i = adj[u].begin(); i != adj[u].end(); ++i) {
      int v = *i;

      if (v != -1 && isValidNextEdge(u, v)) {
          cout << u << "-" << v << " ";
          rmvEdge(u, v);
          printEulerUtil(v); 
      }
  }
}

// Funcion para identificar el siguiente eje no visitado 

bool Euler::isValidNextEdge(int u, int v) {
  int count = 0;  	
  list<int>::iterator i;

  for (i = adj[u].begin(); i != adj[u].end(); ++i) {
    if (*i != -1) {
      count++;
    }
  }

  if (count == 1) {
    return true;
  }

  bool visited[V];
  memset(visited, false, V);
  int count1 = DFSCount(u, visited);
  
  rmvEdge(u, v);
  memset(visited, false, V);
  int count2 = DFSCount(u, visited);
 
  addEdge(u, v);
 
  return (count1 > count2)? false: true;
}

// Funcion para remover ejes ya visitados de el recorrido
 
void Euler::rmvEdge(int u, int v) {
  list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
  *iv = -1;
 
  list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
  *iu = -1;
}
 
// Funcion para conocer el camino mas largo de el grafo
 
int Euler::DFSCount(int v, bool visited[]) {
  visited[v] = true;
  int count = 1;
 
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (*i != -1 && !visited[*i]){
      count += DFSCount(*i, visited);
    }
  }
 
  return count;
}

// Funcion para identificar si el grafo cuenta con un camino o circuito de Euler mediante el numero de aristas de los ejes

int Euler::iseuler(int a[]) {
	int count = 0;

	for(int i=0;i<n;i++) {
		if(a[i] % 2 != 0) {
			count++;
    }
	}

	if(count == 0) {
		cout<<"Euler's circuit exists:\n";
		return 1;
	} else if(count == 2) {
		cout<<"Euler's path exists:\n";
		return 1;
	} else {
		cout<<"No euler's path or circuit exist:'\n\n";
		return -1;
	}
}
 
//  Declaracion datos y metodos de la clase Hamiltonian para Identificar y imprimir Grafos Hamiltonianos
 
class Hamiltonian {
	int *path,v,x;
public:
	Hamiltonian(int n){ v = 0; x = 0; path = new int[n]; }
	bool isSafe(bool graph[][10], int pos);
	bool hamCycleUtil(bool graph[][10], int pos, int i);
	bool hamCycle(bool graph[][10]);
	void printSolution();
};

// Funcion para identificar si en el siguiente vertice se puede seguir el camino 

bool Hamiltonian::isSafe(bool graph[][10], int pos) {
  if (graph [ path[pos-1] ][ v ] == 0) {
    return false;
  }
 
  for (int i = 0; i < pos; i++) {
    if (path[i] == v) {
      return false;
    }
  }
 
  return true;
}
 
// Funcion para identificar si existe un Recorrido Hamiltoniano o es un Camino Hamiltoniano 
 
bool Hamiltonian::hamCycleUtil(bool graph[][10], int pos, int i)
{
  if (pos == n) {
      if ( graph[ path[pos-1] ][ path[0] ] == 1 ) {
        cout<<"Hamiltonian cycle exists\n";
        x = 1;
      }
      else {
        cout<<"Hamiltonian path exists\n";
      }
      return true;
  }

  for (v = 0; v < n; v++) {
    if(v == i) {
      continue;
    }
      if (isSafe(graph, pos)) {
          path[pos] = v;

          if (hamCycleUtil (graph, pos+1, i) == true) {
            return true;
          }

          path[pos] = -1;
      }
  }

  return false;
}
 
// Funcion para imprimir el recorrido encontrado si el grafo cuenta con un camino o circuito Hamiltoniano, si no imprime que no cuenta con uno
 
bool Hamiltonian::hamCycle(bool graph[][10]) {
    for (int i = 0; i < n; i++) {
      path[i] = -1;
    }

    for(int i=0;i < n; i++) {
        path[0] = i;
      if (hamCycleUtil(graph, 1,i) == true) {
        printSolution();
        return true;
      }
    }
    cout<<"\nNo Hamiltonian path or cycle exist";
    return false; 
}
 
// Funcion para imprimir el recorrido encontrado si el grafo cuenta con un camino o circuito Hamiltoniano, si no imprime que no cuenta con uno
 
void Hamiltonian::printSolution() {
  for (int i = 0; i < n - 1; i++) {

    cout << path[i] << "-" << path[i + 1] << " ";
        
    if(x == 1) {
      cout << path[n - 1] << "-" << path[0];
    }
    	
    cout<<"\n";
  }
}

int main() {
    // Numero de vertices
    cout << "\nEnter the number of vertices of graph: ";
    cin >> n;

    // Inicializar euler y hamilton
    Euler g1(n);
    Hamiltonian g2(n);

    // Inicializar matrix de adyacencia y arreglo de grados
    int a[n] = {0};
    bool graph1[10][10] = {0};

    // Numero de aristas
    cout << "\nEnter the total number of edges: ";
    int Edges;
    cin >> Edges;

    // Ejes de el grafo
    for (int i = 1; i <= Edges; i++) {
        cout << "\nEnter the edge (v1 v2): ";
        int v1, v2;
        cin >> v1 >> v2;

        // Actulizar matrix de adyacencia
        graph1[v1][v2] = 1;
        graph1[v2][v1] = 1;

        // Agregar euler a la grafica y actualizar el arreglo de grados
        g1.addEdge(v1, v2);
        a[v1]++;
        a[v2]++;
    }

    // Hamilton
    cout << "\nHamiltonian cycle/path check:\n";
    g2.hamCycle(graph1);

    // Euler
    cout << "\nEuler path/circuit check:\n";
    if (g1.iseuler(a) == 1) {
        g1.printEulerTour();
    }

    return 0;
}
