#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Cliente {
    int id;
    std::vector<double> caracteristicas;

    Cliente(int i, const std::vector<double>& feats) : id(i), caracteristicas(feats) {}
};

// Función para calcular la distancia euclidiana entre dos vectores de características
double calcularDistancia(const std::vector<double>& v1, const std::vector<double>& v2) {
    double distancia = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        distancia += std::pow(v1[i] - v2[i], 2);
    }
    return std::sqrt(distancia);
}

// Función para asignar cada cliente al grupo más cercano (basado en centroides)
void asignarClientesAGrupos(const std::vector<Cliente>& clientes, const std::vector<std::vector<double>>& centroides, std::vector<int>& asignaciones) {
    for (size_t i = 0; i < clientes.size(); ++i) {
        double distanciaMinima = std::numeric_limits<double>::max();
        int grupoAsignado = -1;

        for (size_t j = 0; j < centroides.size(); ++j) {
            double distancia = calcularDistancia(clientes[i].caracteristicas, centroides[j]);
            if (distancia < distanciaMinima) {
                distanciaMinima = distancia;
                grupoAsignado = static_cast<int>(j);
            }
        }

        asignaciones[i] = grupoAsignado;
    }
}

// Función para recalcular los centroides de los grupos
void recalcularCentroides(const std::vector<Cliente>& clientes, const std::vector<int>& asignaciones, std::vector<std::vector<double>>& centroides) {
    std::vector<std::vector<double>> sumas(clientes[0].caracteristicas.size(), std::vector<double>(centroides.size(), 0.0));
    std::vector<int> conteo(centroides.size(), 0);

    for (size_t i = 0; i < clientes.size(); ++i) {
        int grupo = asignaciones[i];
        for (size_t j = 0; j < clientes[i].caracteristicas.size(); ++j) {
            sumas[j][grupo] += clientes[i].caracteristicas[j];
        }
        ++conteo[grupo];
    }

    for (size_t i = 0; i < centroides.size(); ++i) {
        for (size_t j = 0; j < centroides[i].size(); ++j) {
            centroides[i][j] = (conteo[i] > 0) ? sumas[j][i] / conteo[i] : 0.0;
        }
    }
}

// Algoritmo k-medias para agrupar clientes en K grupos
std::vector<std::vector<int>> kMedias(const std::vector<Cliente>& clientes, int k, int maxIteraciones) {
    // Inicializar centroides de forma aleatoria
    std::vector<std::vector<double>> centroides(k);
    for (int i = 0; i < k; ++i) {
        centroides[i] = clientes[i].caracteristicas;
    }

    // Vector para almacenar asignaciones de clientes a grupos
    std::vector<int> asignaciones(clientes.size(), -1);

    // Iteraciones del algoritmo
    for (int iteracion = 0; iteracion < maxIteraciones; ++iteracion) {
        // Asignar cada cliente al grupo más cercano
        asignarClientesAGrupos(clientes, centroides, asignaciones);

        // Recalcular centroides de los grupos
        recalcularCentroides(clientes, asignaciones, centroides);
    }

    // Almacenar resultados en un vector de vectores (grupos)
    std::vector<std::vector<int>> grupos(k);
    for (size_t i = 0; i < clientes.size(); ++i) {
        grupos[asignaciones[i]].push_back(clientes[i].id);
    }

    return grupos;
}

int main() {
    // Ejemplo de uso
    std::vector<Cliente> clientes = {{1, {1.0, 2.0}}, {2, {2.0, 3.0}}, {3, {5.0, 8.0}}, {4, {7.0, 6.0}}};

    int k = 2;  // Número de grupos
    int maxIteraciones = 100;  // Número máximo de iteraciones

    std::vector<std::vector<int>> grupos = kMedias(clientes, k, maxIteraciones);

    // Imprimir resultados
    std::cout << "Grupos resultantes:\n";
    for (int i = 0; i < k; ++i) {
        std::cout << "Grupo " << i + 1 << ": ";
        for (int clienteId : grupos[i]) {
            std::cout << "Cliente " << clienteId << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
