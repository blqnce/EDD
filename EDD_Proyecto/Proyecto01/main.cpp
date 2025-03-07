#include <iostream>
#include <sstream>
#include <vector>
#include "imagen.h"
#include "proyeccion.h"

using namespace std;

vector<string> userIn();

int main(int argc, char *argv[]) {	
    imagen img;
    volumen vol;
    string n_img, n_vol;

    while (true) {
        vector<string> comando = userIn();

        if (comando[0] == "exit") {
            cout << "\nsaliendo\n";
            exit(0);
        }
        else if (comando[0] == "cargar_imagen" && comando.size() == 2) {
            img = cargarImg(comando[1]);
            n_img = comando[1];
            cout << "\nse cargo " << comando[1] << " exitosamente\n" << endl;
        }
        else if (comando[0] == "cargar_volumen" && comando.size() == 3) {
            vol = cargarVol(comando[1], stoi(comando[2]));
            n_vol = comando[1];
            cout << "\nse cargo " << comando[1] << " con " << comando[2] << " imagenes exitosamente\n" << endl;
        }
        else if (comando[0] == "info_imagen" && comando.size() == 1) {
            cout << endl << n_img << "\nancho: " << img.W << "\nalto: " << img.H << endl;
        }
        else if (comando[0] == "info_volumen" && comando.size() == 1) {
            cout << endl << n_vol << "\nancho: " << vol.W << "\nalto: " << vol.H << "\ntamaño: " << vol.n_im << endl;
        }
        else if (comando[0] == "proyeccion2D" && comando.size() == 4) {
            if (vol.n_im == 0) {
                cout << "\nEl volumen aún no ha sido cargado en memoria.\n" << endl;
            } else {
                imagen resultado = proyeccion2D(vol, comando[1], comando[2]);
                guardarPGM(resultado, comando[3]);
                cout << "\nLa proyección 2D ha sido generada y almacenada en " << comando[3] << endl << endl;
            }
        }
        else {
            cout << "\ncomando invalido\n" << endl;
        }
    }
    return 0;
}

// Función para obtener la entrada del usuario
vector<string> userIn() {
    string in;
    cout << "$ ";
    getline(cin, in);
    stringstream ss(in);
    vector<string> comando;
    while (ss >> in) {
        comando.push_back(in);
    }
    return comando;
}
