#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsTopologico(int nodo, vector<vector<int>>& grafo, vector<bool>& visitado, stack<int>& orden) {
    visitado[nodo] = true;
    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            dfsTopologico(vecino, grafo, visitado, orden);
        }
    }
    orden.push(nodo);
}

vector<int> ordenTopologico(vector<vector<int>>& grafo, int n) {
    vector<bool> visitado(n, false);
    stack<int> orden;

    for (int i = 0; i < n; ++i) {
        if (!visitado[i]) {
            dfsTopologico(i, grafo, visitado, orden);
        }
    }

    vector<int> resultado;
    while (!orden.empty()) {
        resultado.push_back(orden.top());
        orden.pop();
    }
    return resultado;
}

int main() {
    vector<vector<int>> grafo = {
        {1, 2},
        {3},
        {3},
        {}
    };

    int n = grafo.size();
    vector<int> orden = ordenTopologico(grafo, n);

    cout << "Orden topológico: ";
    for (int nodo : orden) {
        cout << nodo << " ";
    }
    cout << endl;

    return 0;
}
