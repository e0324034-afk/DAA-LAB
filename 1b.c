#include<stdio.h>
#include<time.h>
    int recursionLinearSearch(int arr[],int size,int key,int index){
        if(index >= size)
            return -1;
        if(arr[index]==key)
            return index;
            return recursionLinearSearch(arr,size,key,index+1)
    }
    int main(){
        int n = 10000;
        int arr[n];

        for(int i = 0;i < n;i++){
            arr[i] = i;
        }
        int key = 99999;
        clock_t start,end;
        double CPU_time_used;
        start = clock();
        int result = recursionLinearSearch(arr,n,key,0);
        end = clock();
        CPU_time_used = ((double)(end-start))
        if(result!=1)
            printf("Element found at index%d\n",result);
        else
            printf("Element not found\n");
            printf("Execution time:%fseconds\n",CPU_time_used);
            return 0;
    }