#include <stdio.h>
#include <string.h>
#include "graph.h"

// Initialiser graphe
void initGraph(Graph *g) {
    g->node_count = 0;
    for (int i = 0; i < MAX_NODES; i++)
        for (int j = 0; j < MAX_NODES; j++)
            g->adj[i][j] = 0;
}

// Ajouter noeud
int addNode(Graph *g, const char *name) {
    strcpy(g->nodes[g->node_count].name, name);
    return g->node_count++;
}

// Ajouter arête (non orientée)
void addEdge(Graph *g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1;
}

// BFS
void bfsPropagation(Graph *g, int start) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\n[ATTACK PROPAGATION]\n");

    while (front < rear) {
        int current = queue[front++];
        printf("Compromised: %s\n", g->nodes[current].name);

        for (int i = 0; i < g->node_count; i++) {
            if (g->adj[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
