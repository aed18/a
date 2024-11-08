#include <iostream>
#include <vector>
#include <algorithm>

struct Clase {
    int inicio;
    int final;

    Clase(int i, int f) : inicio(i), final(f) {}
};

struct Aula {
    int finDisponibilidad;

    Aula() : finDisponibilidad(0) {}
};

// Función para comparar clases por hora de finalización
bool compararPorHoraFinal(const Clase& a, const Clase& b) {
    return a.final < b.final;
}

// Función para asignar una clase a un aula disponible
void asignarAula(Clase& clase, Aula& aula) {
    std::cout << "Asignar clase (" << clase.inicio << "-" << clase.final << ") al aula (" << aula.finDisponibilidad << ")\n";
    aula.finDisponibilidad = clase.final;
}

// Función para optimizar el uso de aulas
std::vector<std::pair<Clase, Aula>> optimizarAulas(const std::vector<Clase>& clases) {
    // Ordenar las clases por hora de finalización
    std::vector<Clase> clasesOrdenadas = clases;
    std::sort(clasesOrdenadas.begin(), clasesOrdenadas.end(), compararPorHoraFinal);

    // Vector para representar aulas ocupadas
    std::vector<Aula> aulasOcupadas;

    // Vector para almacenar asignaciones de clases a aulas
    std::vector<std::pair<Clase, Aula>> asignaciones;

    // Para cada clase en el conjunto ordenado
    for (const Clase& clase : clasesOrdenadas) {
        // Buscar un aula disponible
        auto aulaDisponible = std::find_if(aulasOcupadas.begin(), aulasOcupadas.end(),
            [&](const Aula& aula) { return aula.finDisponibilidad <= clase.inicio; });

        if (aulaDisponible != aulasOcupadas.end()) {
            // Asignar la clase a un aula existente
            asignarAula(const_cast<Clase&>(clase), *aulaDisponible);
            asignaciones.emplace_back(clase, *aulaDisponible);
        } else {
            // Asignar una nueva aula y la clase
            Aula nuevaAula;
            asignarAula(const_cast<Clase&>(clase), nuevaAula);
            asignaciones.emplace_back(clase, nuevaAula);
            aulasOcupadas.push_back(nuevaAula);
        }
    }

    // Devolver la lista de asignaciones
    return asignaciones;
}

int main() {
    // Ejemplo de uso
    std::vector<Clase> clases = {{1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}};

    std::vector<std::pair<Clase, Aula>> resultado = optimizarAulas(clases);

    return 0;
}
