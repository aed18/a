#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void MinimizarProducto(int idx, vector<int>& conjunto, vector<int>& actual, int N, int& mejorD, vector<int>& mejorSubconjunto) {
    if (idx == conjunto.size()) {
        int producto = 1;
        for (int num : actual) {
            producto *= num;
        }
        int diferencia = N - producto;
        if (diferencia >= 0 && diferencia < mejorD) {
            mejorD = diferencia;
            mejorSubconjunto = actual;
        }
        return;
    }

    // Incluir el elemento actual en el subconjunto
    actual.push_back(conjunto[idx]);
    MinimizarProducto(idx + 1, conjunto, actual, N, mejorD, mejorSubconjunto);

    // No incluir el elemento actual en el subconjunto
    actual.pop_back();
    MinimizarProducto(idx + 1, conjunto, actual, N, mejorD, mejorSubconjunto);
}

int main() {
    vector<int> conjunto = {3, 1, 4, 2, 2};
    vector<int> actual;
    int N = 20;

    int mejorD = INT_MAX;
    vector<int> mejorSubconjunto;

    MinimizarProducto(0, conjunto, actual, N, mejorD, mejorSubconjunto);

    cout << "Mejor subconjunto: ";
    for (int num : mejorSubconjunto) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
