#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// Estructura para representar una arista
struct Arista {
    int destino;
    int peso;

    Arista(int d, int p) : destino(d), peso(p) {}
};

// Función para el algoritmo de Dijkstra
void dijkstra(const std::vector<std::vector<Arista>>& grafo, int inicio, std::vector<int>& distancias) {
    int n = grafo.size();
    distancias.resize(n, INF);
    distancias[inicio] = 0;

    // Cola de prioridad para nodos no visitados
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, inicio});

    while (!pq.empty()) {
        int u = pq.top().second;
        int distanciaU = pq.top().first;
        pq.pop();

        // Si ya hemos procesado este nodo, lo ignoramos
        if (distanciaU > distancias[u]) {
            continue;
        }

        // Iterar sobre los vecinos de u
        for (const Arista& vecino : grafo[u]) {
            int v = vecino.destino;
            int pesoUV = vecino.peso;

            // Relajación de la arista (u, v)
            if (distancias[u] + pesoUV < distancias[v]) {
                distancias[v] = distancias[u] + pesoUV;
                pq.push({distancias[v], v});
            }
        }
    }
}

int main() {
    // Ejemplo de uso
    int n = 6; // Número de nodos
    std::vector<std::vector<Arista>> grafo(n);

    // Agregar aristas al grafo (dirigido)
    grafo[0].emplace_back(1, 5);
    grafo[0].emplace_back(2, 3);
    grafo[1].emplace_back(3, 6);
    grafo[1].emplace_back(4, 2);
    grafo[2].emplace_back(4, 7);
    grafo[3].emplace_back(5, 1);
    grafo[4].emplace_back(5, 8);

    int inicio = 0; // Nodo de inicio

    // Vector para almacenar las distancias más cortas desde el nodo de inicio
    std::vector<int> distancias;

    // Aplicar el algoritmo de Dijkstra
    dijkstra(grafo, inicio, distancias);

    // Imprimir las distancias más cortas desde el nodo de inicio
    std::cout << "Distancias más cortas desde el nodo " << inicio << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Nodo " << i << ": " << distancias[i] << "\n";
    }

    return 0;
}
