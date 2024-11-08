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

void maximizarPropinasConCamareros(std::vector<Cliente>& clientes, int k) {
    std::sort(clientes.begin(), clientes.end(), compararPorTiempoEspera);

    std::vector<int> tiempoAsignado(k, 0); // Tiempo asignado a cada camarero

    for (const Cliente& cliente : clientes) {
        int camarero = std::min_element(tiempoAsignado.begin(), tiempoAsignado.end()) - tiempoAsignado.begin();
        tiempoAsignado[camarero] += cliente.tiempoEspera;

        std::cout << "Camarero " << camarero + 1 << " atiende al cliente " << cliente.id << " con tiempo de espera " << cliente.tiempoEspera << std::endl;
    }
}

int main() {
    // Ejemplo de uso
    std::vector<Cliente> clientes = {{1, 5}, {2, 2}, {3, 8}, {4, 1}};
    int k = 2; // Número de camareros

    maximizarPropinasConCamareros(clientes, k);

    return 0;
}
