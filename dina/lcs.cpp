#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> calcularLCS(const std::string& cadena1, const std::string& cadena2) {
    int m = cadena1.length();
    int n = cadena2.length();

    // Inicializar la tabla LCS
    std::vector<std::vector<int>> tablaLCS(m + 1, std::vector<int>(n + 1, 0));

    // Calcular la longitud de la subsecuencia común
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (cadena1[i - 1] == cadena2[j - 1]) {
                tablaLCS[i][j] = tablaLCS[i - 1][j - 1] + 1;
            } else {
                tablaLCS[i][j] = std::max(tablaLCS[i - 1][j], tablaLCS[i][j - 1]);
            }
        }
    }

    return tablaLCS;
}

std::string obtenerLCS(const std::vector<std::vector<int>>& tablaLCS, const std::string& cadena1, const std::string& cadena2) {
    int m = cadena1.length();
    int n = cadena2.length();

    int longitudLCS = tablaLCS[m][n];
    std::string lcs;

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (cadena1[i - 1] == cadena2[j - 1]) {
            lcs = cadena1[i - 1] + lcs;
            --i;
            --j;
        } else if (tablaLCS[i - 1][j] > tablaLCS[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return lcs;
}

int main() {
    std::string cadena1 = "ABCBDAB";
    std::string cadena2 = "BDCAB";

    std::vector<std::vector<int>> tablaLCS = calcularLCS(cadena1, cadena2);
    std::string lcs = obtenerLCS(tablaLCS, cadena1, cadena2);

    std::cout << "Longitud de la subsecuencia común más larga: " << lcs.length() << "\n";
    std::cout << "Subsecuencia común más larga: " << lcs << "\n";

    return 0;
}
