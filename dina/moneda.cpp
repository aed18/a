#include <iostream>
#include <vector>
#include <climits>

std::vector<int> encontrarCambioMinimo(const std::vector<int>& denominaciones, int cantidad) {
    int n = denominaciones.size();

    // Tabla para almacenar la cantidad mínima de monedas para cada cantidad
    std::vector<int> tabla(cantidad + 1, INT_MAX);

    // Caso base: se necesita 0 monedas para hacer cambio de 0
    tabla[0] = 0;

    // Calcular la cantidad mínima de monedas para cada cantidad
    for (int i = 1; i <= cantidad; ++i) {
        for (int j = 0; j < n; ++j) {
            if (denominaciones[j] <= i) {
                int subproblema = tabla[i - denominaciones[j]];
                if (subproblema != INT_MAX && subproblema + 1 < tabla[i]) {
                    tabla[i] = subproblema + 1;
                }
            }
        }
    }

    // Reconstruir la solución
    std::vector<int> solucion;
    int i = cantidad;
    while (i > 0) {
        for (int j = 0; j < n; ++j) {
            if (i - denominaciones[j] >= 0 && tabla[i] == tabla[i - denominaciones[j]] + 1) {
                solucion.push_back(denominaciones[j]);
                i -= denominaciones[j];
                break;
            }
        }
    }

    return solucion;
}

int main() {
    std::vector<int> denominaciones = {1, 2, 5, 10, 20, 50, 100, 200};
    int cantidad = 126;

    std::vector<int> cambio = encontrarCambioMinimo(denominaciones, cantidad);

    std::cout << "Cantidad mínima de monedas: " << cambio.size() << "\n";
    std::cout << "Monedas utilizadas: ";
    for (int moneda : cambio) {
        std::cout << moneda << " ";
    }
    std::cout << "\n";

    return 0;
}
