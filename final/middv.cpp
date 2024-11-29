#include <iostream>
#include <vector>
using namespace std;

double divideYVenceras(vector<int>& arr, int start, int end) {
    if (start == end) 
        return arr[start]; // Caso base: un solo elemento
    
    int mid = (start + end) / 2;
    double left = divideYVenceras(arr, start, mid);
    double right = divideYVenceras(arr, mid + 1, end);
    
    return (left * (mid - start + 1) + right * (end - mid)) / (end - start + 1);
}

int main() {
    vector<int> arr = {5, 9, 2, 4, 3, 8, 1};
    double media = divideYVenceras(arr, 0, arr.size() - 1);
    cout << "La media es: " << media << endl;
    return 0;
}
