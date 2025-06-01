#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];  // Adjacency matrix
int indegree[MAX];  // To store indegree of nodes
int queue[MAX];     // For BFS traversal
int front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void topologicalSort(int V) {
    // Compute indegrees
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++) {
            if (adj[j][i] == 1)
                indegree[i]++;
        }
    }

    // Enqueue all vertices with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    printf("Topological Order: ");
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        // Reduce indegree of neighbors
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(v);
            }
        }
    }

    if (count != V)
        printf("\nGraph has a cycle. Topological sort not possible.\n");
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v) where u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort(V);

    return 0;
}
