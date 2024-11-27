#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // Tamaño del laberinto
int dx[] = {0, 1, 0, -1}; // Movimientos: derecha, abajo, izquierda, arriba
int dy[] = {1, 0, -1, 0};

bool solveMaze(vector<vector<bool>>& maze, int x, int y, vector<vector<int>>& solution) {
    if (x == N - 1 && y == N - 1) { // Llegamos a la salida
        solution[x][y] = 1;
        return true;
    }

    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] && solution[x][y] == 0) {
        solution[x][y] = 1; // Marcar como parte del camino

        for (int i = 0; i < 4; ++i) { // Intentar las 4 direcciones
            if (solveMaze(maze, x + dx[i], y + dy[i], solution)) {
                return true;
            }
        }

        solution[x][y] = 0; // Retroceder
    }
    return false;
}

int main() {
    vector<vector<bool>> maze = {
        {true, true, true, true, true},
        {false, true, true, true, false},
        {true, true, false, false, false},
        {true, true, true, true, true},
        {true, true, true, false, true}
    };

    vector<vector<int>> solution(N, vector<int>(N, 0));

    if (solveMaze(maze, 0, 0, solution)) {
        cout << "Camino encontrado:\n";
        for (const auto& row : solution) {
            for (int cell : row) {
                cout << (cell ? "1 " : "0 ");
            }
            cout << endl;
        }
    } else {
        cout << "No hay camino posible.\n";
    }

    return 0;
}
