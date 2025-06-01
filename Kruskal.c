#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX];

// Function to find the root of a set
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to union two sets
void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Compare function for sorting edges
int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

void kruskal(int n, int e) {
    int i, j, count = 0;
    int minCost = 0;

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, e, sizeof(Edge), compare);

    printf("Edge \tWeight\n");

    for (i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            unionSet(u, v);
            minCost += edges[i].weight;
            count++;
            if (count == n - 1)
                break;
        }
    }

    printf("Minimum Cost of Spanning Tree: %d\n", minCost);
}

int main() {
    int n = 5; // Number of vertices
    int e = 7; // Number of edges

    // Define the edges: u, v, weight
    edges[0] = (Edge){0, 1, 2};
    edges[1] = (Edge){0, 3, 6};
    edges[2] = (Edge){1, 2, 3};
    edges[3] = (Edge){1, 3, 8};
    edges[4] = (Edge){1, 4, 5};
    edges[5] = (Edge){2, 4, 7};
    edges[6] = (Edge){3, 4, 9};

    kruskal(n, e);

    return 0;
}
