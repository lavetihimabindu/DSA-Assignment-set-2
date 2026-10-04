#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main(void) {
    int n, w[MAX][MAX], dist[MAX], used[MAX] = {0}, source;

    printf("Enter number of vertices: "); scanf("%d", &n);
    if (n < 1 || n > MAX) { printf("Invalid number of vertices.\\n"); return 1; }

    printf("Enter weighted adjacency matrix (0 means no edge; weights must be non-negative):\\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
            if (w[i][j] < 0) { printf("Dijkstra does not support negative weights.\\n"); return 1; }
        }
    }

    printf("Enter source vertex (1-%d): ", n); scanf("%d", &source);
    if (source < 1 || source > n) { printf("Invalid source vertex.\\n"); return 1; }
    source--;

    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[source] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1, best = INF;
        for (int i = 0; i < n; i++)
            if (!used[i] && dist[i] < best) { best = dist[i]; u = i; }
        if (u == -1) break;
        used[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!used[v] && w[u][v] > 0 && dist[u] != INF &&
                dist[u] + w[u][v] < dist[v]) {
                dist[v] = dist[u] + w[u][v];
            }
        }
    }

    printf("Shortest distances from vertex %d:\\n", source + 1);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("To vertex %d: Unreachable\\n", i + 1);
        else printf("To vertex %d: %d\\n", i + 1, dist[i]);
    }
    return 0;
}
