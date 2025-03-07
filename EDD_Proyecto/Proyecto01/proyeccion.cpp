#include "proyeccion.h"

imagen proyeccion2D(volumen vol, string direccion, string criterio) {
    imagen resultado;
    resultado.codigo = "P2";
    resultado.W = vol.W;
    resultado.H = vol.H;
    resultado.M = vol.imgv[0].M;
    resultado.val = vector<vector<int>>(resultado.H, vector<int>(resultado.W, 0));

    for (int y = 0; y < resultado.H; y++) {
        for (int x = 0; x < resultado.W; x++) {
            vector<int> valores;
            for (int z = 0; z < vol.n_im; z++) {
                valores.push_back(vol.imgv[z].val[y][x]);
            }

            if (criterio == "minimo") {
                resultado.val[y][x] = *min_element(valores.begin(), valores.end());
            } else if (criterio == "maximo") {
                resultado.val[y][x] = *max_element(valores.begin(), valores.end());
            } else if (criterio == "promedio") {
                int suma = 0;
                for (int v : valores) suma += v;
                resultado.val[y][x] = suma / valores.size();
            } else if (criterio == "mediana") {
                sort(valores.begin(), valores.end());
                resultado.val[y][x] = valores[valores.size() / 2];
            }
        }
    }
    return resultado;
}
