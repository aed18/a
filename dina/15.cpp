#include <iostream>
#include <vector>
#include <limits>

struct NodoABB {
    int clave;
    double probabilidad;
    NodoABB* izquierda;
    NodoABB* derecha;

    NodoABB(int k, double p) : clave(k), probabilidad(p), izquierda(nullptr), derecha(nullptr) {}
};

// Función para encontrar el ABB óptimo utilizando programación dinámica
NodoABB* construirABBOptimo(const std::vector<int>& claves, const std::vector<double>& probabilidades) {
    int n = claves.size();

    // Crear tablas para almacenar los costos y raíces óptimas
    std::vector<std::vector<double>> costos(n + 1, std::vector<double>(n + 1, 0.0));
    std::vector<std::vector<int>> raices(n, std::vector<int>(n, 0));

    // Calcular costos óptimos
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            costos[i][j] = std::numeric_limits<double>::infinity();

            for (int r = i; r <= j; ++r) {
                double costo = (r > i ? costos[i][r - 1] : 0.0) +
                               (r < j ? costos[r + 1][j] : 0.0) +
                               probabilidades[r];

                if (costo < costos[i][j]) {
                    costos[i][j] = costo;
                    raices[i][j] = r;
                }
            }
        }
    }

    // Construir el ABB óptimo utilizando las raíces calculadas
    std::vector<NodoABB*> nodos(n, nullptr);

    for (int k = 0; k < n; ++k) {
        nodos[k] = new NodoABB(claves[k], probabilidades[k]);
    }

    for (int k = 0; k < n; ++k) {
        int i = 0;
        int j = n - 1;
        int r = raices[i][j];

        while (r != k) {
            if (k < r) {
                j = r - 1;
            } else {
                i = r + 1;
            }
            r = raices[i][j];
        }

        nodos[k]->izquierda = (r > i ? nodos[i + (r - i) / 2] : nullptr);
        nodos[k]->derecha = (r < j ? nodos[r + (j - r) / 2] : nullptr);
    }

    return nodos[raices[0][n - 1]];
}

// Función auxiliar para imprimir el ABB en orden
void imprimirEnOrden(NodoABB* raiz) {
    if (raiz) {
        imprimirEnOrden(raiz->izquierda);
        std::cout << "Clave: " << raiz->clave << ", Probabilidad: " << raiz->probabilidad << "\n";
        imprimirEnOrden(raiz->derecha);
    }
}

int main() {
    std::vector<int> claves = {1, 2, 3, 4, 5};
    std::vector<double> probabilidades = {0.25, 0.20, 0.05, 0.20, 0.30};

    NodoABB* raiz = construirABBOptimo(claves, probabilidades);

    std::cout << "ABB Óptimo:\n";
    imprimirEnOrden(raiz);

    // Liberar memoria (puedes usar un destructor más elaborado)
    delete raiz;

    return 0;
}
