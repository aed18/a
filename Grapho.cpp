#include <iostream>
#include <forward_list>
#include <vector>

struct CEdge {
    CEdge(int idn = -1, int v = 0) {
        id_node = idn;
        value = v;
    }
    int id_node;
    int value;
};

struct CNode {
    CNode(int id = -1, char v = 0) {
        id_node = id;
        value = v;
    }
    int id_node;
    char value;
    std::forward_list<CEdge> edges;
};

class CGraph {
public:
    void InsNode(char v);
    void InsEdge(int idn1, int idn2, int v);
    void RemNode(int idn);
    void RemEdge(int idn1, int idn2);
    void Print();
    std::vector<CNode> nodes;
};

void CGraph::InsNode(char v) {
    CNode n(nodes.size(), v);
    nodes.push_back(n);
}

void CGraph::InsEdge(int idn1, int idn2, int v) {
    CEdge e(idn2, v);
    nodes[idn1].edges.push_front(e);
}

void CGraph::RemEdge(int idn1, int idn2) {
    auto& edges = nodes[idn1].edges;
    edges.remove_if([idn2](const CEdge& e) { return e.id_node == idn2; });
}

void CGraph::RemNode(int idn) {
    // Localizar conexiones
    std::vector<int> bedges;

    for (auto& c : nodes) {
        for (auto& e : c.edges) {
            if (e.id_node == idn) {
                bedges.push_back(c.id_node);
            }
        }
    }

    // Eliminar todas las conexiones hacia el nodo
    for (int n : bedges) {
        RemEdge(n, idn);
    }

    // Eliminar el nodo
    nodes.erase(nodes.begin() + idn);

    // Actualizar índices de los nodos restantes
    for (int i = idn; i < nodes.size(); ++i) {
        nodes[i].id_node = i;
    }

    // Actualizar los índices en los bordes
    for (auto& n : nodes) {
        for (auto& e : n.edges) {
            if (e.id_node > idn) {
                --e.id_node;
            }
        }
    }
}

void CGraph::Print() {
    for (auto n : nodes) {
        std::cout << n.value << " ";
        for (auto e : n.edges)
            std::cout << "->" << nodes[e.id_node].value << " " << e.value;
        std::cout << "\n";
    }
}

int main() {
    CGraph g;
    g.InsNode('A');    g.InsNode('B');
    g.InsNode('C');    g.InsNode('D');
    g.InsNode('X');
    g.InsEdge(0, 1, 3);    g.InsEdge(0, 2, 7); // A
    g.InsEdge(1, 3, 4);    g.InsEdge(1, 2, 2); // B
    g.InsEdge(2, 3, 1);    g.InsEdge(2, 4, 5); // C
    g.Print();

    g.RemNode(2); // Eliminar nodo 'C'
    std::cout << "Luego del remove:\n";
    g.Print();

    return 0;
}
