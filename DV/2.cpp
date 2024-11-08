#include <iostream>
#include <cmath>

using namespace std;

// Función para convertir un número binario a decimal
int binaryToDecimal(const string& binary) {
    int decimal = 0;
    int n = binary.length();

    for (int i = 0; i < n; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, n - 1 - i);
        }
    }

    return decimal;
}

// Función para convertir un número decimal a binario
string decimalToBinary(int decimal) {
    string binary = "";

    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }

    return binary;
}

// Función principal de multiplicación utilizando "divide y vencerás"
string multiplyBinary(const string& A, const string& B) {
    // Convierte los números binarios a decimales para facilitar la implementación
    int a = binaryToDecimal(A);
    int b = binaryToDecimal(B);

    // Caso base: si uno de los números es cero, el resultado es cero
    if (a == 0 || b == 0) {
        return "0";
    }

    // Caso base: si uno de los números es uno, el resultado es el otro número
    if (a == 1) {
        return B;
    }
    if (b == 1) {
        return A;
    }

    // Divide los números en dos partes
    int lenA = A.length();
    int lenB = B.length();
    int mid = max(lenA, lenB) / 2;

    string AL = A.substr(0, lenA - mid);
    string AR = A.substr(lenA - mid);
    string BL = B.substr(0, lenB - mid);
    string BR = B.substr(lenB - mid);

    // Realiza las multiplicaciones recursivas
    int P1 = binaryToDecimal(multiplyBinary(AL, BL));
    int P2 = binaryToDecimal(multiplyBinary(AR, BR));
    int P3 = binaryToDecimal(multiplyBinary(decimalToBinary(binaryToDecimal(AL) + binaryToDecimal(AR)),
                                            decimalToBinary(binaryToDecimal(BL) + binaryToDecimal(BR))));

    // Combina los resultados para obtener el producto final
    int resultDecimal = P1 + (P3 - P1 - P2) * pow(2, 2 * mid) + P2;

    // Convierte el resultado decimal a binario
    return decimalToBinary(resultDecimal);
}

int main() {
    string A = "10011011";
    string B = "10111010";

    cout << "Multiplicando los números binarios:\n";
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";

    string result = multiplyBinary(A, B);

    cout << "Resultado en binario: " << result << "\n";

    return 0;
}
