#include <stdio.h>

#define MAX 100

int main(void) {
    int n, a[MAX][MAX], visited[MAX] = {0}, queue[MAX];
    int start, front = 0, rear = 0;

    printf("Enter number of vertices: "); scanf("%d", &n);
    if (n < 1 || n > MAX) { printf("Invalid number of vertices.\\n"); return 1; }

    printf("Enter adjacency matrix (%d x %d):\\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex (1-%d): ", n); scanf("%d", &start);
    if (start < 1 || start > n) { printf("Invalid starting vertex.\\n"); return 1; }
    start--;

    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS visit order: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v + 1);
        for (int i = 0; i < n; i++) {
            if (a[v][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\\n");
    printf("Only vertices reachable from the starting vertex are visited.\\n");
    return 0;
}
