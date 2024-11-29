#include <iostream>
#include <vector>
using namespace std;

int mochilaBinaria(int n, int M, vector<int>& b, vector<int>& p) {
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= M; ++w) {
            if (b[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - b[i - 1]] + p[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][M];
}

int main() {
    int n = 4, M = 7;
    vector<int> b = {2, 3, 4, 5};
    vector<int> p = {1, 2, 3, 4};
    cout << "Máximo beneficio: " << mochilaBinaria(n, M, b, p) << endl;
    return 0;
}
