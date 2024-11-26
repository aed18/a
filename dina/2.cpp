#include <iostream>
#include <vector>
#include <unordered_map>

// Definición de la relación de orden
bool precede(char x, char y) {
    // Aquí deberías implementar la lógica de la relación de orden Φ.
    // Por ejemplo, podrías utilizar una tabla de búsqueda para definir el orden.
    // Este es un ejemplo simple que asume un orden lexicográfico estándar.

    return x < y;
}

// Función para determinar si u precede a v en el orden Φ
bool precedeEnOrden(char u, char v, const std::unordered_map<char, int>& indice) {
    return precede(u, v);
}

// Función principal que utiliza programación dinámica
bool determinarOrden(const std::string& alfabeto, char u, char v) {
    int n = alfabeto.size();

    // Construir un índice para mapear cada carácter a un índice en la matriz DP
    std::unordered_map<char, int> indice;
    for (int i = 0; i < n; ++i) {
        indice[alfabeto[i]] = i;
    }

    // Inicializar la matriz DP
    std::vector<std::vector<bool>> DP(n, std::vector<bool>(n, false));

    // Llenar la matriz DP usando programación dinámica
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || precedeEnOrden(alfabeto[i], alfabeto[j], indice)) {
                DP[i][j] = true;
            } else {
                for (int k = 0; k < n; ++k) {
                    DP[i][j] = DP[i][j] || (DP[i][k] && DP[k][j]);
                }
            }
        }
    }

    // El resultado final está en DP[indice[u]][indice[v]]
    return DP[indice[u]][indice[v]];
}

int main() {
    std::string alfabeto = "abcd";
    char u = 'a';
    char v = 'c';

    if (determinarOrden(alfabeto, u, v)) {
        std::cout << u << " precede a " << v << " en el orden Φ.\n";
    } else {
        std::cout << u << " no precede a " << v << " en el orden Φ.\n";
    }

    return 0;
}
