#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> cambioMonedas(const std::vector<int>& denominaciones, int cantidad) {
    std::vector<int> solucion;

    // Ordenar las denominaciones de mayor a menor
    std::vector<int> denominacionesOrdenadas = denominaciones;
    std::sort(denominacionesOrdenadas.rbegin(), denominacionesOrdenadas.rend());

    // Encontrar el cambio usando denominaciones de mayor a menor
    for (int i = 0; i < denominacionesOrdenadas.size(); ++i) {
        while (cantidad >= denominacionesOrdenadas[i]) {
            solucion.push_back(denominacionesOrdenadas[i]);
            cantidad -= denominacionesOrdenadas[i];
        }
    }

    return solucion;
}

int main() {
    std::vector<int> denominaciones = {1, 2, 5, 10, 20, 50, 100, 200};
    int cantidad = 134;

    std::vector<int> resultado = cambioMonedas(denominaciones, cantidad);

    std::cout << "Cambio para " << cantidad << " euros: ";
    for (int moneda : resultado) {
        std::cout << moneda << " ";
    }
    std::cout << std::endl;

    return 0;
}
