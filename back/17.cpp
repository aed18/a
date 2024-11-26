#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solveKnapsack(int n, const vector<int>& v, const vector<int>& w, int M) {
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (w[i - 1] <= j) {
                // Intentar añadir el objeto a la mochila
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i - 1]] + v[i - 1]);
            } else {
                // No se puede añadir el objeto, tomar el valor de la fila anterior
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][M];
}

int main() {
    int n = 3;
    vector<int> v = {2, 3, 4};
    vector<int> w = {1, 2, 3};
    int M = 5;

    int resultado = solveKnapsack(n, v, w, M);

    cout << "El máximo beneficio equilibrado es: " << resultado << endl;

    return 0;
}
