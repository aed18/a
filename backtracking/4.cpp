#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int level, cost, bound;
    vector<int> path;
};

int calculateBound(vector<vector<int>>& distances, vector<int>& path, int level) {
    int bound = 0;
    vector<bool> visited(distances.size(), false);

    for (int i = 0; i < level; i++) {
        visited[path[i]] = true;
    }

    for (int i = 0; i < distances.size(); i++) {
        if (!visited[i]) {
            int minDist = INT_MAX;
            for (int j = 0; j < distances.size(); j++) {
                if (!visited[j] && i != j) {
                    minDist = min(minDist, distances[i][j]);
                }
            }
            bound += minDist;
        }
    }
    return bound;
}

void tspBranchBound(vector<vector<int>>& distances, int& minCost, vector<int>& bestPath) {
    int n = distances.size();
    Node root;
    root.level = 0;
    root.cost = 0;
    root.path = {0};
    root.bound = calculateBound(distances, root.path, root.level);

    vector<Node> queue = {root};

    while (!queue.empty()) {
        Node u = queue.back();
        queue.pop_back();

        if (u.level == n - 1) {
            int finalCost = u.cost + distances[u.path.back()][0];
            if (finalCost < minCost) {
                minCost = finalCost;
                bestPath = u.path;
                bestPath.push_back(0);
            }
        } else {
            for (int i = 1; i < n; i++) {
                if (find(u.path.begin(), u.path.end(), i) == u.path.end()) {
                    Node v = u;
                    v.level = u.level + 1;
                    v.path.push_back(i);
                    v.cost += distances[u.path.back()][i];
                    v.bound = v.cost + calculateBound(distances, v.path, v.level);
                    if (v.bound < minCost) {
                        queue.push_back(v);
                    }
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> distances = {
        {0, 3, 10, 11, 7},
        {3, 0, 8, 12, 9},
        {10, 8, 0, 9, 4},
        {11, 12, 9, 0, 5},
        {7, 9, 4, 5, 0}
    };

    int minCost = INT_MAX;
    vector<int> bestPath;

    tspBranchBound(distances, minCost, bestPath);

    cout << "Costo mínimo: " << minCost << endl;
    cout << "Ruta óptima: ";
    for (int city : bestPath) cout << city << " ";
    cout << endl;

    return 0;
}
