#include<stdio.h>
void merge(int nums[] , int l, int h){
    int m = (l+h)/2;
    int n1 = m-l+1,n2 = h-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = nums[l+i];
    }   
    for(int j =0;j<n2;j++){
        R[j] = nums[m+1+j];
    }
    int i=0,j=0,k=l;
    while (i<n1 && j<n2)
    {
        if(L[i] <= R[j]){
            nums[k] = L[i];
            i++;
        }
        else{
            nums[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        nums[k] = L[i];
        k++;i++;
    }
    while (j<n2){
        nums[k] = R[j];
        j++,k++;
    }
}
void mergeSort(int nums[] , int l,int h){
    if(l<h){
        int m = (l+h)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,h);
        merge(nums,l,h);
    }
}
int main(){
    int nums[] = {4 ,2, 8 ,6};
    int l = 0;
    int h = (sizeof(nums) / sizeof(nums[0])) - 1;
    mergeSort(nums,l,h);

    for(int i=0;i<=h;i++){
        printf("%d " ,nums[i]);
    }

}