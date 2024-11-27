#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void monedas(int n, int* c, int p) {
	//creado alamacenador
	int** V = new int* [n + 1];
	for (int i = 0; i <= n; ++i) {
		V[i] = new int[p + 1];
	}
	//inicializamos 
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= p; ++j) {
			if(j == 0)
			{
				V[i][j] = 0;
			}
			else if(i == 0)
			{
				V[i][j] = INT_MAX;
			}
			else
			{
				V[i][j] = 0;
			}
		}
	}
	// Llenar la tabla usando la fórmula de recurrencia
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= p; j++) {
			if (j < *(c+ i - 1)) {
				V[i][j] = V[i - 1][j]; // No tomar la moneda
			}
			else {
				if (V[i][j] - *(c + i - 1) != INT_MAX)
				{
					V[i][j] = min(V[i - 1][j], 1 + V[i][j - *(c + i - 1)]);
				}
				else
				{
					V[i][j] = V[i - 1][j];
				}
			}
		}
	}
	cout << "tabla" << endl;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= p; ++j) {
			if(V[i][j] == INT_MAX)
			{
				cout << " ";
			}
			else
			{
				cout << V[i][j] << " ";
			}
		}
		cout << endl;
	}
	vector<int> solucion(n, 0);
	int i = n, j = p;
	while (i > 0 && j > 0) {
		if (V[i][j] == V[i - 1][j]) {
			--i;
		}
		else {
			solucion[i-1]++;
			j -= *(c + i - 1);
		}
	}
	cout << "Solucion" << endl;
	for (auto value : solucion) {
		cout << value << " ";
	}
	cout << endl;
}
int main() {
	int n = 3;
	int c[] = {1,4,6};
	int p = 8;
	monedas(n, c, p);
	return 0;
}
