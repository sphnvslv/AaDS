#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 10002;
const int MAXM = 200002;
const long long INF = 1LL << 60;

struct Edge {
    int to;
    int weight;
    int next;
};

struct HeapNode {
    long long dist;
    int vert;

    bool operator>(const HeapNode& other) const {
        return dist > other.dist;
    }
};

Edge edges[MAXM];
int head[MAXN];
int deg[MAXN];
long long dist[MAXN];
int prevVert[MAXN];
bool visited[MAXN];
int edgeCount = 0;

void addEdge(int u, int v, int w) {
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;
}

void rebuildPath(int start, int end, int* path, int& pathLen) {
    int cur = end;
    pathLen = 0;

    while (cur != -1) {
        path[pathLen++] = cur;
        cur = prevVert[cur];
    }

    for (int i = 0; i < pathLen / 2; i++) {
        int temp = path[i];
        path[i] = path[pathLen - 1 - i];
        path[pathLen - 1 - i] = temp;
    }
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int n, k, start, end;
    scanf("%d %d", &n, &k);
    scanf("%d %d", &start, &end);

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        dist[i] = INF;
        prevVert[i] = -1;
        visited[i] = false;
        deg[i] = 0;
    }

    for (int i = 0; i < k; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        addEdge(v, u, w);

        deg[u]++;
        deg[v]++;
    }

    dist[start] = 0;
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> pq;

    HeapNode startNode;
    startNode.dist = 0;
    startNode.vert = start;
    pq.push(startNode);

    while (!pq.empty()) {
        HeapNode cur = pq.top();
        pq.pop();

        int u = cur.vert;
        long long d = cur.dist;

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        if (u == end) {
            break;
        }

        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to;
            int w = edges[e].weight;

            long long waitTime = 0;
            if (v != end) {
                waitTime = deg[v];
            }

            if (dist[v] > d + w + waitTime) {
                dist[v] = d + w + waitTime;
                prevVert[v] = u;

                HeapNode nextNode;
                nextNode.dist = dist[v];
                nextNode.vert = v;
                pq.push(nextNode);
            }
        }
    }

    printf("%lld\n", dist[end]);

    int path[MAXN];
    int pathLen = 0;
    rebuildPath(start, end, path, pathLen);

    for (int i = 0; i < pathLen; i++) {
        if (i > 0) printf(" ");
        printf("%d", path[i]);
    }
    printf("\n");

    return 0;
}