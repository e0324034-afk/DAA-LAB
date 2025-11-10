#include<stdio.h>
#include<time.h>

int binarySearch(int arr[],int n,int key){
    int low = 0,high = n - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
    if( arr[mid]==key)
        return mid;
    else if(arr[mid]<key)
        low = mid + 1;
    else   
        high = mid - 1;
    }
    return -1;
}

int main(){
    int n = 10000;
    int arr[n];
    for(int i = 0;i < n;i++){
        arr[i] = 1;
    }
    int key = 99999;
    clock_t start,end;
    double CPU_time_used;
    start = clock();
    int result = binarySearch(arr,n,key);
    end = clock();

    CPU_time_used = ((double)(end-start)/2)
    if(result!=1)
        printf("Element found at index%d\n",result);
    else
        printf("Element not found\n");
        printf("Execution time:%fseconds\n",CPU_time_used);
        return 0;
}