#include<stdio.h>
#include<time.h>
int linearSearch(int arr[],int n,int key){
        for(int i=0;i<n;i++){
            if(arr[1]==key)
                return i;
        }
        return -1;
}

int main(){
    int n = 10000;
    int arr[n];
    int key = 99999;
    for(int i = 0;i<n;i++){
        arr[i] = i;
    }
    clock_t start,end;
    double CPU_time_used;
    start = clock();
    int result = linearSearch(arr,n,key);
    end =  clock();
    CPU_time_used = ((double)(end-start))
    if(result != 1)
        printf("Element found at index%d\n",result);
    else
        printf("Element not found\n");
    printf("Execution time:%fseconds\n",CPU_time_used);
    return 0;
}