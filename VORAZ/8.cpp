#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Ciudad {
    int id;
    double x, y; // Coordenadas euclidianas
};

struct Conexion {
    int ciudad1, ciudad2;
    double distancia;

    Conexion(int c1, int c2, double dist) : ciudad1(c1), ciudad2(c2), distancia(dist) {}
};

// Función para calcular la distancia euclidiana entre dos ciudades
double calcularDistancia(const Ciudad& c1, const Ciudad& c2) {
    return std::sqrt(std::pow(c2.x - c1.x, 2) + std::pow(c2.y - c1.y, 2));
}

// Función para comparar conexiones por distancia
bool compararConexiones(const Conexion& c1, const Conexion& c2) {
    return c1.distancia < c2.distancia;
}

// Función principal para construir la red de fibra óptica
std::vector<Conexion> construirRedOptica(const std::vector<Ciudad>& ciudades) {
    int n = ciudades.size();
    std::vector<Conexion> conexiones;

    // Calcular todas las distancias entre ciudades y almacenarlas en conexiones
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double distancia = calcularDistancia(ciudades[i], ciudades[j]);
            conexiones.emplace_back(i, j, distancia);
        }
    }

    // Ordenar conexiones por distancia de menor a mayor
    std::sort(conexiones.begin(), conexiones.end(), compararConexiones);

    // Inicializar conjuntos disjuntos (puedes usar Union-Find para mejorar la eficiencia)
    std::vector<int> conjuntos(n);
    for (int i = 0; i < n; ++i) {
        conjuntos[i] = i;
    }

    std::vector<Conexion> redOptica;

    // Construir la red de fibra óptica sin crear ciclos
    for (const Conexion& conexion : conexiones) {
        int conjunto1 = conjuntos[conexion.ciudad1];
        int conjunto2 = conjuntos[conexion.ciudad2];

        if (conjunto1 != conjunto2) {
            // Agregar conexión al árbol de expansión mínima
            redOptica.push_back(conexion);

            // Fusionar conjuntos
            for (int i = 0; i < n; ++i) {
                if (conjuntos[i] == conjunto2) {
                    conjuntos[i] = conjunto1;
                }
            }
        }
    }

    return redOptica;
}

int main() {
    std::vector<Ciudad> ciudades = {{0, 0, 0}, {1, 1, 0}, {2, 0, 1}, {3, 2, 1}};

    std::vector<Conexion> redOptica = construirRedOptica(ciudades);

    // Imprimir conexiones en la red de fibra óptica
    std::cout << "Conexiones en la red de fibra óptica:\n";
    for (const Conexion& conexion : redOptica) {
        std::cout << "Ciudad " << conexion.ciudad1 << " - Ciudad " << conexion.ciudad2 << " (Distancia: " << conexion.distancia << ")\n";
    }

    return 0;
}
