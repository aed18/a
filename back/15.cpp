#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::min();

// Estructura para representar la solución
struct Solucion {
    vector<int> asignacion;
    int puntuacionTotal;

    Solucion(int n) : asignacion(n, -1), puntuacionTotal(0) {}
};

// Función para verificar si un árbitro y un equipo son de la misma región
bool MismoRegion(int arbitro, int equipo) {
    // Implementa la lógica según tu estructura de datos
    // Devuelve true si son de la misma región, false en caso contrario
    return false;
}

// Función para calcular la puntuación total de una asignación
int CalcularPuntuacion(const vector<vector<int>>& preferencias, const Solucion& solucion) {
    int puntuacion = 0;
    for (int i = 0; i < solucion.asignacion.size(); ++i) {
        int arbitro = solucion.asignacion[i];
        int equipo = i;  // Suponemos que los equipos están numerados de 0 a n/2-1
        if (!MismoRegion(arbitro, equipo)) {
            puntuacion += preferencias[equipo][arbitro];
        }
    }
    return puntuacion;
}

// Función principal de backtracking para la asignación de árbitros
void AsignacionArbitrosBacktracking(int partido, const vector<vector<int>>& preferencias, Solucion& solucion, Solucion& mejorSolucion) {
    if (partido == solucion.asignacion.size()) {
        // Condición de fin: Se ha asignado un árbitro a cada partido
        int puntuacion = CalcularPuntuacion(preferencias, solucion);
        if (puntuacion > mejorSolucion.puntuacionTotal) {
            mejorSolucion = solucion;
            mejorSolucion.puntuacionTotal = puntuacion;
        }
        return;
    }

    for (int arbitro = 0; arbitro < preferencias[0].size(); ++arbitro) {
        if (solucion.asignacion[partido] == -1 && !MismoRegion(arbitro, partido)) {
            solucion.asignacion[partido] = arbitro;
            AsignacionArbitrosBacktracking(partido + 1, preferencias, solucion, mejorSolucion);
            solucion.asignacion[partido] = -1;  // Deshacer asignación para probar otras opciones
        }
    }
}

int main() {
    // Ejemplo de preferencias (ajusta según tus datos)
    vector<vector<int>> preferencias = {
        {9, 5, 8},
        {3, 2, 7},
        {6, 1, 4},
        // ... más filas según el número de equipos
    };

    int n = preferencias.size() * 2;  // Suponiendo que hay n equipos
    int m = preferencias[0].size();   // Suponiendo que hay m árbitros

    Solucion solucionActual(n);
    Solucion mejorSolucion(n);

    AsignacionArbitrosBacktracking(0, preferencias, solucionActual, mejorSolucion);

    // Imprimir la mejor solución encontrada
    cout << "Mejor asignación de árbitros: ";
    for (int arbitro : mejorSolucion.asignacion) {
        cout << arbitro << " ";
    }
    cout << endl;

    cout << "Puntuación total: " << mejorSolucion.puntuacionTotal << endl;

    return 0;
}
