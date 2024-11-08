#include <iostream>
#include <vector>

using namespace std;

// Función para combinar dos arrays ordenados
vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> result(n1 + n2);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copiar los elementos restantes de arr1, si los hay
    while (i < n1) {
        result[k++] = arr1[i++];
    }

    // Copiar los elementos restantes de arr2, si los hay
    while (j < n2) {
        result[k++] = arr2[j++];
    }

    return result;
}

// Función principal para combinar k arrays utilizando "divide y vencerás"
vector<int> mergeKArrays(const vector<vector<int>>& arrays, int start, int end) {
    if (start == end) {
        return arrays[start];
    }

    int mid = start + (end - start) / 2;

    // Recursivamente combinar las mitades izquierda y derecha
    vector<int> left = mergeKArrays(arrays, start, mid);
    vector<int> right = mergeKArrays(arrays, mid + 1, end);

    // Combinar las dos mitades
    return mergeArrays(left, right);
}

int main() {
    // Ejemplo de uso
    vector<vector<int>> arrays = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    int k = arrays.size();

    // Combinar los k arrays
    vector<int> result = mergeKArrays(arrays, 0, k - 1);

    // Imprimir el resultado combinado
    cout << "Array combinado: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
