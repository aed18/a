#include <iostream>
#include <vector>
#include <queue>
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

struct Element {
    int value;
    int arrayIndex;
    int elementIndex;
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKArrays(const vector<vector<int>>& arrays) {
    int k = arrays.size();
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> result;

    // Inserta el primer elemento de cada array en el min-heap
    for (int i = 0; i < k; i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Extrae el mínimo y agrega el siguiente elemento del mismo array al min-heap
    while (!minHeap.empty()) {
        Element minElement = minHeap.top();
        minHeap.pop();
        result.push_back(minElement.value);

        // Inserta el siguiente elemento del mismo array si existe
        if (minElement.elementIndex + 1 < arrays[minElement.arrayIndex].size()) {
            minHeap.push({arrays[minElement.arrayIndex][minElement.elementIndex + 1], 
                          minElement.arrayIndex, 
                          minElement.elementIndex + 1});
        }
    }

    return result;
}

int main() {
    // Ejemplo de entrada
    vector<vector<int>> arrays = {{1, 5, 9}, {2, 6, 8}, {3, 7, 10}};
    vector<int> result = mergeKArrays(arrays);

    // Imprime el array combinado
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


