#include <iostream>
#include <vector>
#include <algorithm>

struct Programa {
    int id;
    int espacio;

    Programa(int i, int s) : id(i), espacio(s) {}
};

bool compararPorEspacio(const Programa& a, const Programa& b) {
    return a.espacio < b.espacio; // Ordenar de forma no decreciente
}

void maximizarProgramas(std::vector<Programa>& programas, int capacidadDisco) {
    std::sort(programas.begin(), programas.end(), compararPorEspacio);

    int espacioUsado = 0;
    int programasAlmacenados = 0;

    for (const Programa& programa : programas) {
        if (espacioUsado + programa.espacio <= capacidadDisco) {
            espacioUsado += programa.espacio;
            programasAlmacenados++;
            std::cout << "Programa " << programa.id << " almacenado." << std::endl;
        }
    }

    std::cout << "Total de programas almacenados: " << programasAlmacenados << std::endl;
}

int main() {
    // Ejemplo de uso
    int capacidadDisco = 15;
    std::vector<Programa> programas = {{1, 5}, {2, 8}, {3, 3}, {4, 6}};

    maximizarProgramas(programas, capacidadDisco);

    return 0;
}
