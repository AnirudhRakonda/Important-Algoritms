#include <stdio.h>
#define max 99

int main() {
    float weight[max], profit[max], ratio[max], temp, capacity, total_val = 0;
    int i, j, n;

    printf("Enter number of items in the sack: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter capacity of the sack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            total_val += profit[i];
            capacity -= weight[i];
        } else {
            total_val += ratio[i] * capacity;
            break;
        }
    }

    printf("Total value of the sack: %.2f\n", total_val);
}
