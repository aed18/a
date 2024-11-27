#include <iostream>
#include <vector>
using namespace std;

bool hasCycleDFS(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor] && hasCycleDFS(neighbor, graph, visited, recStack)) {
            return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false), recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i] && hasCycleDFS(i, graph, visited, recStack)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {1},
        {2},
        {0, 3},
        {}
    };

    cout << "¿El grafo tiene ciclos?: " << (hasCycle(graph) ? "Sí" : "No") << endl;
    return 0;
}
