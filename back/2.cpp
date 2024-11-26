#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un nodo en el árbol de soluciones
struct Node {
    int level;
    int benefit;
    int weight;
    vector<int> chosen_items;
};

// Función para calcular el beneficio estimado utilizando el algoritmo voraz
int estimateBenefit(int level, int remaining_weight, const vector<int>& v, const vector<int>& w) {
    int estimate = 0;
    for (int i = level; i < v.size(); ++i) {
        if (w[i] <= remaining_weight) {
            estimate += v[i];
            remaining_weight -= w[i];
        } else {
            estimate += static_cast<int>((static_cast<double>(v[i]) / w[i]) * remaining_weight);
            break;
        }
    }
    return estimate;
}

// Función principal de backtracking
void knapsackBacktracking(int level, int& bestBenefit, vector<int>& bestItems, const Node& currentNode,
                           const vector<int>& v, const vector<int>& w, int capacity) {
    // Verificar si alcanzamos una solución completa
    if (level == v.size()) {
        if (currentNode.benefit > bestBenefit) {
            bestBenefit = currentNode.benefit;
            bestItems = currentNode.chosen_items;
        }
        return;
    }

    // No incluir el elemento actual
    Node excludeNode = currentNode;
    knapsackBacktracking(level + 1, bestBenefit, bestItems, excludeNode, v, w, capacity);

    // Incluir el elemento actual si es factible
    if (w[level] <= capacity) {
        Node includeNode = currentNode;
        includeNode.level = level + 1;
        includeNode.benefit += v[level];
        includeNode.weight += w[level];
        includeNode.chosen_items.push_back(level + 1);

        // Podar si el beneficio estimado no supera el mejor beneficio actual
        int estimatedBenefit = estimateBenefit(level + 1, capacity - w[level], v, w);
        if (includeNode.benefit + estimatedBenefit > bestBenefit) {
            knapsackBacktracking(level + 1, bestBenefit, bestItems, includeNode, v, w, capacity - w[level]);
        }
    }
}

int main() {
    int n = 5;
    int M = 20;
    vector<int> v = {10, 7, 6, 4, 2};
    vector<int> w = {30, 15, 11, 8, 2};

    int bestBenefit = 0;
    vector<int> bestItems;

    Node initialNode = {0, 0, 0, {}};
    knapsackBacktracking(0, bestBenefit, bestItems, initialNode, v, w, M);

    // Resultados
    cout << "Mejor beneficio: " << bestBenefit << endl;
    cout << "Items seleccionados: ";
    for (int item : bestItems) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
