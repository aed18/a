#include <iostream>
#include <vector>

using namespace std;

// Función de partición para QuickSort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Tomamos el último elemento como pivote
    int i = low - 1; // El índice del menor elemento

    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++;
            // Intercambiamos arr[i] y arr[j]
            swap(arr[i], arr[j]);
        }
    }

    // Intercambiamos arr[i+1] y arr[high] (el pivote)
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Función principal de QuickSort que implementa la recursión
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Encuentra el índice de partición, arr[p] está en su posición correcta
        int p = partition(arr, low, high);

        // Ordena los elementos antes y después de la partición
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    int arrSize = arr.size();

    cout << "Arreglo original:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";

    quickSort(arr, 0, arrSize - 1);

    cout << "Arreglo ordenado:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
