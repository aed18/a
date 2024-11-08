#include <iostream>
#include <vector>

using namespace std;

void Pivote(vector<int>& T, int i, int j, int& l) {
    int x = T[i];
    int y = T[j];
    int z = T[(i + j) / 2];

    if ((x <= y && y <= z) || (z <= y && y <= x)) {
        l = j;
    } else if ((y <= x && x <= z) || (z <= x && x <= y)) {
        l = i;
    } else {
        l = (i + j) / 2;
    }
}

int Seleccion(vector<int>& T, int s) {
    int i = 0;
    int j = T.size() - 1;

    while (true) {
        int l;
        Pivote(T, i, j, l);

        if (s < l) {
            j = l - 1;
        } else if (s > l) {
            i = l + 1;
        } else {
            return T[l];
        }
    }
}

int main() {
    vector<int> T = {5, 9, 2, 5, 4, 3, 4, 10, 1, 6};
    int s = 5;

    int resultado = Seleccion(T, s);

    cout << "El elemento en la posición " << s << " es: " << resultado << endl;

    return 0;
}
