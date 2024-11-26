#include <iostream>

using namespace std;

// Función para realizar el movimiento en el juego del NIM
int realizarMovimiento(int palillos) {
    // El jugador que empieza siempre quita la cantidad necesaria para dejar un múltiplo de 4
    return (palillos % 4 == 0) ? 3 : (palillos % 4) - 1;
}

int main() {
    int palillos = 6; // Número inicial de palillos

    cout << "Juego del NIM con " << palillos << " palillos." << endl;

    // Alternar turnos entre el jugador que empieza y el oponente hasta que no queden palillos
    while (palillos > 0) {
        // Turno del jugador que empieza
        int movimiento = realizarMovimiento(palillos);
        cout << "El jugador que empieza quita " << movimiento + 1 << " palillo(s)." << endl;
        palillos -= movimiento + 1;

        // Verificar si el jugador que empieza ganó después de su movimiento
        if (palillos == 0) {
            cout << "¡El jugador que empieza gana la partida!" << endl;
            break;
        }

        // Turno del oponente
        cout << "Palillos restantes: " << palillos << endl;
        movimiento = 3; // Estrategia óptima para el oponente
        cout << "El oponente quita " << movimiento + 1 << " palillo(s)." << endl;
        palillos -= movimiento + 1;

        // Verificar si el oponente ganó después de su movimiento
        if (palillos == 0) {
            cout << "¡El oponente gana la partida!" << endl;
        }
    }

    return 0;
}
