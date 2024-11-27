#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int contarCaminosMinimos(vector<vector<int>>& grafo, int inicio, int fin, int n) {
    vector<int> distancias(n, INT_MAX);
    vector<int> caminos(n, 0);

    queue<int> q;
    q.push(inicio);
    distancias[inicio] = 0;
    caminos[inicio] = 1;

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();

        for (int vecino : grafo[nodo]) {
            if (distancias[vecino] > distancias[nodo] + 1) {
                distancias[vecino] = distancias[nodo] + 1;
                caminos[vecino] = caminos[nodo];
                q.push(vecino);
            } else if (distancias[vecino] == distancias[nodo] + 1) {
                caminos[vecino] += caminos[nodo];
            }
        }
    }

    return caminos[fin];
}

int main() {
    vector<vector<int>> grafo = {
        {1, 2},
        {3},
        {3},
        {}
    };

    int inicio = 0, fin = 3, n = grafo.size();
    cout << "Número de caminos mínimos: " << contarCaminosMinimos(grafo, inicio, fin, n) << endl;

    return 0;
}
