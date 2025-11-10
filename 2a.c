#include<stdio.h>
void insertionSort(int array[],int n){
    int i,element ,j;
    for(i=1;i<n;i++){
        element = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > element){
            array[j+1]=array[j];
            j = j - 1;
        }
        array[j+1] = element;
    }
}
void printArray(int array[],int n){
    int i;
    for(i = o;i < n;i++)
        print("%d",array[i]);
        printf("\n");
}
int main(){
    clock_t start,end;
    int arr[] = {50,23,9,18,61,32};
    start = clock();
    int n = sizeof(arr)/sizeof(arr[0]);
    end = clock();
    printf("\nBefore sorting:");
    double CPU_time_used;
    printArray(arr,n);
    CPU_time_used = ((double)(end-start)/CLOCKS_per_sec);
    insertionSort(arr,n);
    printf("\nAfter sorting:");
    printf("Time Taken:",CPU_time_used);
    printArray(arr,n);
    CPU_time_used = ((double)(end-start)/CLOCKS_per_sec);
    return 0;
}