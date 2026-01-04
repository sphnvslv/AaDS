#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    int adj[101][101] = { 0 };

    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;

        adj[u - 1][v - 1] = 1;
        adj[v - 1][u - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << adj[i][j];

            if (j < n - 1) {
                out << " ";
            }
        }
        out << endl;
    }

    in.close();
    out.close();
    return 0;
}