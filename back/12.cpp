#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int NO_TRABAJO = -1;

// Función para verificar si un trabajador puede realizar un trabajo
bool PuedeRealizarTrabajo(const vector<vector<int>>& T, int trabajador, int trabajo) {
    return T[trabajador][trabajo] == 1;
}

// Función principal de backtracking para asignación de trabajos
void AsignacionTrabajosBacktracking(int trabajador, vector<int>& asignacion, const vector<vector<int>>& T, int& maxTrabajosAsignados, vector<int>& mejorAsignacion) {
    if (trabajador == T.size()) {
        // Fin de la asignación, calcular el número de trabajos asignados
        int trabajosAsignados = count(asignacion.begin(), asignacion.end(), NO_TRABAJO);
        if (trabajosAsignados > maxTrabajosAsignados) {
            maxTrabajosAsignados = trabajosAsignados;
            mejorAsignacion = asignacion;
        }
        return;
    }

    for (int trabajo = 0; trabajo < T[0].size(); ++trabajo) {
        if (PuedeRealizarTrabajo(T, trabajador, trabajo)) {
            // Asignar el trabajo al trabajador
            asignacion[trabajador] = trabajo;

            // Llamar recursivamente para el siguiente trabajador
            AsignacionTrabajosBacktracking(trabajador + 1, asignacion, T, maxTrabajosAsignados, mejorAsignacion);

            // Deshacer la asignación para probar otras posibilidades
            asignacion[trabajador] = NO_TRABAJO;
        }
    }
}

int main() {
    // Ejemplo de matriz de asignación
    vector<vector<int>> T = {
        {1, 0, 1},
        {1, 1, 0},
        {0, 1, 1},
    };

    int n = T.size();
    int m = T[0].size();

    vector<int> asignacion(n, NO_TRABAJO);
    int maxTrabajosAsignados = 0;
    vector<int> mejorAsignacion;

    AsignacionTrabajosBacktracking(0, asignacion, T, maxTrabajosAsignados, mejorAsignacion);

    // Imprimir la asignación óptima
    cout << "Asignación óptima de trabajos:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Trabajador " << i << ": ";
        if (mejorAsignacion[i] != NO_TRABAJO) {
            cout << "Trabajo " << mejorAsignacion[i];
        } else {
            cout << "Ningún trabajo asignado";
        }
        cout << endl;
    }

    cout << "Número máximo de trabajos asignados: " << maxTrabajosAsignados << endl;

    return 0;
}
