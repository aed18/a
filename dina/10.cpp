#include <iostream>
#include <vector>

// Estructura para representar un proyecto
struct Proyecto {
    int unidades;
    int beneficio;

    Proyecto(int u, int b) : unidades(u), beneficio(b) {}
};

// Función para calcular el beneficio máximo
int BeneficioMaximo(const std::vector<Proyecto>& proyectos, int n, int capacidadMochila) {
    // Inicializar una tabla para almacenar los resultados intermedios
    std::vector<std::vector<int>> tablaBeneficios(n + 1, std::vector<int>(capacidadMochila + 1, 0));

    // Calcular beneficios para cada combinación de proyectos y capacidad de mochila
    for (int i = 1; i <= n; ++i) {
        for (int capacidad = 1; capacidad <= capacidadMochila; ++capacidad) {
            // Inicializar con el beneficio anterior
            tablaBeneficios[i][capacidad] = tablaBeneficios[i - 1][capacidad];

            // Actualizar si se encuentra un beneficio mejor
            if (proyectos[i - 1].unidades <= capacidad) {
                tablaBeneficios[i][capacidad] = std::max(tablaBeneficios[i][capacidad],
                                                         tablaBeneficios[i - 1][capacidad - proyectos[i - 1].unidades] + proyectos[i - 1].beneficio);
            }
        }
    }

    // El resultado final estará en la esquina inferior derecha de la tabla
    return tablaBeneficios[n][capacidadMochila];
}

int main() {
    // Ejemplo de uso
    int n = 3;  // Número de proyectos
    int capacidadMochila = 5;  // Capacidad total de la mochila

    // Representación de proyectos (unidades, beneficio)
    std::vector<Proyecto> proyectos = {{2, 10}, {1, 8}, {3, 15}};

    // Calcular y mostrar el beneficio máximo
    int beneficioMaximo = BeneficioMaximo(proyectos, n, capacidadMochila);
    std::cout << "Beneficio máximo: " << beneficioMaximo << std::endl;

    return 0;
}
