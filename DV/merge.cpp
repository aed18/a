#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crear vectores temporales
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copiar datos a los vectores temporales leftArr[] y rightArr[]
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    // Combinar los vectores temporales de nuevo en arr[left..right]
    int i = 0; // Índice inicial del primer subarreglo
    int j = 0; // Índice inicial del segundo subarreglo
    int k = left; // Índice inicial del subarreglo fusionado

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de leftArr[], si los hay
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de rightArr[], si los hay
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Encuentra el punto medio del vector
        int middle = left + (right - left) / 2;

        // Ordena la primera mitad y la segunda mitad
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Combina las mitades ordenadas
        merge(arr, left, middle, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    int arrSize = arr.size();

    cout << "Arreglo original:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";

    mergeSort(arr, 0, arrSize - 1);

    cout << "Arreglo ordenado:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
