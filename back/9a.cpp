#include <iostream>
#include <vector>

using namespace std;

void SubconjuntosQueSumanM(int idx, vector<int>& conjunto, vector<int>& actual, int M) {
    if (idx == conjunto.size()) {
        int suma = 0;
        for (int num : actual) {
            suma += num;
        }
        if (suma == M) {
            cout << "Subconjunto encontrado: ";
            for (int num : actual) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    // Incluir el elemento actual en el subconjunto
    actual.push_back(conjunto[idx]);
    SubconjuntosQueSumanM(idx + 1, conjunto, actual, M);

    // No incluir el elemento actual en el subconjunto
    actual.pop_back();
    SubconjuntosQueSumanM(idx + 1, conjunto, actual, M);
}

int main() {
    vector<int> conjunto = {1, 2, 3, 4, 5};
    vector<int> actual;
    int M = 7;

    SubconjuntosQueSumanM(0, conjunto, actual, M);

    return 0;
}
