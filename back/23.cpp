#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar un disco
struct Disco {
    int capacidad; // Capacidad del disco
    vector<int> ficheros; // Lista de ficheros en el disco
};

// Estructura para representar una solución
struct Solucion {
    vector<Disco> discos; // Lista de discos con los ficheros grabados
};

// Función para imprimir una solución (solo para visualización)
void imprimirSolucion(const Solucion& solucion) {
    for (int i = 0; i < solucion.discos.size(); ++i) {
        cout << "Disco " << i + 1 << ": ";
        for (int j = 0; j < solucion.discos[i].ficheros.size(); ++j) {
            cout << solucion.discos[i].ficheros[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Función para generar la siguiente solución parcial
void Generar(Solucion& sol, int n, int m, const vector<int>& tamanos) {
    // Implementar la lógica para generar la siguiente solución parcial
    if (sol.discos.size() < m) {
        // Agregar un nuevo disco
        sol.discos.push_back(Disco());
        return;
    }

    // Agregar ficheros a los discos existentes
    for (int i = 0; i < sol.discos.size(); ++i) {
        if (sol.discos[i].ficheros.size() < n) {
            // Agregar un fichero al disco actual
            sol.discos[i].ficheros.push_back(tamanos[sol.discos[i].ficheros.size()]);
            return;
        }
    }
}

// Función para determinar si hay más nodos hermanos por explorar
bool MasHermanos(const Solucion& sol, int n, int m, const vector<int>& tamanos) {
    // Implementar la lógica para determinar si hay más nodos hermanos por explorar
    for (int i = 0; i < sol.discos.size(); ++i) {
        if (sol.discos[i].ficheros.size() < n) {
            return true;
        }
    }
    return sol.discos.size() < m;
}

// Función para determinar si se ha alcanzado una solución completa
bool EsSolucion(const Solucion& sol, int n) {
    // Implementar la lógica para determinar si se ha alcanzado una solución completa
    for (int i = 0; i < sol.discos.size(); ++i) {
        if (sol.discos[i].ficheros.size() != n) {
            return false;
        }
    }
    return true;
}

// Función para evaluar la solución
int Evaluar(const Solucion& sol) {
    // Implementar la lógica para evaluar la solución
    return sol.discos.size(); // En este caso, la evaluación es el número de discos utilizados
}

// Función principal de backtracking para la grabación de ficheros
void GrabacionBacktracking(int n, int m, const vector<int>& tamanos) {
    Solucion solucion_actual;

    while (true) {
        // Procesar la solución actual o realizar otras acciones según sea necesario
        int evaluacion_actual = Evaluar(solucion_actual);
        imprimirSolucion(solucion_actual);

        if (EsSolucion(solucion_actual, n)) {
            // Hemos alcanzado una solución completa, procesar o almacenar según sea necesario
            // ...
        }

        if (MasHermanos(solucion_actual, n, m, tamanos)) {
            // Llamar recursivamente para el siguiente nivel
            Generar(solucion_actual, n, m, tamanos);
        } else {
            // Retroceder: Deshacer la última acción y buscar más hermanos
            if (!solucion_actual.discos.empty()) {
                solucion_actual.discos.back().ficheros.pop_back();
                if (solucion_actual.discos.back().ficheros.empty()) {
                    solucion_actual.discos.pop_back();
                }
            }
        }
    }
}

int main() {
    // Definir los datos del problema
    int n = 5; // Número de ficheros
    int m = 2; // Número de discos
    vector<int> tamanos = {10, 8, 6, 4, 2}; // Tamaños de los ficheros

    // Llamar a la función principal de backtracking
    GrabacionBacktracking(n, m, tamanos);

    return 0;
}
