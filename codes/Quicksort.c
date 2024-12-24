#include<stdio.h>
void swap(int * a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int nums[] , int l , int h){
    int i = l,j=h;
    int pivot = nums[l];
    while (i<j)
    {
        do
        {
            i++;
        } while (nums[i] <= pivot);
        do
        {
            j--;
        } while (nums[j] > pivot);

        if(i<j){
            swap(&nums[i],&nums[j]);
        }
    }
    swap(&nums[l] , &nums[j]);
    return j;
}
void quickSort(int nums[] , int l,int h){
    if(l<h){
        int j = partition(nums,l,h);
        quickSort(nums,l,j);
        quickSort(nums,j+1,h);
    }
}
int main(){
    int nums[] = {4 ,2, 8 ,6};
    int l = 0;
    int h = (sizeof(nums) / sizeof(nums[0])) - 1;
    quickSort(nums,l,h);

    for(int i=0;i<=h;i++){
        printf("%d " ,nums[i]);
    }

}