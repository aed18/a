#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mochila(int n, int M, int* p, int* b) {
 
    int** V = new int* [n + 1];
    for (int i = 0; i <= n; ++i) {
        V[i] = new int[M + 1];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= M; ++j) {
            V[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (*(p + i - 1) <= j) {
                V[i][j] = max(V[i - 1][j], *(b + i - 1) + V[i - 1][j - *(p + i - 1)]);
            }
            else {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    cout << "tabla" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= M; ++j) {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> solucion(n, 0);

    int j = M;
    for (int i = n; i > 0; --i) {
        if (V[i][j] != V[i - 1][j]) {
            solucion[i - 1] = 1;
            j -= *(p + i - 1);
        }
    }

    cout << "Solucion" << endl;
    for (auto value : solucion) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    int n = 3;
    int M = 6;
    int pesos[] = {2,3,4};
    int valor[] = {1,2,5};

    mochila(n, M, pesos, valor);

    return 0;
}
