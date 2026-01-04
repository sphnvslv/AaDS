#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int m, c, n;
    in >> m >> c >> n;

    long long* table = new long long[m];
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }

    for (int k = 0; k < n; k++) {
        long long x;
        in >> x;

        int start = x % m;
        bool dupl = false;

        for (int i = 0; i < m; i++) {

            int pos = (start + c * i) % m;
            if (table[pos] == x) {
                dupl = true;
                break;
            }
        }

        if (!dupl) {
            for (int i = 0; i < m; i++) {

                int pos = (start + c * i) % m;
                if (table[pos] == -1) {
                    table[pos] = x;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        out << table[i];
        if (i < m - 1) out << " ";
    }

    delete[] table;
    return 0;
}