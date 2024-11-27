#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Object {
    int peso;
    int beneficio;
    int cantidad;
};
void mochilaBackT(int nivel, vector<int>& s1, vector<Object>& objetos, int& value, vector<int>& solucion,
    int M, int pesoA, int benA, int n) {
    if (nivel == n) {
        if (pesoA <= M && benA > value) {
            value = benA;
            solucion = s1;
        }
        return;
    }
    for (int i = 0; i <= objetos[nivel].cantidad; ++i) {
        s1[nivel] = i;
        int nuevoPact = pesoA + objetos[nivel].peso * i;
        int nuevoBact = benA + objetos[nivel].beneficio * i;
        // Criterio de poda
        if (nuevoPact <= M) {
            mochilaBackT(nivel + 1, s1, objetos, value, solucion, M, nuevoPact, nuevoBact, n);
        }
    }
    //retrocede
    s1[nivel] = 0;
}
int main() {
    int n = 4; 
    int M = 12; 
    vector<Object> objetos = {{2,3,2},{3,2,2},{4,1,2},{1,4,3}};
    vector<int> s1(n, 0); 
    vector<int> solucion(n, 0); 
    int value, pesoA, benA; 
    value = pesoA = benA = 0; 
    mochilaBackT(0, s1, objetos, value, solucion, M, pesoA, benA, n);
    cout<<"solucion: ";
    for (int i = 0; i < n; ++i) {
        cout << solucion[i] << " ";
    }
    cout<<endl;
    cout<<"Beneficio: " <<value<<endl;
    return 0;
}
