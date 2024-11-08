#include <iostream>
#include <vector>
#include <algorithm>

struct Cliente {
    int id;
    int tiempoEspera;

    Cliente(int i, int t) : id(i), tiempoEspera(t) {}
};

bool compararPorTiempoEspera(const Cliente& a, const Cliente& b) {
    return a.tiempoEspera < b.tiempoEspera; // Ordenar de forma no decreciente por tiempo de espera
}

void maximizarGananciasCamarero(std::vector<Cliente>& clientes) {
    std::sort(clientes.begin(), clientes.end(), compararPorTiempoEspera);

    int gananciasTotales = 0;

    for (const Cliente& cliente : clientes) {
        gananciasTotales += 1 / static_cast<double>(cliente.tiempoEspera);
        std::cout << "Camarero atiende al cliente " << cliente.id << " con tiempo de espera " << cliente.tiempoEspera << std::endl;
    }

    std::cout << "Ganancias totales: " << gananciasTotales << std::endl;
}

int main() {
    // Ejemplo de uso
    std::vector<Cliente> clientes = {{1, 5}, {2, 2}, {3, 8}, {4, 1}};

    maximizarGananciasCamarero(clientes);

    return 0;
}
