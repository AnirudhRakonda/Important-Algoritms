#include <stdio.h>
#define max 99

int high(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int p[max], wt[max], n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter profit and weight of item %d: ", i);
        scanf("%d %d", &p[i], &wt[i]);
    }

    printf("Enter the capacity of the bag: ");
    scanf("%d", &capacity);

    int mat[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                mat[i][w] = 0;
            } else if (wt[i] <= w) {
                mat[i][w] = high(p[i] + mat[i - 1][w - wt[i]], mat[i - 1][w]);
            } else {
                mat[i][w] = mat[i - 1][w];
            }
        }
    }

    printf("Max profit that can be achieved is: %d\n", mat[n][capacity]);

    return 0;
}
