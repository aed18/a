#include <iostream>
#include <vector>
#include <algorithm>

// Estructura para representar una arista
struct Arista {
    int origen, destino, peso;

    Arista(int o, int d, int p) : origen(o), destino(d), peso(p) {}
};

// Estructura para representar un conjunto disjunto (Union-Find)
struct UnionFind {
    std::vector<int> padre, rango;

    UnionFind(int n) {
        padre.resize(n);
        rango.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            padre[i] = i;
        }
    }

    // Encuentra el representante (raíz) del conjunto al que pertenece el nodo x
    int encontrar(int x) {
        if (padre[x] != x) {
            padre[x] = encontrar(padre[x]);
        }
        return padre[x];
    }

    // Une los conjuntos a los que pertenecen los nodos x e y
    void unir(int x, int y) {
        int raizX = encontrar(x);
        int raizY = encontrar(y);

        if (raizX != raizY) {
            // Uniéndolos por rango
            if (rango[raizX] < rango[raizY]) {
                padre[raizX] = raizY;
            } else if (rango[raizX] > rango[raizY]) {
                padre[raizY] = raizX;
            } else {
                // Ambos tienen el mismo rango, se elige uno como raíz y se incrementa el rango
                padre[raizX] = raizY;
                rango[raizY]++;
            }
        }
    }
};

// Función para el algoritmo de Kruskal
std::vector<Arista> kruskal(std::vector<Arista>& aristas, int numNodos) {
    // Ordenar las aristas por peso de manera ascendente
    std::sort(aristas.begin(), aristas.end(), [](const Arista& a, const Arista& b) {
        return a.peso < b.peso;
    });

    std::vector<Arista> arbolDeExpansion;
    UnionFind conjuntos(numNodos);

    for (const Arista& arista : aristas) {
        if (conjuntos.encontrar(arista.origen) != conjuntos.encontrar(arista.destino)) {
            // Agregar la arista al árbol de expansión
            arbolDeExpansion.push_back(arista);

            // Unir los conjuntos a los que pertenecen los nodos de la arista
            conjuntos.unir(arista.origen, arista.destino);
        }
    }

    return arbolDeExpansion;
}

int main() {
    // Ejemplo de uso
    int numNodos = 6; // Número de nodos
    std::vector<Arista> aristas = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 4, 2}, {2, 4, 7}, {3, 5, 1}, {4, 5, 8}};

    // Aplicar el algoritmo de Kruskal
    std::vector<Arista> arbolDeExpansion = kruskal(aristas, numNodos);

    // Imprimir el árbol de expansión mínima
    std::cout << "Aristas del Árbol de Expansión Mínima:\n";
    for (const Arista& arista : arbolDeExpansion) {
        std::cout << "Arista: " << arista.origen << " - " << arista.destino << " Peso: " << arista.peso << "\n";
    }

    return 0;
}
