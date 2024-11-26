#include <iostream>
#include <vector>

using namespace std;

// Función para intercambiar dos caracteres en un vector
void intercambiar(vector<char>& letras, int i, int j) {
    char temp = letras[i];
    letras[i] = letras[j];
    letras[j] = temp;
}

// Función principal de backtracking para generar permutaciones
void generarPermutaciones(vector<char>& letras, int m, int inicio) {
    if (m == 0) {
        // Imprimir la permutación actual
        for (int i = 0; i < letras.size(); ++i) {
            cout << letras[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = inicio; i < letras.size(); ++i) {
        // Intercambiar letras[i] con letras[inicio]
        intercambiar(letras, i, inicio);

        // Llamada recursiva para la siguiente posición
        generarPermutaciones(letras, m - 1, inicio + 1);

        // Deshacer el intercambio para probar con otras combinaciones
        intercambiar(letras, i, inicio);
    }
}

int main() {
    int n, m;
    cout << "Ingrese el número de letras distintas (n): ";
    cin >> n;

    cout << "Ingrese el valor de m (2 <= m <= n): ";
    cin >> m;

    if (m < 2 || m > n) {
        cout << "El valor de m no es válido." << endl;
        return 1;
    }

    vector<char> letras;
    for (int i = 0; i < n; ++i) {
        char letra;
        cout << "Ingrese la letra " << (i + 1) << ": ";
        cin >> letra;
        letras.push_back(letra);
    }

    cout << "Permutaciones de " << m << " letras entre las " << n << " dadas:" << endl;
    generarPermutaciones(letras, m, 0);

    return 0;
}
