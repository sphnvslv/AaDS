#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

struct Node {
    long long value;
    long long min;
    long long max;
};

int main() {

    ifstream in("bst.in");
    ofstream out("bst.out");

    int n;
    in >> n;

    Node* nodes = new Node[n + 1];
    int* parent = new int[n + 1];

    in >> nodes[1].value;
    nodes[1].min = LLONG_MIN;
    nodes[1].max = LLONG_MAX;
    parent[1] = 1;

    bool isBst = true;

    for (int i = 2; i <= n; i++) {

        long long value;
        int parentStr;
        char letter;

        in >> value >> parentStr >> letter;

        int parentInd = parentStr;
        long long parentValue = nodes[parentInd].value;

        nodes[i].value = value;
        parent[i] = i;

        if (letter == 'L') {
            nodes[i].min = nodes[parentInd].min;
            nodes[i].max = parentValue - 1; 
        }
        else {
            nodes[i].min = parentValue;
            nodes[i].max = nodes[parentInd].max;
        }

        if (value < nodes[i].min || value > nodes[i].max) {
            isBst = false;
            for (int j = i + 1; j <= n; j++) {
                in >> value >> parentStr >> letter;
            }
            break;
        }
    }

    if (isBst) {
        out << "YES";
    }
    else {
        out << "NO";
    }

    delete[] nodes;
    delete[] parent;

    in.close();
    out.close();

    return 0;
}