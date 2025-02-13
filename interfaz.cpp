/**********************************
Fecha: 11 de Febrero 2025
Autores: Santiago Hernandez, Juan Esteban, Esteban Navas
Materia: Estructuras de Datos
Tema: Primera entrega del proyecto
***********************************/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Funcion que convierte la entrada del usuario (string) en un vector de strings con los comandos separados
vector<string> userIn() {
    string in;  // Variable que almacena la entrada del usuario
    cout << "$ ";  // Se muestra el prompt de la linea de comandos
    getline(cin, in);  // Se captura la linea completa de entrada del usuario

    stringstream ss(in);  // Se usa stringstream para separar los elementos de la entrada
    vector<string> comando;  // Vector para almacenar los comandos separados

    // Separa la entrada en palabras y las almacena en el vector
    while (ss >> in) {
        comando.push_back(in);
    }

    return comando;  // Retorna el vector con los comandos ingresados
}

int main(int argc, char *argv[]) {
    // Bucle infinito para mantener la ejecucion del programa hasta que el usuario decida salir
    while (true) {
        // Captura la entrada del usuario y la convierte en un vector de strings
        vector<string> comando = userIn();

        // Comando para salir del programa
        if (comando[0] == "exit") {
            cout << "\nSaliendo del sistema...\n";
            exit(0);
  