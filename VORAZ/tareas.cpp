#include <iostream>
#include <vector>
#include <algorithm>

struct Tarea {
    int indice;
    int beneficio;
    int plazo;

    Tarea(int i, int b, int d) : indice(i), beneficio(b), plazo(d) {}
};

bool compararPorBeneficio(const Tarea& a, const Tarea& b) {
    return a.beneficio > b.beneficio;
}

void planificacionTareas(const std::vector<Tarea>& tareas) {
    std::vector<Tarea> tareasOrdenadas = tareas;
    std::sort(tareasOrdenadas.begin(), tareasOrdenadas.end(), compararPorBeneficio);

    std::vector<int> secuencia;
    std::vector<bool> candidatos(tareas.size(), true);

    for (const Tarea& tarea : tareasOrdenadas) {
        int indice = tarea.indice;

        for (std::size_t i = std::min(static_cast<std::size_t>(tareas.size()), static_cast<std::size_t>(tarea.plazo)) - 1; i >= 0; --i) {
            if (candidatos[i]) {
                secuencia.push_back(indice);
                candidatos[i] = false;
                break;
            }
        }
    }

    std::cout << "Secuencia de tareas seleccionadas: ";
    for (int indice : secuencia) {
        std::cout << indice << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Tarea> tareas = {{1, 10, 2}, {2, 5, 1}, {3, 7, 3}, {4, 20, 2}, {5, 15, 4}};

    planificacionTareas(tareas);

    return 0;
}
