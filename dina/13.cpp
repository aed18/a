#include <iostream>
#include <vector>
#include <limits>

struct Arco {
    int origen, destino, peso;
};

struct Grafo {
    int numNodos, numArcos;
    std::vector<Arco> arcos;

    // Constructor
    Grafo(int n, int m) : numNodos(n), numArcos(m) {}
};

bool tieneCicloNegativo(const Grafo& grafo) {
    int numNodos = grafo.numNodos;
    int numArcos = grafo.numArcos;

    // Agregar un nuevo nodo al grafo
    int nuevoNodo = numNodos;
    std::vector<Arco> arcosExtendidos = grafo.arcos;

    for (int i = 0; i < numNodos; ++i) {
        arcosExtendidos.push_back({nuevoNodo, i, 0});
    }

    // Inicializar distancias
    std::vector<int> distancia(numNodos + 1, std::numeric_limits<int>::max());
    distancia[nuevoNodo] = 0;

    // Aplicar el algoritmo de Bellman-Ford
    for (int i = 0; i < numNodos; ++i) {
        for (const Arco& arco : arcosExtendidos) {
            int u = arco.origen;
            int v = arco.destino;
            int peso = arco.peso;

            if (distancia[u] != std::numeric_limits<int>::max() && distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
            }
        }
    }

    // Verificar si hay ciclos negativos
    for (const Arco& arco : arcosExtendidos) {
        int u = arco.origen;
        int v = arco.destino;
        int peso = arco.peso;

        if (distancia[u] != std::numeric_limits<int>::max() && distancia[u] + peso < distancia[v]) {
            return true; // Ciclo negativo detectado
        }
    }

    return false; // No hay ciclos negativos
}

int main() {
    // Ejemplo de uso
    Grafo grafo(3, 3); // Grafo con 3 nodos y 3 arcos
    grafo.arcos = {{0, 1, -1}, {1, 2, -2}, {2, 0, -3}};

    if (tieneCicloNegativo(grafo)) {
        std::cout << "El grafo tiene ciclos negativos.\n";
    } else {
        std::cout << "El grafo no tiene ciclos negativos.\n";
    }

    return 0;
}
