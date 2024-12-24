#include <stdio.h>

int a[10][10], visited[10], n, cost = 0;

void get() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter elements of row %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nThe cost matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int least(int currentCity) {
    int minCost = 999, nextCity = 999;

    for (int i = 0; i < n; i++) {
        if (a[currentCity][i] != 0 && !visited[i]) {
            if (a[currentCity][i] < minCost) {
                minCost = a[currentCity][i];
                nextCity = i;
            }
        }
    }

    if (minCost != 999) {
        cost += minCost;
    }
    return nextCity;
}

void mincost(int city) {
    visited[city] = 1;
    printf("%d -> ", city + 1);

    int nextCity = least(city);
    if (nextCity == 999) {
        nextCity = 0;
        printf("%d", nextCity + 1);
        cost += a[city][nextCity];
        return;
    }
    mincost(nextCity);
}

void put() {
    printf("\n\nMinimum cost: %d\n", cost);
}

int main() {
    get();
    printf("\nThe path is: \n\n");
    mincost(0);
    put();
    return 0;
}