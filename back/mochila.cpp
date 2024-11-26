#include <iostream>
#include <vector>

using namespace std;

// Definición de las estructuras de datos
struct Objeto {
    int peso;
    int beneficio;
};

struct SolucionParcial {
    vector<int> seleccionados;
    int pesoTotal;
    int beneficioTotal;
};

// Variables globales
vector<Objeto> objetos;
int capacidadMaxima;
SolucionParcial mejorSolucion;

// Funciones del esquema
void Generar(int nivel, SolucionParcial& solucionActual) {
    solucionActual.seleccionados[nivel]++;
    solucionActual.pesoTotal += objetos[nivel].peso;
    solucionActual.beneficioTotal += objetos[nivel].beneficio;
}

bool Solucion(int nivel, const SolucionParcial& solucionActual) {
    return nivel == objetos.size() - 1 && solucionActual.pesoTotal <= capacidadMaxima;
}

bool Criterio(int nivel, const SolucionParcial& solucionActual) {
    return nivel < objetos.size() - 1 && solucionActual.pesoTotal <= capacidadMaxima;
}

bool MasHermanos(int nivel, const SolucionParcial& solucionActual) {
    return solucionActual.seleccionados[nivel] < 1;
}

void Retroceder(int nivel, SolucionParcial& solucionActual) {
    solucionActual.seleccionados[nivel] = -1;
    solucionActual.pesoTotal -= objetos[nivel].peso;
    solucionActual.beneficioTotal -= objetos[nivel].beneficio;
}

// Función principal de backtracking
void MochilaBacktracking(int nivel, SolucionParcial& solucionActual) {
    while (true) {
        Generar(nivel, solucionActual);

        if (Solucion(nivel, solucionActual)) {
            if (solucionActual.beneficioTotal > mejorSolucion.beneficioTotal) {
                mejorSolucion = solucionActual;
            }
        } else if (Criterio(nivel, solucionActual)) {
            MochilaBacktracking(nivel + 1, solucionActual);
        }

        Retroceder(nivel, solucionActual);

        if (!MasHermanos(nivel, solucionActual)) {
            break;
        }
    }
}

int main() {
    // Inicialización de datos de ejemplo
    objetos = {{2, 10}, {5, 30}, {8, 40}, {2, 20}};
    capacidadMaxima = 10;

    // Inicialización de la mejor solución encontrada
    mejorSolucion = {{}, 0, 0};

    // Inicialización de la solución parcial actual
    SolucionParcial solucionActual = {{}, 0, 0};

    // Llamada al algoritmo de backtracking
    MochilaBacktracking(0, solucionActual);

    // Mostrar la mejor solución encontrada
    cout << "Mejor solución encontrada:" << endl;
    cout << "Objetos seleccionados: ";
    for (int i = 0; i < mejorSolucion.seleccionados.size(); ++i) {
        cout << mejorSolucion.seleccionados[i] << " ";
    }
    cout << endl;
    cout << "Peso total: " << mejorSolucion.pesoTotal << endl;
    cout << "Beneficio total: " << mejorSolucion.beneficioTotal << endl;

    return 0;
}




//
#include <iostream>
#include <vector>

using namespace std;

int nivel;
vector<int> s;
int voa;
vector<int> soa;
int pact, bact;
vector<int> p={1,2,3,4};
vector<int> b={2,3,4,5};
int n = p.size();
int M = 7;
vector<int> sInicial(n, -1);

void Generar(int &nivel, vector<int>& s) {
    s[nivel] = s[nivel] + 1;
    pact = pact + p[nivel] * s[nivel];
    bact = bact + b[nivel] * s[nivel];
}

bool Solucion(int &nivel, vector<int>& s) {
    return ((nivel == n) && (pact <= M));
}

bool Criterio(int &nivel, vector<int>& s) {
    return ((nivel < n) && (pact <= M));
}

bool MasHermanos(int &nivel, vector<int>& s) {
    return (s[nivel] < 1);
}

void Retroceder(int& nivel, vector<int>& s) {
    pact = pact - p[nivel] * s[nivel];
    bact = bact - b[nivel] * s[nivel];
    s[nivel] = -1;
    nivel = nivel - 1;
}

void Backtracking(vector<int>& sInicial) {
    nivel = 0;
    s = sInicial;
    voa = -1;
    //soa
    pact = 0;
    bact = 0;
    n--;
    while (nivel > -1) {

        Generar(nivel, s);
        if (Solucion(nivel, s) && (bact > voa)) {
            voa = bact;
            soa = s;
        }
        if (Criterio(nivel, s)) {
            nivel++;
        } 
        else 
        {
            while ((!MasHermanos(nivel, s)) && (nivel > -1)) 
            {
                Retroceder(nivel, s);
            }
        }
    }
}


int main()
{
    Backtracking(sInicial);
    cout << "Mejor solucion: ";
    for (int i = 0; i < soa.size(); i++) 
    {
        cout << soa[i] << " ";
    }
    cout << endl;

    return 0;
}