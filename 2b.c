#include<stdio.h>
struct pair{
    int min;
    int max;
}
struct pair maxminDivideConquer(int arr[],int low,int high){
    struct pair result;
    struct pair left;
    struct pair right;
    int mid;

    if(low== high){
            result.min = arr[low];
            result.max = arr[low];
            return result;
    }
    if(high == low+1){
        if(arr[low]<arr[high]){
            result.min = arr[low];
            result.max = arr[high];
        }
    }
    else{
        result.min = arr[high];
        result.max = arr[low];
    }
    return result;

mid = (low+high)/2;
left = maxminDivideConquer(arr,low,mid);
right = maxminDivideConquer(arr,mid+1,high);

results.max = (left.max > right.max) ? left.max : right.max;
result.min=(left.min < right.min) ? left.min : right.min;
return result;
}
    int main(){
        clock_t start,end;
        int arr[] = {6,4,26,14,33,64,46};
        start = clock();
        int n = sizeof(arr)/sizeof(arr[0]);
        struct pair result = maxminDivideConquer(arr,0,n-1);
        double CPU_time_used;
        printf("Maximum element is :%d\n");
        CPU_time_used = ((double)(end-start)/CLOCKS_per_sec);
        

    }