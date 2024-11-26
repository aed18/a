#include <iostream>
#include <vector>
#include <cmath>

// Función para calcular la fiabilidad de la fase i con mi copias del dispositivo Di
double calcularFiabilidad(int mi, double ri) {
    return 1.0 - std::pow(1.0 - ri, mi);
}

// Función principal para maximizar la fiabilidad del sistema dado un límite de coste
double maximizarFiabilidad(int n, const std::vector<int>& ci, const std::vector<int>& mi, const std::vector<double>& ri, int C) {
    // Inicializar una tabla para almacenar la máxima fiabilidad alcanzada hasta el momento para cada coste
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(C + 1, 0.0));

    // Iterar sobre cada fase i
    for (int i = 1; i <= n; ++i) {
        // Iterar sobre cada posible coste j
        for (int j = 0; j <= C; ++j) {
            // Inicializar la máxima fiabilidad alcanzada hasta el momento con el valor anterior
            dp[i][j] = dp[i - 1][j];

            // Probar cada cantidad de copias del dispositivo en la fase i
            for (int k = 1; k <= mi[i - 1] && j - k * ci[i - 1] >= 0; ++k) {
                // Calcular la fiabilidad con k copias
                double fiabilidadFaseI = calcularFiabilidad(k, ri[i - 1]);

                // Actualizar la máxima fiabilidad si es necesario
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k * ci[i - 1]] + fiabilidadFaseI);
            }
        }
    }

    // La respuesta estará en la esquina inferior derecha de la tabla
    return dp[n][C];
}

int main() {
    int n = 5; // Número de fases
    std::vector<int> ci = {1, 2, 3, 4, 5}; // Coste de cada unidad del dispositivo en cada fase
    std::vector<int> mi = {2, 3, 1, 2, 1}; // Número de copias del dispositivo en cada fase
    std::vector<double> ri = {0.99, 0.95, 0.98, 0.96, 0.97}; // Fiabilidad de cada dispositivo en cada fase
    int C = 10; // Límite de coste total

    double maxFiabilidad = maximizarFiabilidad(n, ci, mi, ri, C);

    std::cout << "Máxima fiabilidad alcanzada: " << maxFiabilidad << std::endl;

    return 0;
}
