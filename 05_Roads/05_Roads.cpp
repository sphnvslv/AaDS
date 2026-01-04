#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> parent;
vector<int> height;

void makeSet(int v) {
    parent[v] = v;
    height[v] = 0;
}

int findSet(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

bool unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a != b) {
        if (height[a] < height[b]) {
            swap(a, b);
        }
        parent[b] = a;

        if (height[a] == height[b]) {
            height[a]++;
        }
        return true;
    }
    return false;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q;
    scanf("%d %d", &n, &q);

    parent.resize(n + 1);
    height.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        makeSet(i);
    }

    int components = n;

    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (unionSets(u, v)) {
            components--;
        }

        printf("%d\n", components);
    }

    return 0;
}