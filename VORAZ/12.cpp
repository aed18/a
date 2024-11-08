#include <iostream>
#include <vector>
#include <algorithm>

struct Tarea {
    int inicio;
    int duracion;
    int deadline;

    Tarea(int s, int t, int d) : inicio(s), duracion(t), deadline(d) {}
};

// Función para comparar tareas por deadline
bool compararPorDeadline(const Tarea& a, const Tarea& b) {
    return a.deadline < b.deadline;
}

// Algoritmo greedy para minimizar el retraso máximo
int minimizarRetrasoMaximo(std::vector<Tarea>& tareas) {
    int retrasoMaximo = 0;
    int tiempoActual = 0;

    // Ordenar tareas por deadline
    std::sort(tareas.begin(), tareas.end(), compararPorDeadline);

    // Calcular el retraso para cada tarea
    for (const Tarea& tarea : tareas) {
        tiempoActual += tarea.duracion;
        int retraso = std::max(0, tiempoActual - tarea.deadline);
        retrasoMaximo = std::max(retrasoMaximo, retraso);
    }

    return retrasoMaximo;
}

int main() {
    // Ejemplo de uso
    std::vector<Tarea> tareas = {{0, 3, 5}, {2, 4, 7}, {4, 2, 8}, {5, 5, 10}};

    int retraso = minimizarRetrasoMaximo(tareas);

    std::cout << "Retraso máximo: " << retraso << std::endl;

    return 0;
}
