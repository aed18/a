#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Estructura para representar un punto en el plano
struct Point {
    int x, y;
};

// Función para calcular la distancia euclidiana entre dos puntos
double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Función para comparar puntos en función de sus coordenadas x
bool compareByX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

// Función para comparar puntos en función de sus coordenadas y
bool compareByY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

// Función principal para encontrar el par de puntos más cercano
pair<Point, Point> findClosestPair(vector<Point>& pointsByX, vector<Point>& pointsByY, int low, int high) {
    if (high - low <= 3) {
        // Caso base: usar fuerza bruta para conjuntos pequeños de puntos
        // ...
    }

    // División del conjunto en dos partes
    int mid = low + (high - low) / 2;
    vector<Point> leftPointsByX(pointsByX.begin() + low, pointsByX.begin() + mid + 1);
    vector<Point> rightPointsByX(pointsByX.begin() + mid + 1, pointsByX.begin() + high + 1);

    // Recursión en ambas mitades
    pair<Point, Point> leftClosestPair = findClosestPair(leftPointsByX, pointsByY, low, mid);
    pair<Point, Point> rightClosestPair = findClosestPair(rightPointsByX, pointsByY, mid + 1, high);

    // Encontrar la distancia mínima entre las dos mitades
    double minDistance = min(calculateDistance(leftClosestPair.first, leftClosestPair.second),
                             calculateDistance(rightClosestPair.first, rightClosestPair.second));

    // Construir un vector de puntos dentro de la franja central
    vector<Point> strip;
    for (const Point& point : pointsByY) {
        if (abs(point.x - pointsByX[mid].x) < minDistance) {
            strip.push_back(point);
        }
    }

    // Encontrar el par de puntos más cercano en la franja central
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDistance; ++j) {
            double distance = calculateDistance(strip[i], strip[j]);
            if (distance < minDistance) {
                minDistance = distance;
                leftClosestPair = {strip[i], strip[j]};
            }
        }
    }

    // Devolver el par de puntos más cercano entre las dos mitades
    return min(leftClosestPair, rightClosestPair);
}

int main() {
    // Ejemplo de uso
    vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

    // Ordenar puntos por coordenada x y y
    vector<Point> pointsByX = points;
    vector<Point> pointsByY = points;
    sort(pointsByX.begin(), pointsByX.end(), compareByX);
    sort(pointsByY.begin(), pointsByY.end(), compareByY);

    // Encontrar el par de puntos más cercano
    pair<Point, Point> closestPair = findClosestPair(pointsByX, pointsByY, 0, points.size() - 1);

    // Imprimir el resultado
    cout << "Par de puntos más cercano: (" << closestPair.first.x << ", " << closestPair.first.y << ") y ("
         << closestPair.second.x << ", " << closestPair.second.y << ")\n";

    return 0;
}
