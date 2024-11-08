#include <iostream>
#include <vector>
#include <unordered_set>

struct Arista {
    int nodo1;
    int nodo2;

    Arista(int u, int v) : nodo1(u), nodo2(v) {}
};

std::unordered_set<int> recubrimientoGreedy(std::vector<Arista>& aristas) {
    std::unordered_set<int> recubrimiento;
    
    while (!aristas.empty()) {
        // Seleccionar arista que aún no está cubierta
        const Arista& arista = aristas.back();
        aristas.pop_back();

        // Agregar ambos extremos al recubrimiento
        recubrimiento.insert(arista.nodo1);
        recubrimiento.insert(arista.nodo2);
    }

    return recubrimiento;
}

int main() {
    // Ejemplo de uso
    std::vector<Arista> aristas = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}};

    std::unordered_set<int> recubrimiento = recubrimientoGreedy(aristas);

    std::cout << "Recubrimiento: ";
    for (int nodo : recubrimiento) {
        std::cout << nodo << " ";
    }
    std::cout << std::endl;

    return 0;
}
