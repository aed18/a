#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Función para calcular la estimación (cota superior) usando un enfoque greedy
float estimacion(int nivel, int n, int capacidadRestante, vector<int>& pesos, vector<int>& beneficios) {
    float beneficioEstimado = 0;
    for (int i = nivel; i < n; i++) {
        if (pesos[i] <= capacidadRestante) {
            beneficioEstimado += beneficios[i];
            capacidadRestante -= pesos[i];
        } else {
            beneficioEstimado += beneficios[i] * ((float)capacidadRestante / pesos[i]);
            break;
        }
    }
    return beneficioEstimado;
}

// Backtracking optimizado para el problema de la mochila 0/1
void mochilaBacktracking(int nivel, int n, int capacidadMax, int pesoActual, int beneficioActual, 
                         vector<int>& pesos, vector<int>& beneficios, int& mejorBeneficio, vector<int>& solucionActual, 
                         vector<int>& mejorSolucion) {
    if (pesoActual > capacidadMax) return; // Poda por peso

    if (nivel == n) { // Caso base: llegamos al nivel de las hojas
        if (beneficioActual > mejorBeneficio) {
            mejorBeneficio = beneficioActual;
            mejorSolucion = solucionActual;
        }
        return;
    }

    // Poda por estimación
    float beneficioEstimado = beneficioActual + estimacion(nivel + 1, n, capacidadMax - pesoActual, pesos, beneficios);
    if (beneficioEstimado <= mejorBeneficio) return;

    // Generar soluciones: primero incluir el objeto (1)
    solucionActual[nivel] = 1;
    mochilaBacktracking(nivel + 1, n, capacidadMax, pesoActual + pesos[nivel], beneficioActual + beneficios[nivel], 
                        pesos, beneficios, mejorBeneficio, solucionActual, mejorSolucion);

    // Luego excluir el objeto (0)
    solucionActual[nivel] = 0;
    mochilaBacktracking(nivel + 1, n, capacidadMax, pesoActual, beneficioActual, 
                        pesos, beneficios, mejorBeneficio, solucionActual, mejorSolucion);
}

int main() {
    int capacidadMax = 61; // Tamaño de la mochila
    vector<int> pesos = {1, 11, 21, 23, 33};
    vector<int> beneficios = {11, 21, 31, 33, 43};
    int n = pesos.size();

    // Ordenar los objetos por beneficio/peso de forma decreciente
    vector<pair<float, int>> ratio(n);
    for (int i = 0; i < n; i++) {
        ratio[i] = {(float)beneficios[i] / pesos[i], i};
    }
    sort(ratio.rbegin(), ratio.rend());

    vector<int> pesosOrdenados(n), beneficiosOrdenados(n);
    for (int i = 0; i < n; i++) {
        pesosOrdenados[i] = pesos[ratio[i].second];
        beneficiosOrdenados[i] = beneficios[ratio[i].second];
    }

    // Variables de estado para el algoritmo
    int mejorBeneficio = 0;
    vector<int> solucionActual(n, 0), mejorSolucion(n, 0);

    // Ejecutar el algoritmo de backtracking optimizado
    mochilaBacktracking(0, n, capacidadMax, 0, 0, pesosOrdenados, beneficiosOrdenados, mejorBeneficio, solucionActual, mejorSolucion);

    // Imprimir la solución
    cout << "Máximo beneficio: " << mejorBeneficio << endl;
    cout << "Objetos seleccionados: ";
    for (int i = 0; i < n; i++) {
        if (mejorSolucion[i] == 1) {
            cout << ratio[i].second + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
