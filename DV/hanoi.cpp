#include <iostream>

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        // Caso base: mover el disco de la torre origen a la torre destino
        std::cout << "Mover disco 1 desde la torre " << origen << " a la torre " << destino << std::endl;
        return;
    }

    // Mover n-1 discos de la torre origen a la torre auxiliar
    hanoi(n - 1, origen, auxiliar, destino);

    // Mover el disco restante de la torre origen a la torre destino
    std::cout << "Mover disco " << n << " desde la torre " << origen << " a la torre " << destino << std::endl;

    // Mover los n-1 discos de la torre auxiliar a la torre destino
    hanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int num_discos;

    std::cout << "Ingrese el número de discos: ";
    std::cin >> num_discos;

    hanoi(num_discos, 'A', 'C', 'B');

    return 0;
}
