#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define N 5

bool isSubsetSum(int set[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    clock_t start_time = clock();

    int set[N] = {3, 34, 4, 12, 5};
    int sum = 9;

    if (isSubsetSum(set, N, sum))
        printf("Subset with the given sum exists.\n");
    else
        printf("No subset with the given sum exists.\n");

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTime Complexity Analysis:\n");
    printf("Theoretical: O(2^N)\n");
    printf("Empirical (CPU Time): %.6f seconds\n", time_taken);

    return 0;
}
