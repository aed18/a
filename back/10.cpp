#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// Función para calcular el costo total del recorrido
int CalcularCostoTotal(const vector<vector<int>>& grafo, const vector<int>& recorrido) {
    int costo = 0;
    for (int i = 0; i < recorrido.size() - 1; ++i) {
        int ciudadActual = recorrido[i];
        int ciudadSiguiente = recorrido[i + 1];
        costo += grafo[ciudadActual][ciudadSiguiente];
    }
    costo += grafo[recorrido.back()][recorrido[0]]; // Regresar a la ciudad de origen
    return costo;
}

// Función principal de backtracking para el Problema del Viajante
void ViajanteBacktracking(int ciudadActual, vector<int>& recorrido, vector<bool>& visitado, const vector<vector<int>>& grafo, int& mejorCosto, vector<int>& mejorRecorrido) {
    if (recorrido.size() == grafo.size()) {
        int costoActual = CalcularCostoTotal(grafo, recorrido);
        if (costoActual < mejorCosto) {
            mejorCosto = costoActual;
            mejorRecorrido = recorrido;
        }
        return;
    }

    for (int i = 0; i < grafo.size(); ++i) {
        if (!visitado[i]) {
            visitado[i] = true;
            recorrido.push_back(i);
            ViajanteBacktracking(i, recorrido, visitado, grafo, mejorCosto, mejorRecorrido);
            recorrido.pop_back();
            visitado[i] = false;
        }
    }
}

int main() {
    // Ejemplo de grafo (matriz de adyacencia)
    vector<vector<int>> grafo = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = grafo.size();

    vector<int> recorrido;
    vector<bool> visitado(n, false);
    recorrido.push_back(0); // Comenzar desde la ciudad 0

    int mejorCosto = INF;
    vector<int> mejorRecorrido;

    ViajanteBacktracking(0, recorrido, visitado, grafo, mejorCosto, mejorRecorrido);

    cout << "Mejor recorrido: ";
    for (int ciudad : mejorRecorrido) {
        cout << ciudad << " ";
    }
    cout << endl;

    cout << "Mejor costo: " << mejorCosto << endl;

    return 0;
}
