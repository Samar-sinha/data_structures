#include<stdio.h>
void insertion_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int j =  i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            j--;
        }
    }
}
int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements : \n");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    insertion_sort(arr, n);
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
    return 0;
}