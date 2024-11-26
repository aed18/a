#include <iostream>
#include <vector>
#include <climits>

struct Eslabon {
    int peso;
    char etiqueta;  // Puedes almacenar información adicional sobre el eslabón si es necesario
};

int costoUnion(const std::vector<Eslabon>& eslabones, int i, int j, int k) {
    // Función de costo para la unión de las subcadenas i a j y j+1 a k
    return eslabones[i].peso + eslabones[j].peso + eslabones[k].peso;
}

void construirCadena(const std::vector<Eslabon>& eslabones) {
    int n = eslabones.size();
    
    // Crear una matriz para almacenar los costos mínimos
    std::vector<std::vector<int>> costoMinimo(n, std::vector<int>(n, INT_MAX));

    // Rellenar la diagonal con los pesos individuales
    for (int i = 0; i < n; ++i) {
        costoMinimo[i][i] = eslabones[i].peso;
    }

    // Calcular los costos mínimos
    for (int longitud = 2; longitud <= n; ++longitud) {
        for (int i = 0; i <= n - longitud; ++i) {
            int j = i + longitud - 1;
            for (int k = i; k < j; ++k) {
                costoMinimo[i][j] = std::min(costoMinimo[i][j], costoUnion(eslabones, i, k, j));
            }
        }
    }

    // El costo mínimo total para construir la cadena estará en la esquina superior derecha
    int costoTotal = costoMinimo[0][n - 1];

    std::cout << "Costo total de construcción: " << costoTotal << std::endl;
}

int main() {
    std::vector<Eslabon> eslabones = {{2, 'a'}, {5, 'b'}, {10, 'c'}, {12, 'd'}};

    construirCadena(eslabones);

    return 0;
}
