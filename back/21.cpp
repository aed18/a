#include <iostream>
#include <vector>

using namespace std;

void devolucionMonedasBacktracking(int C, const vector<int>& tipos, vector<int>& cantidad, vector<int>& solucionActual, vector<int>& mejorSolucion, int& minMonedas, int nivel) {
    // Criterio de Fin
    if (nivel == tipos.size()) {
        int totalMonedas = 0;
        for (int i = 0; i < tipos.size(); ++i) {
            totalMonedas += solucionActual[i];
        }

        // Actualizar la mejor solución si la solución actual es válida y mejor
        if (totalMonedas <= minMonedas && totalMonedas > 0 && C == 0) {
            minMonedas = totalMonedas;
            mejorSolucion = solucionActual;
        }

        return;
    }

    // Generar opciones para la moneda actual
    for (int cantidadActual = 0; cantidadActual <= cantidad[nivel] && cantidadActual * tipos[nivel] <= C; ++cantidadActual) {
        solucionActual[nivel] = cantidadActual;

        // Llamada recursiva para la siguiente moneda
        devolucionMonedasBacktracking(C - cantidadActual * tipos[nivel], tipos, cantidad, solucionActual, mejorSolucion, minMonedas, nivel + 1);

        // Restaurar para probar la siguiente opción
        solucionActual[nivel] = 0;
    }
}

int main() {
    int C = 27; // Cantidad a devolver
    vector<int> tipos = {1, 2, 5, 10}; // Tipos de monedas
    vector<int> cantidad = {5, 2, 1, 10}; // Cantidad de monedas de cada tipo

    vector<int> solucionActual(tipos.size(), 0);
    vector<int> mejorSolucion(tipos.size(), 0);
    int minMonedas = INT_MAX;

    devolucionMonedasBacktracking(C, tipos, cantidad, solucionActual, mejorSolucion, minMonedas, 0);

    // Mostrar la mejor solución
    cout << "Mejor Solución: ";
    for (int i = 0; i < tipos.size(); ++i) {
        cout << mejorSolucion[i] << " monedas de " << tipos[i] << " ";
    }
    cout << endl;

    return 0;
}
