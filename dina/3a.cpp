#include <iostream>
#include <vector>

double calcularProbabilidad(int i, int j, double P) {
    if (i == 0 && j > 0) {
        return 1.0;
    } else if (j == 0 && i > 0) {
        return 0.0;
    } else {
        return P * calcularProbabilidad(i - 1, j, P) + (1.0 - P) * calcularProbabilidad(i, j - 1, P);
    }
}

int main() {
    int n = 3; // Número total de victorias necesarias
    double P = 0.5; // Probabilidad de ganar un partido concreto

    double probabilidadGanar = calcularProbabilidad(n, n, P);

    std::cout << "La probabilidad de que Informáticos CB gane el play-off es: " << probabilidadGanar << std::endl;

    return 0;
}
