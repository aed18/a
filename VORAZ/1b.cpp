#include <iostream>
#include <vector>
#include <algorithm>

struct Contenedor {
    int id;
    double peso;

    Contenedor(int i, double p) : id(i), peso(p) {}
};

bool compararPorPeso(const Contenedor& a, const Contenedor& b) {
    return a.peso > b.peso; // Ordenar de forma no decreciente
}

void maximizarToneladas(std::vector<Contenedor>& contenedores, double capacidadBuque) {
    std::sort(contenedores.begin(), contenedores.end(), compararPorPeso);

    double pesoCargado = 0.0;
    int contenedoresCargados = 0;

    for (const Contenedor& contenedor : contenedores) {
        if (pesoCargado + contenedor.peso <= capacidadBuque) {
            pesoCargado += contenedor.peso;
            contenedoresCargados++;
            std::cout << "Contenedor " << contenedor.id << " cargado." << std::endl;
        }
    }

    std::cout << "Total de contenedores cargados: " << contenedoresCargados << std::endl;
    std::cout << "Peso total cargado: " << pesoCargado << " toneladas." << std::endl;
}

int main() {
    // Ejemplo de uso
    double capacidadBuque = 10.0;
    std::vector<Contenedor> contenedores = {{1, 3.0}, {2, 2.5}, {3, 1.5}, {4, 4.0}};

    maximizarToneladas(contenedores, capacidadBuque);

    return 0;
}
