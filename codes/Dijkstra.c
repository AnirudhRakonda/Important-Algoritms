#include <stdio.h>

#define max 999
#define infinity 9999

void dijkstra(int G[max][max], int n, int start);

int main()
{
    int n, G[max][max], i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    printf("Enter start node value: ");
    scanf("%d", &start);

    dijkstra(G, n, start);

    return 0;
}

void dijkstra(int G[max][max], int n, int start)
{
    int prev[max], vis[max], cost[max][max], dist[max];
    int i, j, c, min, next;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[i][j] = (G[i][j] == 0 && i != j) ? infinity : G[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        prev[i] = start;
        vis[i] = 0;
    }

    dist[start] = 0;
    vis[start] = 1;
    c = 1;


    while (c < n)
    {
        min = infinity;

        for (i = 0; i < n; i++)
        {
            if (!vis[i] && dist[i] < min)
            {
                min = dist[i];
                next = i;
            }
        }

        vis[next] = 1;


        for (i = 0; i < n; i++)
        {
            if (!vis[i] && dist[next] + cost[next][i] < dist[i])
            {
                dist[i] = dist[next] + cost[next][i];
                prev[i] = next;
            }
        }
        c++;
    }


    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("\nDistance of node %d = %d", i, dist[i]);
            printf("\nPath = %d\n", i);
            j = i;

            do
            {
                j = prev[j];
                printf(" <- %d", j);
            } while (j != start);
        }
    }
}
