#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Matriz de beneficios
const int INF = INT_MAX;

// Función para realizar la asignación utilizando backtracking
void asignarTareas(int nivel, int beneficioActual, vector<int>& asignados, vector<int>& solucionActual,
                   vector<int>& mejorSolucion, int& maxBeneficio, const vector<vector<int>>& beneficios) {
    int n = beneficios.size();
    
    // Si se ha completado una solución
    if (nivel == n) {
        if (beneficioActual > maxBeneficio) {
            maxBeneficio = beneficioActual;
            mejorSolucion = solucionActual;
        }
        return;
    }

    // Explorar todas las tareas no asignadas
    for (int tarea = 0; tarea < n; ++tarea) {
        if (asignados[tarea] == 0) { // Si la tarea no está asignada
            asignados[tarea] = 1;
            solucionActual[nivel] = tarea;
            asignarTareas(nivel + 1, beneficioActual + beneficios[nivel][tarea], asignados, 
                          solucionActual, mejorSolucion, maxBeneficio, beneficios);
            asignados[tarea] = 0; // Backtrack
        }
    }
}

int main() {
    // Matriz de beneficios
    vector<vector<int>> beneficios = {
        {94, 1, 54, 68},
        {74, 10, 88, 82},
        {62, 88, 8, 76},
        {11, 74, 81, 21}
    };

    int n = beneficios.size();
    vector<int> asignados(n, 0); // Para rastrear tareas asignadas
    vector<int> solucionActual(n, -1); // Solución parcial
    vector<int> mejorSolucion(n, -1); // Mejor solución encontrada
    int maxBeneficio = INT_MIN;

    // Resolver utilizando backtracking
    asignarTareas(0, 0, asignados, solucionActual, mejorSolucion, maxBeneficio, beneficios);

    // Salida de resultados
    cout << "Máximo beneficio: " << maxBeneficio << endl;
    cout << "Asignación óptima:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Persona " << i + 1 << " -> Tarea " << mejorSolucion[i] + 1 << endl;
    }

    return 0;
}
