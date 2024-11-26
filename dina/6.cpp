#include <iostream>
#include <vector>
#include <unordered_map>

bool evaluarExpresion(const std::string& x, const std::unordered_map<char, std::unordered_map<char, char>>& tablaMultiplicacion) {
    int n = x.size();

    // Inicializar la matriz de memorización para almacenar los resultados intermedios
    std::vector<std::vector<bool>> memo(n, std::vector<bool>(n, false));

    // Llenar la diagonal principal, ya que una subexpresión de longitud 1 siempre es igual a su único carácter
    for (int i = 0; i < n; ++i) {
        memo[i][i] = (x[i] == 'a');
    }

    // Llenar la matriz de abajo hacia arriba y de izquierda a derecha
    for (int longitud = 2; longitud <= n; ++longitud) {
        for (int i = 0; i <= n - longitud; ++i) {
            int j = i + longitud - 1;

            for (int k = i; k < j; ++k) {
                // Comprobar si la subexpresión [i, k] y [k+1, j] puede multiplicarse para obtener 'a'
                char parte1 = x[k];
                char parte2 = x[k + 1];

                if (tablaMultiplicacion.at(parte1).count(parte2) && (memo[i][k] && memo[k + 1][j])) {
                    memo[i][j] = true;
                    break;  // No es necesario seguir verificando
                }
            }
        }
    }

    // El resultado estará en la esquina superior derecha de la matriz
    return memo[0][n - 1];
}

int main() {
    std::unordered_map<char, std::unordered_map<char, char>> tablaMultiplicacion = {
        {'a', {{'a', 'b'}, {'b', 'b'}, {'c', 'a'}}},
        {'b', {{'a', 'c'}, {'b', 'a'}, {'c', 'b'}}},
        {'c', {{'a', 'c'}, {'b', 'b'}, {'c', 'c'}}}
    };

    std::string x = "abbabcb";

    bool esPosible = evaluarExpresion(x, tablaMultiplicacion);

    if (esPosible) {
        std::cout << "Es posible poner paréntesis en la expresión para obtener 'a'.\n";
    } else {
        std::cout << "No es posible obtener 'a' mediante la colocación de paréntesis en la expresión.\n";
    }

    return 0;
}
