#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortDFS(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& Stack) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            topologicalSortDFS(neighbor, graph, visited, Stack);
        }
    }

    Stack.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> Stack;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, graph, visited, Stack);
        }
    }

    vector<int> result;
    while (!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }

    return result;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {3},
        {}
    };

    vector<int> order = topologicalSort(graph);
    cout << "Ordenación topológica: ";
    for (int node : order) cout << node << " ";
    cout << endl;

    return 0;
}
