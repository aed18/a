#include <iostream>
using namespace std;

bool searchInSortedMatrix(int x, int **A, int startRow, int endRow, int startCol, int endCol) {
    if (startRow > endRow || startCol > endCol) {
        return false;
    }

    int midRow = (startRow + endRow) / 2;
    int midCol = (startCol + endCol) / 2;

    if (A[midRow][midCol] == x) {
        return true;
    } else if (A[midRow][midCol] > x) {
        // Buscar en la submatriz izquierda arriba y derecha abajo
        return searchInSortedMatrix(x, A, startRow, midRow - 1, startCol, endCol) ||
               searchInSortedMatrix(x, A, midRow, endRow, startCol, midCol - 1);
    } else {
        // Buscar en la submatriz derecha arriba y izquierda abajo
        return searchInSortedMatrix(x, A, startRow, midRow, midCol + 1, endCol) ||
               searchInSortedMatrix(x, A, midRow + 1, endRow, startCol, endCol);
    }
}

bool searchInPartiallyOrderedArray(int x, int **A, int n) {
    return searchInSortedMatrix(x, A, 0, n - 1, 0, n - 1);
}

int main() {
    int n = 4; // Tamaño del array bidimensional (ejemplo)

    // Ejemplo de un array parcialmente ordenado
    int **A = new int *[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }

    // Llenar el array (debe estar parcialmente ordenado)
    // Aquí puedes proporcionar tus propios valores para A

    int x = 7; // Elemento a buscar

    // Llamar a la función "divide y vencerás" para buscar el elemento
    bool result = searchInPartiallyOrderedArray(x, A, n);

    // Imprimir el resultado
    if (result) {
        cout << "El elemento " << x << " está presente en el array." << endl;
    } else {
        cout << "El elemento " << x << " no está presente en el array." << endl;
    }

    // Liberar memoria
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
