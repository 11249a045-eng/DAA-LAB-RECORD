#include <stdio.h>
#include <stdlib.h>
int comparator(const void *p1, const void *p2) {
    const int *a = (const int *)p1;
    const int *b = (const int *)p2;
    return a[2] - b[2];
}
void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;

    return parent[component] = findParent(parent, parent[component]);
}
void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}
int kruskalAlgo(int vertices, int edges, int edgeList[edges][3]) {
    qsort(edgeList, edges, sizeof(edgeList[0]), comparator);

    int parent[vertices];
    int rank[vertices];

    makeSet(parent, rank, vertices);

    int minCost = 0;

    for (int i = 0; i < edges; i++) {
        int u = edgeList[i][0];
        int v = edgeList[i][1];
        int wt = edgeList[i][2];

        int setU = findParent(parent, u);
        int setV = findParent(parent, v);
        if (setU != setV) {
            minCost += wt;
            unionSet(setU, setV, parent, rank);
        }
    }

    return minCost;
}
int main() {
    int edgeList[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int vertices = 4;
    int edges = 5;

    printf("Minimum Cost: %d\n", kruskalAlgo(vertices, edges, edgeList));

    return 0;
}
