#include <iostream>
#include <vector>
using namespace std;

void devolverDinero(double cantidad, vector<double> monedas) {
    cout << "Monedas usadas: ";
    for (double moneda : monedas) {
        while (cantidad >= moneda) {
            cantidad -= moneda;
            cantidad = round(cantidad * 100) / 100; // Redondear para evitar errores numéricos
            cout << moneda << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<double> monedas = {5, 2, 1, 0.5, 0.2, 0.1};
    double cantidad = 3.80;
    devolverDinero(cantidad, monedas);
    return 0;
}
