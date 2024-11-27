#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Función para calcular la suma de diferencias absolutas
int calcularDiferencia(const vector<int>& alturas, const vector<int>& longitudes, const vector<int>& asignacion) {
    int suma = 0;
    for (int i = 0; i < asignacion.size(); ++i) {
        suma += abs(alturas[i] - longitudes[asignacion[i]]);
    }
    return suma;
}

// Función de backtracking sin poda
void backtracking(const vector<int>& alturas, const vector<int>& longitudes, vector<bool>& usado,
                  vector<int>& asignacion, int alumno, int& minDiferencia) {
    if (alumno == alturas.size()) {
        // Se alcanzó una asignación completa, calcular la diferencia total
        int sumaActual = calcularDiferencia(alturas, longitudes, asignacion);
        minDiferencia = min(minDiferencia, sumaActual);
        return;
    }

    for (int i = 0; i < longitudes.size(); ++i) {
        if (!usado[i]) {
            // Marcar como usado
            usado[i] = true;
            asignacion[alumno] = i;

            // Llamada recursiva al siguiente alumno
            backtracking(alturas, longitudes, usado, asignacion, alumno + 1, minDiferencia);

            // Deshacer la asignación
            usado[i] = false;
        }
    }
}

int main() {
    // Entrada de ejemplo
    vector<int> alturas = {178, 168, 190, 170};
    vector<int> longitudes = {183, 188, 168, 175};

    // Ordenar para facilitar las asignaciones
    sort(alturas.begin(), alturas.end());
    sort(longitudes.begin(), longitudes.end());

    // Variables para backtracking
    int n = alturas.size();
    vector<bool> usado(n, false);
    vector<int> asignacion(n, -1);
    int minDiferencia = INT_MAX;

    // Ejecutar el algoritmo
    backtracking(alturas, longitudes, usado, asignacion, 0, minDiferencia);

    // Salida de resultados
    cout << "Mínima suma de diferencias absolutas: " << minDiferencia << endl;

    return 0;
}
