#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    int** matrix = new int* [n + 1];
    for (int i = 1; i <= n; i++) {
        matrix[i] = new int[n + 1];

        for (int j = 1; j <= n; j++) {
            in >> matrix[i][j];
        }
    }

    int* parent = new int[n + 1]();

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (matrix[i][j] == 1) {
                parent[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        out << parent[i] << " ";
    }

    for (int i = 1; i <= n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] parent;

    return 0;
}