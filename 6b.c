#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 < r2) ? 1 : -1;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), compare);
    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    clock_t start_time = clock();

    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    int n = sizeof(arr) / sizeof(arr[0]);

    double max_value = fractionalKnapsack(W, arr, n);
    printf("Maximum value in knapsack = %.2f\n", max_value);

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTime Complexity Analysis:\n");
    printf("Theoretical: O(N log N) (due to sorting)\n");
    printf("Empirical (CPU Time): %.6f seconds\n", time_taken);

    return 0;
}
