#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    int* heap = new int[n + 1]; 

    for (int i = 1; i <= n; i++) {
        in >> heap[i];
    }

    bool isHeap = true;

    for (int i = 1; i <= n; i++) {
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        if (leftChild <= n) {
            if (heap[i] > heap[leftChild]) {
                isHeap = false;
                break;
            }
        }

        if (rightChild <= n) {
            if (heap[i] > heap[rightChild]) {
                isHeap = false;
                break;
            }
        }
    }

    if (isHeap) {
        out << "Yes";
    }
    else {
        out << "No";
    }

    delete[] heap;

    return 0;
}