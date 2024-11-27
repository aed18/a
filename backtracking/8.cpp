#include <iostream>
#include <vector>
using namespace std;

bool dfsCiclo(int nodo, vector<vector<int>>& grafo, vector<bool>& visitado, vector<bool>& enRecursion) {
    visitado[nodo] = true;
    enRecursion[nodo] = true;

    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino] && dfsCiclo(vecino, grafo, visitado, enRecursion)) {
            return true;
        } else if (enRecursion[vecino]) {
            return true;
        }
    }

    enRecursion[nodo] = false;
    return false;
}

bool tieneCiclos(vector<vector<int>>& grafo, int n) {
    vector<bool> visitado(n, false);
    vector<bool> enRecursion(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visitado[i] && dfsCiclo(i, grafo, visitado, enRecursion)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> grafo = {
        {1},        // Nodo 0 -> Nodo 1
        {2},        // Nodo 1 -> Nodo 2
        {0},        // Nodo 2 -> Nodo 0 (ciclo)
        {}
    };

    int n = grafo.size();
    if (tieneCiclos(grafo, n)) {
        cout << "El grafo tiene ciclos." << endl;
    } else {
        cout << "El grafo no tiene ciclos." << endl;
    }
    return 0;
}
