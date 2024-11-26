#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> secuenciaCrecienteMaxima(const std::vector<int>& V) {
    int n = V.size();
    std::vector<int> longitud(n, 1); // Inicializar todas las longitudes como 1

    // Calcular la longitud de la secuencia creciente de máxima longitud
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (V[i] > V[j] && longitud[i] < longitud[j] + 1) {
                longitud[i] = longitud[j] + 1;
            }
        }
    }

    // Encontrar la posición del último elemento de la secuencia creciente de máxima longitud
    int maxLongitud = longitud[0];
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (longitud[i] > maxLongitud) {
            maxLongitud = longitud[i];
            maxIndex = i;
        }
    }

    // Reconstruir la secuencia creciente de máxima longitud
    std::vector<int> secuencia;
    int actualLongitud = maxLongitud;
    for (int i = maxIndex; i >= 0; --i) {
        if (longitud[i] == actualLongitud) {
            secuencia.push_back(V[i]);
            --actualLongitud;
        }
    }

    // La secuencia construida está en orden inverso, así que la invertimos
    std::reverse(secuencia.begin(), secuencia.end());

    return secuencia;
}

int main() {
    std::vector<int> V = {11, 17, 5, 8, 6, 4, 7, 12, 3};

    std::vector<int> resultado = secuenciaCrecienteMaxima(V);

    std::cout << "Secuencia creciente de máxima longitud: ";
    for (int num : resultado) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
