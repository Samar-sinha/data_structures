#include<stdio.h>
void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        int didswap = 0;
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp; 
                didswap = 1;
            }
        }
        if(didswap==0) break;
    }
}
int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements : \n");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    bubble_sort(arr, n);
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
    return 0;
}