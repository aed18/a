#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfsArticulacion(int nodo, int padre, vector<vector<int>>& grafo, vector<bool>& visitado,
                     vector<int>& num, vector<int>& low, vector<bool>& articulacion, int& tiempo) {
    visitado[nodo] = true;
    num[nodo] = low[nodo] = ++tiempo;
    int hijos = 0;

    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            hijos++;
            dfsArticulacion(vecino, nodo, grafo, visitado, num, low, articulacion, tiempo);
            low[nodo] = min(low[nodo], low[vecino]);

            if (padre == -1 && hijos > 1) {
                articulacion[nodo] = true;
            }
            if (padre != -1 && low[vecino] >= num[nodo]) {
                articulacion[nodo] = true;
            }
        } else if (vecino != padre) {
            low[nodo] = min(low[nodo], num[vecino]);
        }
    }
}

vector<bool> encontrarArticulaciones(vector<vector<int>>& grafo, int n) {
    vector<bool> visitado(n, false), articulacion(n, false);
    vector<int> num(n, -1), low(n, -1);
    int tiempo = 0;

    for (int i = 0; i < n; ++i) {
        if (!visitado[i]) {
            dfsArticulacion(i, -1, grafo, visitado, num, low, articulacion, tiempo);
        }
    }

    return articulacion;
}

int main() {
    vector<vector<int>> grafo = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2, 4, 5},
        {3, 5},
        {3, 4}
    };

    int n = grafo.size();
    vector<bool> articulaciones = encontrarArticulaciones(grafo, n);

    cout << "Puntos de articulación: ";
    for (int i = 0; i < n; ++i) {
        if (articulaciones[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
