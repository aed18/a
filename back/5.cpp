#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar la solución
struct Solucion {
    vector<int> cantidad_por_moneda;
};

// Función para generar la siguiente solución parcial
void Generar(int k, const vector<int>& denominaciones, Solucion& sol) {
    sol.cantidad_por_moneda[k]++;
}

// Función para determinar si hay más nodos hermanos por explorar
bool MasHermanos(int k, const vector<int>& denominaciones, const Solucion& sol) {
    return k < denominaciones.size() - 1;
}

// Función para determinar si se ha alcanzado una solución completa
bool EsSolucion(int k, const vector<int>& denominaciones, const Solucion& sol, int monto) {
    int suma = 0;
    for (int i = 0; i < denominaciones.size(); ++i) {
        suma += sol.cantidad_por_moneda[i] * denominaciones[i];
    }
    return suma == monto;
}

// Función para evaluar la solución parcial actual
bool Criterio(int k, const vector<int>& denominaciones, const Solucion& sol, int monto) {
    int suma = 0;
    for (int i = 0; i <= k; ++i) {
        suma += sol.cantidad_por_moneda[i] * denominaciones[i];
    }
    return suma <= monto;
}

// Función principal de backtracking para el cambio de moneda
void CambioDeMonedaBacktracking(int k, const vector<int>& denominaciones, Solucion& sol, int monto) {
    while (true) {
        Generar(k, denominaciones, sol);
        if (EsSolucion(k, denominaciones, sol, monto)) {
            // Procesar la solución completa
            cout << "Solución encontrada: ";
            for (int i = 0; i < denominaciones.size(); ++i) {
                cout << sol.cantidad_por_moneda[i] << " x " << denominaciones[i] << "  ";
            }
            cout << endl;
        } else if (Criterio(k, denominaciones, sol, monto)) {
            // Llamar recursivamente para el siguiente nivel
            CambioDeMonedaBacktracking(k + 1, denominaciones, sol, monto);
        }
        if (!MasHermanos(k, denominaciones, sol)) {
            break;
        }
    }
}

int main() {
    int monto;
    cout << "Ingrese el monto para el cambio: ";
    cin >> monto;

    vector<int> denominaciones = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; // Ejemplo de denominaciones en centavos

    Solucion solucion;
    solucion.cantidad_por_moneda.resize(denominaciones.size(), 0);

    CambioDeMonedaBacktracking(0, denominaciones, solucion, monto);

    return 0;
}
