#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

const int MAXN = 750005;

struct Edge {
    int u, v;
    bool destroyed;
};

int parent[MAXN];
int height[MAXN];
Edge edges[MAXN];
int quer[MAXN];

int findSet(int v) {
    if (v == parent[v]) {
        return v;
    }
    else {
        parent[v] = findSet(parent[v]);
        return parent[v];
    }
}

bool unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a == b) {
        return false;
    }
    if (height[a] < height[b]) {
        swap(a, b);
    }
    parent[b] = a;
    if (height[a] == height[b]) {
        height[a]++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        height[i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v;
        edges[i].destroyed = false;
    }

    for (int i = 0; i < q; i++) {
        cin >> quer[i];
        edges[quer[i]].destroyed = true;
    }

    int components = n;

    for (int i = 1; i <= m; i++) {
        if (!edges[i].destroyed && unionSets(edges[i].u, edges[i].v)) {
            components--;
        }
    }

    string res(q, '0');

    for (int i = q - 1; i >= 0; i--) {
        if (components == 1) {
            res[i] = '1';
        }
        else res[i] = '0';

        int idx = quer[i];
        if (unionSets(edges[idx].u, edges[idx].v)) {
            components--;
        }
    }

    cout << res << '\n';
    return 0;
}
