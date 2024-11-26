#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

void calcularCosteMinimo(const std::vector<std::vector<int>>& costes) {
    int n = costes.size();

    // Crear una matriz para almacenar los costes mínimos
    std::vector<std::vector<int>> costeMinimo(n, std::vector<int>(n, INF));

    // Inicializar los costes directos
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && costes[i][j] != INF) {
                costeMinimo[i][j] = costes[i][j];
            }
        }
    }

    // Calcular los costes mínimos utilizando programación dinámica
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Si se puede mejorar el coste de ir de i a j pasando por k
                if (costeMinimo[i][k] != INF && costeMinimo[k][j] != INF) {
                    costeMinimo[i][j] = std::min(costeMinimo[i][j], costeMinimo[i][k] + costeMinimo[k][j]);
                }
            }
        }
    }

    // Imprimir los costes mínimos
    std::cout << "Matriz de costes mínimos:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (costeMinimo[i][j] == INF) {
                std::cout << "INF ";
            } else {
                std::cout << costeMinimo[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> costes = {
        {0, 17, 8, 16, 20},
        {INF, 0, 12, 6, 15},
        {INF, INF, 0, 12, 16},
        {INF, INF, INF, 0, 15},
        {INF, INF, INF, INF, 0}
    };

    calcularCosteMinimo(costes);

    return 0;
}
