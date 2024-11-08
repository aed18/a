#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string sumar(const string& a, const string& b) {
    string resultado;
    int carry = 0;

    for (int i = a.size() - 1; i >= 0; --i) {
        int suma = (a[i] - '0') + (b[i] - '0') + carry;
        carry = suma / 10;
        resultado.push_back((suma % 10) + '0');
    }

    if (carry > 0) {
        resultado.push_back(carry + '0');
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

string restar(const string& a, const string& b) {
    string resultado;
    int carry = 0;

    for (int i = a.size() - 1; i >= 0; --i) {
        int resta = (a[i] - '0') - (b[i] - '0') - carry;
        carry = 0;

        if (resta < 0) {
            resta += 10;
            carry = 1;
        }

        resultado.push_back(resta + '0');
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

string multiplicacionRapida(const string& u, const string& v) {
    int n = max(u.size(), v.size());

    if (n == 1) {
        return to_string((u[0] - '0') * (v[0] - '0'));
    }

    int m = ceil(n / 2.0);

    string w = u.substr(0, u.size() - m);
    string x = u.substr(u.size() - m, m);
    string y = v.substr(0, v.size() - m);
    string z = v.substr(v.size() - m, m);

    string m1 = multiplicacionRapida(w, y);
    string m2 = multiplicacionRapida(restar(w, x), sumar(y, z));
    string m3 = multiplicacionRapida(x, z);

    return sumar(sumar(m1 + string(2 * m, '0'), restar(m2, sumar(m1, m3))) + string(m, '0'), m3);
}

int main() {
    string u, v;

    cout << "Ingrese el primer número: ";
    cin >> u;

    cout << "Ingrese el segundo número: ";
    cin >> v;

    string resultado = multiplicacionRapida(u, v);

    cout << "Resultado de la multiplicación: " << resultado << endl;

    return 0;
}
