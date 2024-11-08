#include <iostream>
#include <vector>
#include <algorithm>

struct Licencia {
    int id;
    double tasaIncremento;

    Licencia(int i, double delta) : id(i), tasaIncremento(delta) {}
};

// Función de comparación para ordenar las licencias por tasaIncremento de forma ascendente
bool compararPorIncremento(const Licencia& a, const Licencia& b) {
    return a.tasaIncremento < b.tasaIncremento;
}

// Algoritmo Greedy para minimizar el coste de adquisición de las licencias
double costoMinimoLicencias(const std::vector<Licencia>& licencias, int n) {
    std::sort(licencias.begin(), licencias.end(), compararPorIncremento);

    double costoTotal = 0.0;
    double factor = 1.0;

    for (int i = 0; i < n; ++i) {
        costoTotal += 100.0 * factor;
        factor *= (1.0 + licencias[i].tasaIncremento);
    }

    return costoTotal;
}

int main() {
    // Ejemplo de uso
    int n = 5; // Número de licencias
    std::vector<Licencia> licencias = {{1, 0.02}, {2, 0.01}, {3, 0.03}, {4, 0.05}, {5, 0.04}};

    double costoTotal = costoMinimoLicencias(licencias, n);

    std::cout << "Costo total mínimo de adquisición de las licencias: " << costoTotal << " €\n";

    return 0;
}
