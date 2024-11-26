#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <unordered_map>

struct TasaCambio {
    int origen, destino;
    double tasa;
};

double bellmanFord(const std::vector<TasaCambio>& tasas, int numMonedas, int nodoInicial, int nodoFinal,
                   std::unordered_map<int, double>& distancias) {
    if (nodoInicial == nodoFinal) {
        return 0.0; // Distancia a sí mismo es 0
    }

    int clave = nodoInicial * numMonedas + nodoFinal;
    if (distancias.find(clave) != distancias.end()) {
        return distancias[clave]; // Devolver el valor almacenado si existe
    }

    double mejorDistancia = std::numeric_limits<double>::infinity();
    for (const TasaCambio& tasa : tasas) {
        if (tasa.origen == nodoInicial) {
            double distanciaSiguiente = bellmanFord(tasas, numMonedas, tasa.destino, nodoFinal, distancias);
            double distanciaActual = std::log(tasa.tasa) + distanciaSiguiente;

            mejorDistancia = std::min(mejorDistancia, distanciaActual);
        }
    }

    distancias[clave] = mejorDistancia; // Almacenar el resultado parcial

    return mejorDistancia;
}

bool tieneCicloNegativo(const std::vector<TasaCambio>& tasas, int numMonedas) {
    std::unordered_map<int, double> distancias;

    for (int i = 0; i < numMonedas; ++i) {
        if (bellmanFord(tasas, numMonedas, i, i, distancias) < 0.0) {
            return true; // Ciclo negativo detectado
        }
    }

    return false; // No hay ciclo negativo
}

int main() {
    std::vector<TasaCambio> tasas = {
        {0, 1, 100.0 / 5600.0}, // Euro a Yen
        {1, 2, 9.0 / 400.0},     // Yen a Dólar
        {2, 0, 8.0 / 10.0}       // Dólar a Euro
    };

    int numMonedas = 3;

    if (tieneCicloNegativo(tasas, numMonedas)) {
        std::cout << "¡Existe una oportunidad de arbitraje!\n";
    } else {
        std::cout << "No hay oportunidades de arbitraje.\n";
    }

    return 0;
}
