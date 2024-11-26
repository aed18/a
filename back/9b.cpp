#include <iostream>
#include <vector>

using namespace std;

void MinimizarExpresion(int idx, vector<int>& numeros, vector<int>& seleccionados, int N, int& mejorSuma, vector<int>& mejorSeleccion) {
    if (idx == numeros.size()) {
        int suma = 0;
        for (int num : seleccionados) {
            suma += num * num;
        }
        if (suma < mejorSuma && suma >= N) {
            mejorSuma = suma;
            mejorSeleccion = seleccionados;
        }
        return;
    }

    // Incluir el elemento actual en la selección
    seleccionados.push_back(numeros[idx]);
    MinimizarExpresion(idx + 1, numeros, seleccionados, N, mejorSuma, mejorSeleccion);

    // No incluir el elemento actual en la selección
    seleccionados.pop_back();
    MinimizarExpresion(idx + 1, numeros, seleccionados, N, mejorSuma, mejorSeleccion);
}

int main() {
    vector<int> numeros = {1, 2, 3, 4, 5};
    vector<int> seleccionados;
    int N = 10;

    int mejorSuma = INT_MAX;
    vector<int> mejorSeleccion;

    MinimizarExpresion(0, numeros, seleccionados, N, mejorSuma, mejorSeleccion);

    cout << "Mejor selección: ";
    for (int num : mejorSeleccion) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
