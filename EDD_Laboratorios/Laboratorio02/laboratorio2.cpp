#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template<class T, int element> class Exp{
	public:
			T a[element];
	void put(){
			int x = 1;
			for (int j=0; j<element; j++){
				a[j] = x;
				x++
			}
	}
	
	void print(){
		for(int x = 6; x<element; x++)
			cout<< a[x] << " " << "\n";
		cout << "\n ...Fin! \n";
		
	}
	
};

// Utility function to display queue

void tool_cola(queue<string> objeto) {
	cout << "\n Tamaño de la cola: " << objeto.size() << "\n";
	
	while (!objeto.empty()){
		cout << objeto.front() << ", ";
		objeto.pop;
	}
	cout << endl;
}


int main(){
	
		//Templates
		
		// Se crea un objeto
		Exp<int,2> objeto;
		objeto.put();
		objeto.print();
		
		//Pilas
		
		// Se crea el stack
		stack<int> st;
		// Se añaden elementos al stack
		st.push(10);
		st.push(20);
		st.push(30);
		st.push(40);
		
		// Se liberan los dos mas nuevos
		st.pop();
		st.pop();
		
		while (!st.empty()) {
			cout << " " << st.top();
			st.pop();
		}
		
		cout << "\n ... fin \n";
		
		//Queue
		
		//Crear una queue de un string
		queue<string> animales;
		//Agregar elementos a la queue
		animales.push("Gato");
		animales.push("Hormiga");
		animales.push("Conejo");
		animales.push("Perro");
		
		cout << "\n Cola inicial: \n";
		tool_cola(animales);
		
		// Iteradores
		
		vector<int> v1, v2;
		
		for(int i = 1; i <= 10; i++){
			v1.push_back(i);
			v1.push_back(i+2);
		}
		
		//Inicializar el iterador
		//Que apunta al primer elemento del vector v1
		vector<int> :: iterator itr = v1.begin();
		//Copia elementos del vector v2 a el vector v1 en el comienzo
		copy (v2.begin(), v2.end(), inserter(v1, itr));
		// Imprimir los elementos del vector v1
		cout <<" Los elementos del vector v1 despues de copiar los elementos del vector v2 son :" << endl;
		for (itr = v1.begin(); itr! = v1.end(); ++itr){
			cout << " " << *itr;
		}
		
		cout <<"\n\n;
		
		return 0;
}