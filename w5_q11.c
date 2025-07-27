#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
}

int isCyclicUtil(struct Graph* graph, int v, int visited[], int recStack[]) {

    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[v][i]) {
            if (!visited[i] && isCyclicUtil(graph, i, visited, recStack)) {
                return 1;
            } else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[v] = 0;
    return 0;
}

int isCyclic(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int recStack[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, visited, recStack)) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0); 
    addEdge(graph, 2, 3);

    if (isCyclic(graph)) {
        printf("Graph contains a cycle\n");
    } else {
        printf("Graph does not contain a cycle\n");
    }

    free(graph);
    return 0;
}
