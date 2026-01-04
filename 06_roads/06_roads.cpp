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
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, q;
    fin >> n >> m >> q;

    // Инициализация DSU
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    // Чтение ребер
    for (int i = 1; i <= m; i++) {
        fin >> roads[i].u >> roads[i].v;
        roads[i].destroyed = false;
    }

    // Отметим разрушенные ребра
    int queries[MAXN];
    for (int i = 0; i < q; i++) {
        fin >> queries[i];
        roads[queries[i]].destroyed = true;
    }

    // Построим начальный граф без разрушенных ребер
    for (int i = 1; i <= m; i++) {
        if (!roads[i].destroyed) {
            unite(roads[i].u, roads[i].v);
        }
    }

    // Подсчитаем количество компонент в начальном состоянии
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            components++;
        }
    }

    // Обрабатываем запросы в обратном порядке (восстанавливаем дороги)
    char result[MAXN];
    for (int i = q - 1; i >= 0; i--) {
        result[i] = (components == 1) ? '1' : '0';

        int edge_idx = queries[i];
        int u = roads[edge_idx].u;
        int v = roads[edge_idx].v;

        // Восстанавливаем дорогу
        if (unite(u, v)) {
            components--;
        }
    }

    // Вывод результатов
    for (int i = 0; i < q; i++) {
        fout << result[i];
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}