#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countShortestPaths(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> distance(n, -1), count(n, 0);
    queue<int> q;

    distance[start] = 0;
    count[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1) { // No visitado
                distance[neighbor] = distance[node] + 1;
                count[neighbor] = count[node];
                q.push(neighbor);
            } else if (distance[neighbor] == distance[node] + 1) { // Mismo nivel
                count[neighbor] += count[node];
            }
        }
    }

    return count[end];
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3}
    };

    int start = 0, end = 4;
    cout << "Número de caminos mínimos: " << countShortestPaths(graph, start, end) << endl;
    return 0;
}
