#include <iostream>

using namespace std;

// Función para imprimir el estado actual del montón
void ImprimirMonton(int monton) {
    cout << "Montón actual: " << monton << " palos" << endl;
}

// Función para determinar si un estado es un estado final (juego terminado)
bool EsEstadoFinal(int monton) {
    return monton == 0;
}

// Función para evaluar la utilidad de un estado final
int EvaluarUtilidad(int monton, bool esTurnoOrdenador) {
    // El ordenador gana si el montón está vacío y es su turno, de lo contrario, pierde
    return (monton == 0 && esTurnoOrdenador) ? 1 : -1;
}

// Función principal de minimax para el juego de Nim
int Minimax(int monton, bool esTurnoOrdenador) {
    if (EsEstadoFinal(monton)) {
        return EvaluarUtilidad(monton, esTurnoOrdenador);
    }

    if (esTurnoOrdenador) {
        int mejorValor = -1; // Inicializar con un valor mínimo
        for (int retirar = 1; retirar <= 3; ++retirar) {
            int nuevoMonton = monton - retirar;
            int valor = Minimax(nuevoMonton, !esTurnoOrdenador);
            mejorValor = max(mejorValor, valor);
        }
        return mejorValor;
    } else {
        int mejorValor = 1; // Inicializar con un valor máximo
        for (int retirar = 1; retirar <= 3; ++retirar) {
            int nuevoMonton = monton - retirar;
            int valor = Minimax(nuevoMonton, !esTurnoOrdenador);
            mejorValor = min(mejorValor, valor);
        }
        return mejorValor;
    }
}

// Función para que el ordenador realice su movimiento basado en minimax
int MovimientoOrdenador(int monton) {
    int mejorMovimiento = -1;
    int mejorValor = -1;

    for (int retirar = 1; retirar <= 3; ++retirar) {
        int nuevoMonton = monton - retirar;
        int valor = Minimax(nuevoMonton, false);
        if (valor > mejorValor) {
            mejorValor = valor;
            mejorMovimiento = retirar;
        }
    }

    return mejorMovimiento;
}

int main() {
    int monton = 5;
    bool esTurnoOrdenador = true;

    while (!EsEstadoFinal(monton)) {
        ImprimirMonton(monton);

        if (esTurnoOrdenador) {
            cout << "Turno del Ordenador:" << endl;
            int movOrdenador = MovimientoOrdenador(monton);
            cout << "El Ordenador retira " << movOrdenador << " palo(s)" << endl;
            monton -= movOrdenador;
        } else {
            cout << "Turno del Humano:" << endl;
            int movHumano;
            do {
                cout << "Ingrese la cantidad de palos a retirar (entre 1 y 3): ";
                cin >> movHumano;
            } while (movHumano < 1 || movHumano > 3);
            monton -= movHumano;
        }

        esTurnoOrdenador = !esTurnoOrdenador;
    }

    ImprimirMonton(monton);
    
    if (esTurnoOrdenador) {
        cout << "¡El Ordenador ha perdido!" << endl;
    } else {
        cout << "¡El Humano ha perdido!" << endl;
    }

    return 0;
}
