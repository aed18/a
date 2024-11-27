#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    vector<int> assigned;  // Asignación actual
    int cost, level;       // Costo acumulado y nivel actual
    vector<bool> available; // Disponibilidad de tareas
};

int calculateCost(vector<vector<int>>& costMatrix, vector<int>& assigned) {
    int totalCost = 0;
    for (int i = 0; i < assigned.size(); ++i) {
        totalCost += costMatrix[i][assigned[i]];
    }
    return totalCost;
}

int assignmentProblem(vector<vector<int>>& costMatrix) {
    int n = costMatrix.size();
    queue<Node> Q;

    Node root;
    root.level = 0;
    root.cost = 0;
    root.assigned = vector<int>(n, -1);
    root.available = vector<bool>(n, true);
    Q.push(root);

    int minCost = INT_MAX;

    while (!Q.empty()) {
        Node u = Q.front(); Q.pop();

        if (u.level == n) {
            minCost = min(minCost, u.cost);
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (u.available[i]) {
                Node v = u;
                v.level = u.level + 1;
                v.assigned[u.level] = i;
                v.available[i] = false;
                v.cost = calculateCost(costMatrix, v.assigned);
                if (v.cost < minCost) Q.push(v);
            }
        }
    }
    return minCost;
}

int main() {
    vector<vector<int>> costMatrix = {
        {94, 1, 54, 68},
        {74, 10, 88, 82},
        {62, 88, 8, 76},
        {11, 74, 81, 21}
    };

    cout << "Costo mínimo de asignación: " << assignmentProblem(costMatrix) << endl;
    return 0;
}
