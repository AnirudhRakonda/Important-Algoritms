#include <stdio.h>
#define max 999 // A high value representing infinity

void prims(int n, int cost[max][max]);

int main() {
    int n, cost[max][max];


    printf("Enter number of nodes: ");
    scanf("%d", &n);


    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);


            if (i != j && cost[i][j] == 0) {
                cost[i][j] = max;
            }
        }
    }


    prims(n, cost);

    return 0;
}

void prims(int n, int cost[max][max]) {
    int vis[max], u = 0, v = 0, min, min_cost = 0, ne = 0;


    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }

    vis[0] = 1; 

    printf("\nThe edges of the Minimum Spanning Tree are:\n");

    while (ne < n - 1) { 
        min = max;

        
        for (int i = 0; i < n; i++) {
            if (vis[i]) { 
                for (int j = 0; j < n; j++) {
                    if (!vis[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }


        if (!vis[v]) {
            printf("Edge %d: (%d, %d) = %d\n", ne + 1, u + 1, v + 1, min);
            min_cost += min;  
            vis[v] = 1;       
            ne++;             
        }


        cost[u][v] = cost[v][u] = max;
    }

    printf("\nMinimum cost of the spanning tree = %d\n", min_cost);
}
