#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 20
#define MAX_NAME  30

typedef struct {
    char name[MAX_NAME];
} Node;

typedef struct {
    int adj[MAX_NODES][MAX_NODES];
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

// Fonctions
void initGraph(Graph *g);
int addNode(Graph *g, const char *name);
void addEdge(Graph *g, int src, int dest);
void bfsPropagation(Graph *g, int start);

#endif
