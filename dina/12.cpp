#include <iostream>
#include <vector>
#include <algorithm>

// Estructura para representar las estaciones de una cadena de montaje
struct CadenaMontaje {
    int n; // Número de estaciones
    std::vector<std::vector<int>> tiempos; // Matriz de tiempos
    std::vector<int> tiemposCambio; // Tiempos de cambio de una cadena a otra
    std::vector<int> tiemposSalida; // Tiempos de salida de cada cadena
};

// Función para encontrar la ruta óptima a través de las estaciones
std::vector<int> RutaOptima(const CadenaMontaje& cadena1, const CadenaMontaje& cadena2) {
    int n = cadena1.n;

    // Inicializar matrices de costos y rutas
    std::vector<std::vector<int>> costos(2, std::vector<int>(n, 0));
    std::vector<std::vector<int>> rutas(2, std::vector<int>(n, 0));

    // Inicializar el primer costo y ruta
    costos[0][0] = cadena1.tiempos[0][0];
    costos[1][0] = cadena2.tiempos[0][0];

    // Rellenar las matrices de costos y rutas
    for (int j = 1; j < n; ++j) {
        // Costos para permanecer en la misma cadena
        int costoPermanecer1 = costos[0][j - 1] + cadena1.tiempos[0][j];
        int costoPermanecer2 = costos[1][j - 1] + cadena2.tiempos[1][j];

        // Costos para cambiar de cadena
        int costoCambiarA1 = costos[1][j - 1] + cadena2.tiempos[1][j] + cadena1.tiemposCambio[j];
        int costoCambiarA2 = costos[0][j - 1] + cadena1.tiempos[0][j] + cadena2.tiemposCambio[j];

        // Actualizar costos y rutas
        if (costoPermanecer1 <= costoCambiarA1) {
            costos[0][j] = costoPermanecer1;
            rutas[0][j] = 0;
        } else {
            costos[0][j] = costoCambiarA1;
            rutas[0][j] = 1;
        }

        if (costoPermanecer2 <= costoCambiarA2) {
            costos[1][j] = costoPermanecer2;
            rutas[1][j] = 1;
        } else {
            costos[1][j] = costoCambiarA2;
            rutas[1][j] = 0;
        }
    }

    // Encontrar la cadena con el menor tiempo de salida
    int costoFinalCadena1 = costos[0][n - 1] + cadena1.tiemposSalida[0];
    int costoFinalCadena2 = costos[1][n - 1] + cadena2.tiemposSalida[1];

    std::vector<int> rutaOptima;

    if (costoFinalCadena1 <= costoFinalCadena2) {
        // Construir la ruta óptima para la cadena 1
        int j = n - 1;
        rutaOptima.push_back(0); // Cadena 1

        while (j > 0) {
            rutaOptima.push_back(rutas[0][j]);
            --j;
        }
    } else {
        // Construir la ruta óptima para la cadena 2
        int j = n - 1;
        rutaOptima.push_back(1); // Cadena 2

        while (j > 0) {
            rutaOptima.push_back(rutas[1][j]);
            --j;
        }
    }

    std::reverse(rutaOptima.begin(), rutaOptima.end()); // Invertir la ruta

    return rutaOptima;
}

int main() {
    // Ejemplo de uso
    CadenaMontaje cadena1, cadena2;
    cadena1.n = cadena2.n = 4;

    cadena1.tiempos = {
        {4, 5, 3, 2},
        {2, 10, 1, 4}
    };

    cadena1.tiemposCambio = {0, 7, 0, 9};
    cadena1.tiemposSalida = {18, 7};

    cadena2.tiempos = {
        {10, 6, 8, 3},
        {6, 3, 2, 4}
    };

    cadena2.tiemposCambio = {0, 8, 0, 6};
    cadena2.tiemposSalida = {16, 9};

    std::vector<int> rutaOptima = RutaOptima(cadena1, cadena2);

    // Imprimir la ruta óptima
    std::cout << "Ruta óptima: ";
    for (int i : rutaOptima) {
        std::cout << i + 1 << " "; // Ajustar índices para imprimir
    }
    std::cout << std::endl;

    return 0;
}
