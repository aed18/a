#include <iostream>
#include <vector>

using namespace std;

bool CumplePropiedad(const vector<int>& subconjunto, int umbral) {
    int suma = 0;
    for (int num : subconjunto) {
        suma += num;
    }
    return suma > umbral;
}

void SubconjuntoConPropiedad(int idx, vector<int>& conjunto, vector<int>& actual, int umbral) {
    if (idx == conjunto.size()) {
        if (CumplePropiedad(actual, umbral)) {
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
    SubconjuntoConPropiedad(idx + 1, conjunto, actual, umbral);

    // No incluir el elemento actual en el subconjunto
    actual.pop_back();
    SubconjuntoConPropiedad(idx + 1, conjunto, actual, umbral);
}

int main() {
    vector<int> conjunto = {3, 1, 4, 2, 2};
    vector<int> actual;
    int umbral = 5;

    SubconjuntoConPropiedad(0, conjunto, actual, umbral);

    return 0;
}
