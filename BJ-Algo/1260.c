#include <stdio.h>
#define true 1
#define false 0
#define kSize 1001

void DFS(const int matrix[][kSize], int v);
void BFS(const int matrix[][kSize], int v);

int main()
{
    int i, src, dst;
    int num_vertex, num_edge, start_vertex;
    int matrix[kSize][kSize] = {0}; // Discard 0 vertex.
    scanf("%d %d %d", &num_vertex, &num_edge, &start_vertex);
    for (i = 0; i < num_edge; ++i) {
        scanf("%d %d", &src, &dst);
        matrix[src][dst] = true;
        matrix[dst][src] = true;
    }
    DFS(matrix, start_vertex);
    printf("\n");
    BFS(matrix, start_vertex);
    return 0;
}

void DFS(const int matrix[][kSize], int v)
{
    static int visited[1001] = {0, };
    int w;
    visited[v] = true;
    printf("%d ", v);
    for (w = 0; w < kSize; ++w) {
        if (matrix[v][w] && !visited[w])
            DFS(matrix, w);
    }
}

void BFS(const int matrix[][kSize], int v)
{
    static int visited[1001] = {0, };
    int queue[kSize];
    int front = -1;
    int rear = -1;
    int w, u;
    visited[v] = true;

    printf("%d ", v);
    queue[++rear] = v;
    while (front != rear) {
        w = queue[++front];
        for (u = 0; u < kSize; ++u) {
            if (matrix[w][u] && !visited[u]) {
                queue[++rear] = u;
                visited[u] = true;
                printf("%d ", u);
            }
        }
    }
}