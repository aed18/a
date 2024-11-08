#include <iostream>
#include <vector>

// Mueve la declaración de denominaciones al ámbito global
const std::vector<double> denominaciones = {1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};

std::vector<int> devolverCambio(double monto) {
    std::vector<int> cantidadMonedas(denominaciones.size(), 0);

    for (size_t i = 0; i < denominaciones.size(); ++i) {
        while (monto >= denominaciones[i]) {
            monto -= denominaciones[i];
            ++cantidadMonedas[i];
        }
    }

    return cantidadMonedas;
}

int main() {
    double montoCompra, montoPago;
    std::cout << "Ingrese el monto de la compra: ";
    std::cin >> montoCompra;
    std::cout << "Ingrese el monto pagado: ";
    std::cin >> montoPago;

    double cambio = montoPago - montoCompra;

    if (cambio < 0) {
        std::cout << "Error: El monto pagado es insuficiente.\n";
        return 1;
    }

    std::vector<int> cantidadMonedas = devolverCambio(cambio);

    std::cout << "Cambio devuelto:\n";
    for (size_t i = 0; i < cantidadMonedas.size(); ++i) {
        if (cantidadMonedas[i] > 0) {
            std::cout << cantidadMonedas[i] << " moneda(s) de " << denominaciones[i] << " euro(s)\n";
        }
    }

    return 0;
}
