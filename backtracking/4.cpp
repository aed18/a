#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Nodo {
    int nivel, costo, bound, ciudadActual;
    vector<int> camino;
};

int calcularBound(Nodo& nodo, const vector<vector<int>>& distancias, int n) {
    int bound = nodo.costo;
    vector<bool> visitados(n, false);

    // Marcar las ciudades ya visitadas en el camino actual
    for (int ciudad : nodo.camino) {
        visitados[ciudad] = true;
    }

    // Sumar costos mínimos de las ciudades no visitadas
    for (int i = 0; i < n; ++i) {
        if (!visitados[i]) {
            int minCosto = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (i != j && !visitados[j] && distancias[i][j] != 0) {
                    minCosto = min(minCosto, distancias[i][j]);
                }
            }
            bound += minCosto;
        }
    }
    return bound;
}

int branchAndBoundTSP(const vector<vector<int>>& distancias) {
    int n = distancias.size();
    priority_queue<pair<int, Nodo>, vector<pair<int, Nodo>>, greater<>> pq;

    Nodo raiz = {0, 0, 0, 0, {0}};
    raiz.bound = calcularBound(raiz, distancias, n);
    pq.push({raiz.bound, raiz});

    int minCosto = INT_MAX;
    vector<int> mejorCamino;

    while (!pq.empty()) {
        Nodo nodo = pq.top().second;
        pq.pop();

        if (nodo.bound >= minCosto) continue;

        if (nodo.nivel == n - 1) {
            int costoFinal = nodo.costo + distancias[nodo.ciudadActual][0];
            if (costoFinal < minCosto) {
                minCosto = costoFinal;
                mejorCamino = nodo.camino;
            }
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (find(nodo.camino.begin(), nodo.camino.end(), i) == nodo.camino.end()) {
                Nodo hijo = nodo;
                hijo.nivel++;
                hijo.camino.push_back(i);
                hijo.costo += distancias[nodo.ciudadActual][i];
                hijo.ciudadActual = i;
                hijo.bound = calcularBound(hijo, distancias, n);

                if (hijo.bound < minCosto) {
                    pq.push({hijo.bound, hijo});
                }
            }
        }
    }

    cout << "Costo mínimo: " << minCosto << endl;
    cout << "Camino óptimo: ";
    for (int ciudad : mejorCamino) {
        cout << ciudad + 1 << " -> ";
    }
    cout << "1" << endl; // Volvemos a la ciudad inicial

    return minCosto;
}

int main() {
    vector<vector<int>> distancias = {
        {0, 3, 10, 11, 7},
        {3, 0, 8, 12, 9},
        {10, 8, 0, 9, 4},
        {11, 12, 9, 0, 5},
        {7, 9, 4, 5, 0}
    };

    branchAndBoundTSP(distancias);
    return 0;
}
