#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

bool isConnected(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);

    // Iniciar DFS desde el nodo 0
    dfs(0, graph, visited);

    // Comprobar si todos los nodos fueron visitados
    for (bool nodeVisited : visited) {
        if (!nodeVisited) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };

    cout << "¿El grafo es conexo?: " << (isConnected(graph) ? "Sí" : "No") << endl;
    return 0;
}
