#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 200002;
const int MAXM = 600004;
const long long INF = 1LL << 60;

struct Edge {
    int to;
    int weight;
    int next;
};

struct HeapNode {
    long long dist;
    int vertex;

    bool operator>(const HeapNode& other) const {
        return dist > other.dist;
    }
};

Edge edges[MAXM];
int head[MAXN];
int edgeCount = 0;

void add_edge(int u, int v, int w) {
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;
}

long long dist[MAXN];
bool visited[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        dist[i] = INF;
        visited[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        //add_edge(v, u, w);
    }

    dist[1] = 0;
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> pq;

    HeapNode start;
    start.dist = 0;
    start.vertex = 1;
    pq.push(start);

    while (!pq.empty()) {
        HeapNode cur = pq.top();
        pq.pop();

        int u = cur.vertex;
        long long d = cur.dist;

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        for (int e = head[u]; e != 0; e = edges[e].next) {
            int v = edges[e].to;
            int w = edges[e].weight;

            if (dist[v] > d + w) {
                dist[v] = d + w;

                HeapNode next;
                next.dist = dist[v];
                next.vertex = v;
                pq.push(next);
            }
        }
    }

    printf("%lld\n", dist[n]);

    return 0;
}