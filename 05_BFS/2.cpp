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
    bool inQueue[MAXN] = { false };

    int queue[MAXN];
    int front = 0, back = 0;

    int curLabel = 1;

    for (int start = 1; start <= n; start++) {
        if (labels[start] == 0) {

            queue[back++] = start;
            labels[start] = curLabel++;
            inQueue[start] = true;

            while (front < back) {
                int u = queue[front++];

                for (int v = 1; v <= n; v++) {
                    if (adj[u][v] == 1 && labels[v] == 0 && !inQueue[v]){

                        int insertPos = back;
                        for (int i = back - 1; i >= front; i--) {

                            if (queue[i] < v) {
                                insertPos = i + 1;
                                break;
                            }
                        }

                        for (int i = back; i > insertPos; i--) {
                            queue[i] = queue[i - 1];
                        }

                        queue[insertPos] = v;
                        back++;
                        inQueue[v] = true;
                    }
                }

                for (int i = front; i < back; i++) {
                    if (labels[queue[i]] == 0) {
                        labels[queue[i]] = curLabel++;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", labels[i]);
    }    printf("\n");

    return 0;
}