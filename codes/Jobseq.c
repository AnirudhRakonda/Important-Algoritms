
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Jobs {
   char id;
   int dead;
   int profit;
} Jobs;

int compare(const void* a, const void* b){
   Jobs* temp1 = (Jobs*)a;
   Jobs* temp2 = (Jobs*)b;
   return (temp2->profit - temp1->profit);
}

int min(int num1, int num2){
   return (num1 >= num2) ? num2 : num1;
}
int main(){
   Jobs arr[] = { 
        {'a', 2,  60},
        {'b', 1, 100},
        {'c', 3,  20},
        {'d', 2,  40},
        {'e', 1,  20},
   };
   int n = sizeof(arr) / sizeof(arr[0]);
   qsort(arr, n, sizeof(Jobs), compare);
   printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(int i = 0; i< n; i++) {
        printf("%10c %10i %10i\n", arr[i].id, arr[i].dead, arr[i].profit);
    }
   int result[n];
   bool slot[n];
    int maxProfit = 0;
   for (int i = 0; i < n; i++)
      slot[i] = false;
   for (int i = 0; i < n; i++) {
      for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
         if (slot[j] == false) {
            result[j] = i;
            maxProfit += arr[i].profit;
            slot[j] = true;
            break;
         }
      }
   }
   printf("Following is maximum profit sequence of Jobs: ");
   for (int i = 0; i < n; i++)
      if (slot[i]){
        printf("%c ", arr[result[i]].id);
      }

    printf("\nMaximum Profit : %d",maxProfit);
   return 0;
}