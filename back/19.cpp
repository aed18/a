#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizarBeneficio(int n, int M, vector<int>& pesos, vector<int>& beneficios) {
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = M; j >= 0; --j) {
            // Intentar colocar el objeto en la primera mochila
            if (j >= pesos[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - pesos[i - 1]] + beneficios[i - 1]);
            }

            // Intentar colocar el objeto en la segunda mochila
            if (j + pesos[i - 1] <= M) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + pesos[i - 1]] + beneficios[i - 1]);
            }

            // No colocar el objeto en ninguna mochila
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    // El resultado final estará en dp[n][M]
    return dp[n][M];
}

int main() {
    int n = 3; // Número de objetos
    int M = 10; // Peso máximo común a ambas mochilas
    vector<int> pesos = {3, 5, 2}; // Pesos de los objetos
    vector<int> beneficios = {5, 10, 2}; // Beneficios de los objetos

    int resultado = maximizarBeneficio(n, M, pesos, beneficios);

    cout << "El beneficio máximo obtenido es: " << resultado << endl;

    return 0;
}
