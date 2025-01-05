#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 20
int board[MAX][MAX]; 
int x[MAX];          

void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int place(int k, int i) {
    for (int j = 1; j < k; j++) { 
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) { 
            return 0;
        }
    }
    return 1;
}

void Nqueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {           
            x[k] = i;               
            board[k - 1][i - 1] = 1;

            if (k == n) {
                print(n); 
            } else {
                Nqueen(k + 1, n); 
            }

            board[k - 1][i - 1] = 0;
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens (<20): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0; 
        }
    }

    Nqueen(1, n); 
    return 0;
}
