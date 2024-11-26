#include <iostream>
#include <climits>

struct Node {
    char name;
    int value;
    Node* left;
    Node* right;

    Node(char n, int v) : name(n), value(v), left(nullptr), right(nullptr) {}
};

int minimax(Node* node, int depth, bool maximizingPlayer, int alpha, int beta) {
    if (depth == 0 || node == nullptr) {
        return node->value;
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        for (Node* child : {node->left, node->right}) {
            int eval = minimax(child, depth - 1, false, alpha, beta);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                std::cout << "Poda alfa-beta en nodo " << node->name << std::endl;
                break;
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (Node* child : {node->left, node->right}) {
            int eval = minimax(child, depth - 1, true, alpha, beta);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                std::cout << "Poda alfa-beta en nodo " << node->name << std::endl;
                break;
            }
        }
        return minEval;
    }
}

int main() {
    // Construir el árbol
    Node* root = new Node('A', 0);
    root->left = new Node('B', 0);
    root->right = new Node('C', 0);
    root->left->left = new Node('D', 3);
    root->left->right = new Node('E', 5);
    root->right->left = new Node('F', 2);
    root->right->right = new Node('G', 8);

    // Llamar al algoritmo minimax con poda alfa-beta
    int result = minimax(root, 3, true, INT_MIN, INT_MAX);
    std::cout << "El valor final del nodo raíz es: " << result << std::endl;

    return 0;
}
