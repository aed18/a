#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int g(int i, int S, const std::vector<std::vector<int>>& grafo, std::vector<std::vector<int>>& memo) {
    int n = grafo.size();

    if (S == 0) {
        // Todos los nodos han sido visitados
        return grafo[i][0];
    }

    if (memo[i][S] != -1) {
        // Ya se ha calculado este caso
        return memo[i][S];
    }

    int minDist = INF;
    for (int k = 0; k < n; ++k) {
        if (S & (1 << k)) {
            // Si el k-ésimo bit está encendido (k está en S)
            minDist = std::min(minDist, grafo[i][k] + g(k, S - (1 << k), grafo, memo));
        }
    }

    return memo[i][S] = minDist;
}

int tsp(const std::vector<std::vector<int>>& grafo) {
    int n = grafo.size();

    // Inicializar la tabla de memorización
    std::vector<std::vector<int>> memo(n, std::vector<int>(1 << n, -1));

    // Inicializar el conjunto S (todos los nodos menos el nodo 1)
    int S = (1 << n) - 2;

    // Calcular la longitud del circuito hamiltoniano minimal
    int resultado = g(0, S, grafo, memo);

    return resultado;
}

int main() {
    std::vector<std::vector<int>> grafo = {
        {0, 29, 20, 21},
        {29, 0, 15, 18},
        {20, 15, 0, 26},
        {21, 18, 26, 0}
    };

    int resultado = tsp(grafo);

    std::cout << "Longitud del circuito hamiltoniano minimal: " << resultado << std::endl;

    return 0;
}
