#include <iostream>
#include <vector>
using namespace std;

void dfs(int nodo, vector<vector<int>>& grafo, vector<bool>& visitado) {
    visitado[nodo] = true;
    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            dfs(vecino, grafo, visitado);
        }
    }
}

bool esConexo(vector<vector<int>>& grafo, int n) {
    vector<bool> visitado(n, false);
    dfs(0, grafo, visitado);
    for (bool v : visitado) {
        if (!v) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> grafo = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };
    int n = grafo.size();
    if (esConexo(grafo, n)) {
        cout << "El grafo es conexo." << endl;
    } else {
        cout << "El grafo no es conexo." << endl;
    }
    return 0;
}
