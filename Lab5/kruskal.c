#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];

// Find set of an element i (with path compression)
int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

// Union of two sets
void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Compare function for sorting edges by weight
int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Edge edges[], int n, int e) {
    Edge result[MAX];
    int total_cost = 0, count = 0;

    // Sort edges by weight
    qsort(edges, e, sizeof(Edge), compare);

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            result[count++] = edges[i];
            total_cost += edges[i].weight;
            unionSets(u, v);
        }
    }

    printf("Edges in Minimum Spanning Tree:\n");
    for (int i = 0; i < count; i++)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
    
    printf("Minimum Cost = %d\n", total_cost);
}

int main() {
    int n, e;
    Edge edges[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter %d edges (u v weight):\n", e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, n, e);
    return 0;
}
