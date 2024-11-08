#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para intercambiar dos elementos en un vector
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Función para encontrar la mediana de un vector usando la estrategia "divide y vencerás"
int findMedian(vector<int>& arr, int left, int right) {
    int n = right - left + 1;

    // Si el tamaño del vector es impar, devuelve el elemento central
    if (n % 2 != 0) {
        return arr[left + n / 2];
    }

    // Si el tamaño del vector es par, encuentra el elemento central en el subconjunto ordenado
    vector<int> medianCandidates;
    for (int i = left; i <= right; i += 5) {
        int subRight = min(i + 4, right);
        sort(arr.begin() + i, arr.begin() + subRight + 1);
        medianCandidates.push_back(arr[i + (subRight - i) / 2]);
    }

    // Encuentra la mediana de las medianas recursivamente
    return findMedian(medianCandidates, 0, medianCandidates.size() - 1);
}

int main() {
    // Ejemplo de uso
    vector<int> arr = {12, 4, 5, 7, 3, 8, 1, 6, 9, 10, 2, 11};

    int median = findMedian(arr, 0, arr.size() - 1);

    cout << "Mediana del vector: " << median << endl;

    return 0;
}
