#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void MinimizarDiferencia(int idx, vector<int>& conjunto, vector<int>& actual, int N, int& mejorDiferencia, vector<int>& mejorSubconjunto) {
    if (idx == conjunto.size()) {
        int suma = 0;
        for (int num : actual) {
            suma += num;
        }
        int diferencia = abs(N - suma);
        if (diferencia < mejorDiferencia) {
            mejorDiferencia = diferencia;
            mejorSubconjunto = actual;
        }
        return;
    }

    // Incluir el elemento actual en el subconjunto
    actual.push_back(conjunto[idx]);
    MinimizarDiferencia(idx + 1, conjunto, actual, N, mejorDiferencia, mejorSubconjunto);

    // No incluir el elemento actual en el subconjunto
    actual.pop_back();
    MinimizarDiferencia(idx + 1, conjunto, actual, N, mejorDiferencia, mejorSubconjunto);
}

int main() {
    vector<int> conjunto = {3, 1, 4, 2, 2};
    vector<int> actual;
    int N = 10;

    int mejorDiferencia = INT_MAX;
    vector<int> mejorSubconjunto;

    MinimizarDiferencia(0, conjunto, actual, N, mejorDiferencia, mejorSubconjunto);

    cout << "Mejor subconjunto: ";
    for (int num : mejorSubconjunto) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
