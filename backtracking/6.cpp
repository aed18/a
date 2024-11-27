#include <iostream>
#include <vector>
using namespace std;

bool isBipartiteDFS(int node, vector<vector<int>>& graph, vector<int>& colors, int color) {
    colors[node] = color;
    for (int neighbor : graph[node]) {
        if (colors[neighbor] == -1) {
            if (!isBipartiteDFS(neighbor, graph, colors, 1 - color)) {
                return false;
            }
        } else if (colors[neighbor] == colors[node]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n, -1); // -1: no visitado, 0 y 1: colores alternados

    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            if (!isBipartiteDFS(i, graph, colors, 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    cout << "¿Es bipartito?: " << (isBipartite(graph) ? "Sí" : "No") << endl;
    return 0;
}
