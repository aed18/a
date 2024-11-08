#include <iostream>
#include <vector>
#include <algorithm>

struct Objeto {
    int indice;
    int peso;
    int valor;

    Objeto(int i, int p, int v) : indice(i), peso(p), valor(v) {}
};

bool compararPorValorPorPeso(const Objeto& a, const Objeto& b) {
    return (static_cast<double>(a.valor) / a.peso) > (static_cast<double>(b.valor) / b.peso);
}

void mochila(const std::vector<Objeto>& objetos, int capacidad) {
    std::vector<Objeto> objetosOrdenados = objetos;
    std::sort(objetosOrdenados.begin(), objetosOrdenados.end(), compararPorValorPorPeso);

    std::vector<int> solucion(objetos.size(), 0);
    int pesoActual = 0;

    for (const Objeto& objeto : objetosOrdenados) {
        int indice = objeto.indice;
        if (pesoActual + objeto.peso <= capacidad) {
            solucion[indice] = 1;
            pesoActual += objeto.peso;
        } else {
            solucion[indice] = (capacidad - pesoActual) / objeto.peso;
            pesoActual = capacidad;
            break;
        }
    }

    std::cout << "Solución (0 o 1 para cada objeto): ";
    for (int valor : solucion) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Objeto> objetos = {{1, 2, 10}, {2, 5, 40}, {3, 1, 7}, {4, 7, 20}, {5, 3, 15}};
    int capacidadMochila = 10;

    mochila(objetos, capacidadMochila);

    return 0;
}
