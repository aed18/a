#include <iostream>
#include <vector>
#include <queue>

// Estructura para representar una arista
struct Arista {
    int destino;
    int peso;

    Arista(int d, int p) : destino(d), peso(p) {}
};

// Estructura para comparar aristas en la cola de prioridad (min heap)
struct ComparadorArista {
    bool operator()(const Arista& a, const Arista& b) {
        return a.peso > b.peso;
    }
};

// Función para el algoritmo de Prim
std::vector<std::vector<Arista>> prim(std::vector<std::vector<Arista>>& grafo) {
    int numNodos = grafo.size();
    std::vector<bool> visitado(numNodos, false);
    std::priority_queue<Arista, std::vector<Arista>, ComparadorArista> colaPrioridad;

    // Iniciar desde el nodo 0 (puede ser cualquier nodo)
    int nodoInicial = 0;
    visitado[nodoInicial] = true;

    // Agregar las aristas del nodo inicial a la cola de prioridad
    for (const Arista& arista : grafo[nodoInicial]) {
        colaPrioridad.push(arista);
    }

    std::vector<std::vector<Arista>> arbolDeExpansion(numNodos);

    while (!colaPrioridad.empty()) {
        // Obtener la arista de menor peso
        Arista aristaActual = colaPrioridad.top();
        colaPrioridad.pop();

        int nodoActual = aristaActual.destino;

        if (!visitado[nodoActual]) {
            // Agregar la arista al árbol de expansión mínima
            arbolDeExpansion[nodoActual].push_back({nodoInicial, aristaActual.peso});
            arbolDeExpansion[nodoInicial].push_back({nodoActual, aristaActual.peso});

            // Marcar el nodo actual como visitado
            visitado[nodoActual] = true;

            // Agregar las aristas del nodo actual a la cola de prioridad
            for (const Arista& vecino : grafo[nodoActual]) {
                colaPrioridad.push(vecino);
            }
        }
    }

    return arbolDeExpansion;
}

int main() {
    // Ejemplo de uso
    int numNodos = 5; // Número de nodos
    std::vector<std::vector<Arista>> grafo(numNodos);

    // Agregar aristas al grafo
    grafo[0].push_back({1, 2});
    grafo[0].push_back({2, 3});
    grafo[1].push_back({2, 1});
    grafo[1].push_back({3, 4});
    grafo[2].push_back({3, 5});
    grafo[3].push_back({4, 2});

    // Aplicar el algoritmo de Prim
    std::vector<std::vector<Arista>> arbolDeExpansion = prim(grafo);

    // Imprimir el árbol de expansión mínima
    std::cout << "Aristas del Árbol de Expansión Mínima:\n";
    for (int i = 0; i < numNodos; ++i) {
        for (const Arista& arista : arbolDeExpansion[i]) {
            std::cout << "Arista: " << i << " - " << arista.destino << " Peso: " << arista.peso << "\n";
        }
    }

    return 0;
}
