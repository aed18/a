#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool esBipartito(vector<vector<int>>& grafo, int n) {
    vector<int> colores(n, -1); // -1: sin color, 0: color 1, 1: color 2
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (colores[i] == -1) { // Si no está coloreado
            colores[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int nodo = q.front();
                q.pop();

                for (int vecino : grafo[nodo]) {
                    if (colores[vecino] == -1) { // No coloreado
                        colores[vecino] = 1 - colores[nodo];
                        q.push(vecino);
                    } else if (colores[vecino] == colores[nodo]) {
                        return false; // No es bipartito
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> grafo = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    int n = grafo.size();
    if (esBipartito(grafo, n)) {
        cout << "El grafo es bipartito." << endl;
    } else {
        cout << "El grafo no es bipartito." << endl;
    }
    return 0;
}
