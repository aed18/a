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

// Función para realizar la partición rápida
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}

// Función para encontrar el k-ésimo menor elemento usando la selección rápida
int kthSmallest(vector<int>& arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int partitionIndex = partition(arr, low, high);

        // Si el k-ésimo menor está en la partición izquierda
        if (partitionIndex - low == k - 1) {
            return arr[partitionIndex];
        }

        // Si el k-ésimo menor está en la partición derecha
        if (partitionIndex - low > k - 1) {
            return kthSmallest(arr, low, partitionIndex - 1, k);
        }

        // Si el k-ésimo menor está en la partición derecha
        return kthSmallest(arr, partitionIndex + 1, high, k - partitionIndex + low - 1);
    }

    // Si k no es válido
    return -1;
}

int main() {
    // Ejemplo de uso
    vector<int> arr = {12, 4, 5, 7, 3, 8, 1, 6, 9, 10, 2, 11};
    int k = 5; // Encuentra el quinto menor elemento

    int kthElement = kthSmallest(arr, 0, arr.size() - 1, k);

    cout << "El " << k << "-ésimo menor elemento es: " << kthElement << endl;

    return 0;
}
