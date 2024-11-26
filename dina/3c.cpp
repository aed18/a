#include <iostream>
#include <vector>

double calcularProbabilidadIntercalada(int i, int j, double PL, double PV) {
    if (i == 0 && j > 0) {
        return 1.0;
    } else if (j == 0 && i > 0) {
        return 0.0;
    } else {
        if ((i + j) % 2 == 0) {
            // Juega en casa
            return PL * calcularProbabilidadIntercalada(i - 1, j, PL, PV) + (1.0 - PV) * calcularProbabilidadIntercalada(i, j - 1, PL, PV);
        } else {
            // Juega fuera
            return (1.0 - PL) * calcularProbabilidadIntercalada(i - 1, j, PL, PV) + PV * calcularProbabilidadIntercalada(i, j - 1, PL, PV);
        }
    }
}

int main() {
    int n = 3; // Número total de victorias necesarias
    double PL = 0.6; // Probabilidad de ganar como local
    double PV = 0.4; // Probabilidad de ganar como visitante

    double probabilidadGanarIntercalada = calcularProbabilidadIntercalada(n, n, PL, PV);

    std::cout << "La probabilidad de que Informáticos CB gane el play-off intercalando partidos es: " << probabilidadGanarIntercalada << std::endl;

    return 0;
}
