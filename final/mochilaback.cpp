#include <iostream>
#include <vector>
using namespace std;

int maxBeneficio = 0;

void backtracking(int i, int n, int M, int pesoActual, int beneficioActual, vector<int>& b, vector<int>& p) {
    if (pesoActual > M) return; // Si excede la capacidad, descartar
    if (i == n) {
        maxBeneficio = max(maxBeneficio, beneficioActual);
        return;
    }
    // Incluir el elemento actual
    backtracking(i + 1, n, M, pesoActual + b[i], beneficioActual + p[i], b, p);
    // No incluir el elemento actual
    backtracking(i + 1, n, M, pesoActual, beneficioActual, b, p);
}

int main() {
    int n = 4, M = 7;
    vector<int> b = {3, 4, 5, 6};
    vector<int> p = {2, 3, 4, 5};
    backtracking(0, n, M, 0, 0, b, p);
    cout << "Máximo beneficio: " << maxBeneficio << endl;
    return 0;
}
