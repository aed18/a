#include <iostream>
#include <vector>

using namespace std;

// Función para combinar y contar las inversiones en dos sub-rankings
int mergeAndCountInversions(vector<int>& ranking, vector<int>& temp, int low, int mid, int high) {
    int inversions = 0;

    int i = low;      // Índice para la primera mitad del ranking
    int j = mid + 1;  // Índice para la segunda mitad del ranking
    int k = low;      // Índice para el array temporal

    while (i <= mid && j <= high) {
        if (ranking[i] <= ranking[j]) {
            temp[k++] = ranking[i++];
        } else {
            // Contar inversiones al encontrar un elemento en la primera mitad mayor que uno en la segunda mitad
            inversions += (mid - i + 1);
            temp[k++] = ranking[j++];
        }
    }

    // Completar la fusión si hay elementos restantes en la primera mitad
    while (i <= mid) {
        temp[k++] = ranking[i++];
    }

    // Completar la fusión si hay elementos restantes en la segunda mitad
    while (j <= high) {
        temp[k++] = ranking[j++];
    }

    // Copiar el array temporal de vuelta al array original
    for (int l = low; l <= high; ++l) {
        ranking[l] = temp[l];
    }

    return inversions;
}

// Función principal para contar inversiones usando "divide y vencerás"
int countInversions(vector<int>& ranking, vector<int>& temp, int low, int high) {
    int inversions = 0;

    if (low < high) {
        int mid = low + (high - low) / 2;

        // Contar inversiones en la primera mitad y en la segunda mitad
        inversions += countInversions(ranking, temp, low, mid);
        inversions += countInversions(ranking, temp, mid + 1, high);

        // Combinar y contar inversiones entre las dos mitades
        inversions += mergeAndCountInversions(ranking, temp, low, mid, high);
    }

    return inversions;
}

int main() {
    // Ejemplo de uso
    vector<int> ranking = {4, 3, 2, 1};  // Cambia los valores según sea necesario
    vector<int> temp(ranking.size());

    // Contar inversiones en el ranking
    int inversions = countInversions(ranking, temp, 0, ranking.size() - 1);

    // Imprimir el resultado
    cout << "Número de inversiones en el ranking: " << inversions << endl;

    return 0;
}
