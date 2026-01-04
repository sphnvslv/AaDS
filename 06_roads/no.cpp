#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 100005;

struct Road {
    int u, v;
    bool destroyed;
};

Road roads[MAXN];
int parent[MAXN];
int sz[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return false;
    }

    if (sz[x] < sz[y]) {
        parent[x] = y;
        sz[y] += sz[x];
    }
    else {
        parent[y] = x;
        sz[x] += sz[y];
    }
    return true;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m, q;
    in >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        in >> roads[i].u >> roads[i].v;
        roads[i].destroyed = false;
    }

    int queries[MAXN];
    for (int i = 0; i < q; i++) {
        in >> queries[i];
        roads[queries[i]].destroyed = true;
    }

    for (int i = 1; i <= m; i++) {
        if (!roads[i].destroyed) {
            unite(roads[i].u, roads[i].v);
        }
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            components++;
        }
    }

    char result[MAXN];
    for (int i = q - 1; i >= 0; i--) {
        if (components == 1) {
            result[i] = '1';
        }
        else {
            result[i] = '0';
        }

        int edge_idx = queries[i];
        int u = roads[edge_idx].u;
        int v = roads[edge_idx].v;

        if (unite(u, v)) {
            components--;
        }
    }

    for (int i = 0; i < q; i++) {
        out << result[i];
    }
    out << endl;

    in.close();
    out.close();
    return 0;
}