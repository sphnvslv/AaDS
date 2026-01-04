#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
using namespace std;

const int MAXN = 105;

int adj[MAXN][MAXN];      
int labels[MAXN];         
int curLabel = 1;    
int n;                    

void dfs(int u) {
    labels[u] = curLabel++;

    for (int v = 1; v <= n; v++) {
        if (adj[u][v] == 1 && labels[v] == 0) {
            dfs(v);
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        labels[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (labels[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", labels[i]);
    }

    return 0;
}