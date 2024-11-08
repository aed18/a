#include <iostream>
#include <vector>

using namespace std;

bool descendente(int a, int b)
{
    return a > b;
}

bool ascendente(int a, int b)
{
    return a < b;
}

// Función de partición para QuickSort
template <class T>
int partition(vector<int>& arr, int low, int high, T funcion) {
    int pivot = arr[high]; // Tomamos el último elemento como pivote
    int i = low - 1; // El índice del menor elemento

    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (funcion(arr[j],pivot)){
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
template <class T>
void quickSort(vector<int>& arr, int low, int high, T funcion) {
    if (low < high) {
        // Encuentra el índice de partición, arr[p] está en su posición correcta
        int p = partition(arr, low, high, funcion);

        // Ordena los elementos antes y después de la partición
        quickSort(arr, low, p - 1, funcion);
        quickSort(arr, p + 1, high, funcion);
    }
}

template <class T>
void merge(vector<int>& arr, int left, int middle, int right, T funcion) {
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
        if (funcion(leftArr[i],rightArr[j])) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
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

template <class T>
void mergeSort(vector<int>& arr, int left, int right, T funcion) {
    if (left < right) {
        // Encuentra el punto medio del vector
        int middle = left + (right - left) / 2;

        // Ordena la primera mitad y la segunda mitad
        mergeSort(arr, left, middle, funcion);
        mergeSort(arr, middle + 1, right, funcion);

        // Combina las mitades ordenadas
        merge(arr, left, middle, right, funcion);
    }
}

int main() {
    vector<int> arr = { 9,1,3,5,0,4,2,6,8,7};
    vector<int> arr2 = { 9,1,3,5,0,4,2,6,8,7 };
    int arrSize = arr.size();

    cout << "Arreglo original:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";

    quickSort(arr, 0, arrSize - 1, ascendente);
    mergeSort(arr2, 0, arrSize - 1, ascendente);


    cout << "Arreglo ordenado por quickSort:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "Arreglo ordenado por mergeSort:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr2[i] << " ";
    cout << "\n";

    quickSort(arr, 0, arrSize - 1, descendente);
    mergeSort(arr2, 0, arrSize - 1, descendente);

    cout << "Arreglo ordenado por quickSort descendente:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "Arreglo ordenado por mergeSort descendente:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr2[i] << " ";
    cout << "\n";


    return 0;
}
