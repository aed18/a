#include <iostream>
#include <vector>
#include <algorithm>

struct Tarea {
    int id;
    int beneficio;
    int plazoLimite;

    Tarea(int i, int g, int d) : id(i), beneficio(g), plazoLimite(d) {}
};

bool compararPorBeneficio(const Tarea& a, const Tarea& b) {
    return a.beneficio > b.beneficio; // Ordenar de forma no decreciente por beneficio
}

void maximizarBeneficio(std::vector<Tarea>& tareas) {
    std::sort(tareas.begin(), tareas.end(), compararPorBeneficio);

    int tiempoRestante = tareas.size();
    int beneficioTotal = 0;

    for (const Tarea& tarea : tareas) {
        if (tiempoRestante >= tarea.plazoLimite) {
            beneficioTotal += tarea.beneficio;
            tiempoRestante--;
            std::cout << "Realizada tarea " << tarea.id << " con beneficio " << tarea.beneficio << std::endl;
        }
    }

    std::cout << "Beneficio total: " << beneficioTotal << std::endl;
}

int main() {
    // Ejemplo de uso
    std::vector<Tarea> tareas = {{1, 50, 2}, {2, 10, 1}, {3, 15, 2}, {4, 30, 1}};

    maximizarBeneficio(tareas);

    return 0;
}
