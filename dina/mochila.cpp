#include <iostream>
#include <vector>

struct Objeto {
    int peso;
    int beneficio;
};

void mochila01(const std::vector<Objeto>& objetos, int capacidad) {
    int n = objetos.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (objetos[i - 1].peso <= w) {
                dp[i][w] = std::max(dp[i - 1][w], objetos[i - 1].beneficio + dp[i - 1][w - objetos[i - 1].peso]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Construir la solución
    int res = dp[n][capacidad];
    int w = capacidad;
    std::vector<int> solucion;

    for (int i = n; i > 0 && res > 0; --i) {
        if (res != dp[i - 1][w]) {
            solucion.push_back(i);
            res -= objetos[i - 1].beneficio;
            w -= objetos[i - 1].peso;
        }
    }

    // Imprimir la solución
    std::cout << "Objetos seleccionados: ";
    for (int i = solucion.size() - 1; i >= 0; --i) {
        std::cout << solucion[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Beneficio total: " << dp[n][capacidad] << std::endl;
}

int main() {
    std::vector<Objeto> objetos = {{3, 12}, {7, 3}, {4, 7}, {2, 4}, {1, 3}, {6, 8}};
    int capacidad = 15;

    std::cout << "Mochila de capacidad W=15:\n";
    mochila01(objetos, capacidad);

    return 0;
}





#include <iostream>
#include <vector>
#include <set>

struct Objeto {
    int peso;
    int beneficio;
};

void mochila01(const std::vector<Objeto>& objetos, int capacidad) {
    int n = objetos.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacidad + 1, 0));
    std::vector<std::set<int>> soluciones(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (objetos[i - 1].peso <= w) {
                int nuevoBeneficio = objetos[i - 1].beneficio + dp[i - 1][w - objetos[i - 1].peso];

                if (nuevoBeneficio > dp[i - 1][w]) {
                    dp[i][w] = nuevoBeneficio;
                    soluciones[i].insert(w);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Construir y mostrar todas las soluciones
    for (int w : soluciones[n]) {
        int res = dp[n][w];
        int pesoActual = w;
        std::vector<int> solucion;

        for (int i = n; i > 0 && res > 0; --i) {
            if (res != dp[i - 1][pesoActual]) {
                solucion.push_back(i);
                res -= objetos[i - 1].beneficio;
                pesoActual -= objetos[i - 1].peso;
            }
        }

        std::cout << "Objetos seleccionados para capacidad " << w << ": ";
        for (int i = solucion.size() - 1; i >= 0; --i) {
            std::cout << solucion[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Beneficio total: " << dp[n][w] << std::endl;
    }
}

int main() {
    std::vector<Objeto> objetos = {{3, 12}, {7, 3}, {4, 7}, {2, 4}, {1, 3}, {6, 8}};
    int capacidad = 15;

    std::cout << "Mochila de capacidad W=15:\n";
    mochila01(objetos, capacidad);

    return 0;
}
