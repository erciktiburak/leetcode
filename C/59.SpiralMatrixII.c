#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;

    while (num <= n * n) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }

    // Set return values
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return matrix;
}

int main() {
    int n = 3;
    int returnSize, *returnColumnSizes;
    int** result = generateMatrix(n, &returnSize, &returnColumnSizes);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}
