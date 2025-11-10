#include <stdio.h>
#include <string.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main() {
    clock_t start_time = clock();

    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    int length = LCS(X, Y, m, n);
    printf("Length of Longest Common Subsequence = %d\n", length);

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTime Complexity Analysis:\n");
    printf("Theoretical: O(m × n)\n");
    printf("Empirical (CPU Time): %.6f seconds\n", time_taken);

    return 0;
}
