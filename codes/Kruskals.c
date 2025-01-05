#include <stdio.h>
int p[10];
int find(int i) {
    while (p[i])
        i = p[i];
    return i;
}
int uni(int i, int j) {
    if (i != j) {
        p[j] = i;
        return 1;
    }
    return 0;
}
int main() {
    int g[10][10], n, i, j, a, b, u, v, min, c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    while (c < n - 1) {
        min = 99999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (g[i][j] && g[i][j] < min) {
                    min = g[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }
        if (uni(find(u), find(v))) {
            printf("%d-%d ", a, b);
            c++;
        }
        g[a][b] = g[b][a] = 99999;
    }
    return 0;
}