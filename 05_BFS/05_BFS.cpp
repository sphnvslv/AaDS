#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 105; 

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    int adj[MAXN][MAXN];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int labels[MAXN] = { 0 };

    int queue[MAXN];
    int front = 0, rear = 0;

    int curLabel = 1;

    for (int start = 1; start <= n; start++) {
        if (labels[start] == 0) {

            queue[rear++] = start;
            labels[start] = curLabel++;

            while (front < rear) {
                int u = queue[front++];

                for (int v = 1; v <= n; v++) {
                    if (adj[u][v] == 1 && labels[v] == 0) {

                        queue[rear++] = v;
                        labels[v] = curLabel++;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", labels[i]);
    }

    return 0;
}