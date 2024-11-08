#include <iostream>
#include <vector>

struct Gasolinera {
    int distancia;
    int capacidad;

    Gasolinera(int d, int c) : distancia(d), capacidad(c) {}
};

// Función para determinar en qué gasolineras repostar
std::vector<int> seleccionarGasolineras(const std::vector<Gasolinera>& gasolineras, int autonomia) {
    std::vector<int> gasolinerasSeleccionadas;
    int distanciaRecorrida = 0;

    for (const auto& gasolinera : gasolineras) {
        // Verificar si es necesario repostar en la gasolinera actual
        if (gasolinera.distancia - distanciaRecorrida > autonomia) {
            gasolinerasSeleccionadas.push_back(gasolinera.distancia);
            distanciaRecorrida = gasolinera.distancia;
        }
    }

    return gasolinerasSeleccionadas;
}

int main() {
    // Ejemplo de uso
    std::vector<Gasolinera> gasolineras = {{100, 50}, {200, 20}, {300, 60}, {400, 30}, {500, 25}};
    int autonomia = 150;

    std::vector<int> gasolinerasSeleccionadas = seleccionarGasolineras(gasolineras, autonomia);

    std::cout << "Repostar en las gasolineras en las siguientes distancias:\n";
    for (int distancia : gasolinerasSeleccionadas) {
        std::cout << distancia << " ";
    }
    std::cout << "\n";

    return 0;
}
