#include <stdio.h>
#include <time.h>

int fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

void fibIterative(int n) {
    int a = 0, b = 1, next;
    printf("Iterative Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int n = 10;

    clock_t start_iter = clock();
    fibIterative(n);
    clock_t end_iter = clock();
    double time_iter = (double)(end_iter - start_iter) / CLOCKS_PER_SEC;

    clock_t start_rec = clock();
    printf("Recursive Fibonacci Series: ");
    for (int i = 0; i < n; i++)
        printf("%d ", fibRecursive(i));
    clock_t end_rec = clock();
    double time_rec = (double)(end_rec - start_rec) / CLOCKS_PER_SEC;

    printf("\n\nTime Complexity Analysis:\n");
    printf("Iterative: O(N)\n");
    printf("Recursive: O(2^N)\n");
    printf("Empirical Time (Iterative): %.6f seconds\n", time_iter);
    printf("Empirical Time (Recursive): %.6f seconds\n", time_rec);

    return 0;
}
