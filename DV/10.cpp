#include <iostream>
#include <vector>

using namespace std;

// Función auxiliar para buscar si hay un índice i tal que X[i] = i
int searchIndexEqualsValue(const vector<int>& X, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // Verificar si X[mid] es igual a mid
        if (X[mid] == mid) {
            return mid; // Encontramos un índice que cumple la condición
        } else if (X[mid] > mid) {
            // Si X[mid] es mayor que mid, la solución está en la mitad izquierda
            return searchIndexEqualsValue(X, low, mid - 1);
        } else {
            // Si X[mid] es menor que mid, la solución está en la mitad derecha
            return searchIndexEqualsValue(X, mid + 1, high);
        }
    }

    // Si no encontramos ningún índice que cumpla la condición
    return -1;
}

// Función principal para buscar si existe un índice i tal que X[i] = i
int findIndexEqualsValue(const vector<int>& X) {
    return searchIndexEqualsValue(X, 0, X.size() - 1);
}

int main() {
    vector<int> X = {-10, -5, 0, 3, 7, 9, 12, 17}; // Vector ordenado

    int result = findIndexEqualsValue(X);

    if (result != -1) {
        cout << "Existe un índice i = " << result << " tal que X[i] = i." << endl;
    } else {
        cout << "No existe ningún índice i tal que X[i] = i." << endl;
    }

    return 0;
}
