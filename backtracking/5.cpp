#include <iostream>
#include <vector>
using namespace std;

struct Posicion {
    int fila, columna;
};

// Movimientos posibles: arriba, abajo, izquierda, derecha
vector<Posicion> movimientos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool resolverLaberinto(vector<vector<bool>>& laberinto, vector<vector<bool>>& visitado, 
                       vector<Posicion>& camino, Posicion actual, Posicion salida) {
    int n = laberinto.size();
    int m = laberinto[0].size();
    
    // Verificar si hemos llegado a la salida
    if (actual.fila == salida.fila && actual.columna == salida.columna) {
        camino.push_back(actual);
        return true;
    }
    
    // Marcar como visitado
    visitado[actual.fila][actual.columna] = true;
    camino.push_back(actual);
    
    // Probar cada movimiento posible
    for (auto mov : movimientos) {
        Posicion nueva = {actual.fila + mov.fila, actual.columna + mov.columna};
        if (nueva.fila >= 0 && nueva.fila < n && nueva.columna >= 0 && nueva.columna < m &&
            laberinto[nueva.fila][nueva.columna] && !visitado[nueva.fila][nueva.columna]) {
            if (resolverLaberinto(laberinto, visitado, camino, nueva, salida)) {
                return true;
            }
        }
    }
    
    // Retroceder
    camino.pop_back();
    return false;
}

int main() {
    vector<vector<bool>> laberinto = {
        {true, false, true, true, false},
        {true, true, true, false, true},
        {false, false, true, true, true},
        {true, true, false, false, true},
        {true, false, true, true, true}
    };
    
    Posicion inicio = {0, 0};
    Posicion salida = {4, 4};
    vector<vector<bool>> visitado(5, vector<bool>(5, false));
    vector<Posicion> camino;
    
    if (resolverLaberinto(laberinto, visitado, camino, inicio, salida)) {
        cout << "Camino encontrado:" << endl;
        for (auto p : camino) {
            cout << "(" << p.fila << ", " << p.columna << ") -> ";
        }
        cout << "Salida" << endl;
    } else {
        cout << "No se encontró un camino." << endl;
    }
    
    return 0;
}
