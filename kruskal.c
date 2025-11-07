#include <stdio.h>

#define MAX 100

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int n, int cost[MAX][MAX]) {
    int edges = 0, mincost = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Edge\tWeight\n");

    while (edges < n - 1) {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (find(i) != find(j) && cost[i][j] < min && cost[i][j] != 0)
                    min = cost[i][j], a = i, b = j;

        unionSet(a, b);
        printf("%d - %d\t%d\n", a, b, min);
        mincost += min;
        edges++;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Total cost of MST: %d\n", mincost);
}

int main() {
    int n, cost[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    kruskal(n, cost);
    return 0;
}
