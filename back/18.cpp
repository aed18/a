#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

void mostrarSolucion(const vector<int>& solucion) {
    for (int i = 0; i < solucion.size(); ++i) {
        cout << "Objeto " << i + 1 << " en recipiente " << solucion[i] << endl;
    }
    cout << "Número de recipientes utilizados: " << *max_element(solucion.begin(), solucion.end()) << endl;
    cout << "-------------------------------------" << endl;
}

void empaquetamientoEnRecipientesBacktracking(vector<int>& objetos, int capacidadMaxima, vector<int>& solucionActual) {
    if (objetos.empty()) {
        mostrarSolucion(solucionActual);
        return;
    }

    for (int i = 0; i < solucionActual.size(); ++i) {
        if (objetos.back() <= capacidadMaxima - solucionActual[i]) {
            solucionActual[i] += objetos.back();
            empaquetamientoEnRecipientesBacktracking(objetos, capacidadMaxima, solucionActual);
            solucionActual[i] -= objetos.back();
        }
    }

    // Crear un nuevo recipiente
    solucionActual.push_back(objetos.back());
    empaquetamientoEnRecipientesBacktracking(objetos, capacidadMaxima, solucionActual);
    solucionActual.pop_back();

    objetos.pop_back(); // Quitar el objeto actual
}

int main() {
    vector<int> objetos = {2, 3, 4};
    int capacidadMaxima = 5;
    vector<int> solucionActual;

    empaquetamientoEnRecipientesBacktracking(objetos, capacidadMaxima, solucionActual);

    return 0;
}
