#include<stdio.h>
#include<time.h>

int recursiveBinarySearch(int arr[],int low,int high,int key){
    if(high < low)
        return -1;
    int mid = low + (high - low)/2
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key){
        return recursiveBinarySearch(arr,low,mid-1,key);
    else
        return recursiveBinarySearch(arr,mid+1,high,key);
    }
}
    int main(){
        int n = 10000;
        int arr[n];
        for(int i =0;i<n;i++){
            arr[i] = i;
        }
        int key = 99999;
        clock_t start,end;
        double CPU_time_used;
        start = clock();
        int result =  recursiveBinarySearch(arr,0,n-1,key);
        end = clock();
        CPU_time_used = ((double)(end-start))
        if(result!=1)
            printf("Elements found at index%d\n",result);
        else
            printf("Element not found\n",CPU_time_used);
        return 0;
    }