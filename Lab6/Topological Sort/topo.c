#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], stack[MAX], top = -1;
int V;  // number of vertices

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i])
            dfs(i);
    }
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i);

    printf("Topological Order: ");
    while (top != -1)
        printf("%d ", stack[top--]);
}

int main() {
    int E, u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();
    return 0;
}
