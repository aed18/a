#include <iostream>
#include <vector>

using namespace std;

// Función para contar la ocurrencia de un elemento en un rango del array
int countInRange(const vector<int>& nums, int num, int low, int high) {
    int count = 0;
    for (int i = low; i <= high; ++i) {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

// Función para encontrar el elemento mayoritario en un rango del array
int findMajorityElementInRange(const vector<int>& nums, int low, int high) {
    if (low == high) {
        return nums[low];
    }

    // División del array
    int mid = low + (high - low) / 2;

    // Conquista
    int leftMajority = findMajorityElementInRange(nums, low, mid);
    int rightMajority = findMajorityElementInRange(nums, mid + 1, high);

    // Combinación
    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    int leftCount = countInRange(nums, leftMajority, low, high);
    int rightCount = countInRange(nums, rightMajority, low, high);

    return (leftCount > rightCount) ? leftMajority : rightMajority;
}

// Función principal para encontrar el elemento mayoritario
int findMajorityElement(const vector<int>& nums) {
    int n = nums.size();

    // Llamar a la función auxiliar para encontrar el elemento mayoritario en todo el array
    return findMajorityElementInRange(nums, 0, n - 1);
}

int main() {
    // Ejemplo de uso
    vector<int> array = {3, 3, 4, 2, 4, 4, 2, 4, 4};

    int majorityElement = findMajorityElement(array);

    if (majorityElement != -1) {
        cout << "El elemento mayoritario es: " << majorityElement << endl;
    } else {
        cout << "No hay elemento mayoritario en el array." << endl;
    }

    return 0;
}
