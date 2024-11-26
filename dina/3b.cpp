#include <iostream>
#include <vector>

double calcularProbabilidad(int i, int j, double PL, double PV) {
    if (i == 0 && j > 0) {
        return 1.0;
    } else if (j == 0 && i > 0) {
        return 0.0;
    } else {
        return PL * calcularProbabilidad(i - 1, j, PL, PV) + (1.0 - PV) * calcularProbabilidad(i, j - 1, PL, PV);
    }
}

int main() {
    int n = 3; // Número total de victorias necesarias
    double PL = 0.6; // Probabilidad de ganar como local
    double PV = 0.4; // Probabilidad de ganar como visitante

    double probabilidadGanar = calcularProbabilidad(n, n, PL, PV);

    std::cout << "La probabilidad de que Informáticos CB gane el play-off es: " << probabilidadGanar << std::endl;

    return 0;
}
