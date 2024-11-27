#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfsArticulation(int u, int parent, vector<vector<int>>& graph, vector<int>& visited, vector<int>& disc, vector<int>& low, set<int>& articulationPoints, int& time) {
    visited[u] = 1;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : graph[u]) {
        if (!visited[v]) {
            children++;
            dfsArticulation(v, u, graph, visited, disc, low, articulationPoints, time);

            low[u] = min(low[u], low[v]);

            if (parent == -1 && children > 1) {
                articulationPoints.insert(u);
            }
            if (parent != -1 && low[v] >= disc[u]) {
                articulationPoints.insert(u);
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

set<int> findArticulationPoints(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0), disc(n, 0), low(n, 0);
    set<int> articulationPoints;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsArticulation(i, -1, graph, visited, disc, low, articulationPoints, time);
        }
    }

    return articulationPoints;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2, 4},
        {2, 3}
    };

    set<int> points = findArticulationPoints(graph);
    cout << "Puntos de articulación: ";
    for (int point : points) cout << point << " ";
    cout << endl;

    return 0;
}
