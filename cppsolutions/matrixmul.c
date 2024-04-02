#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int rows, int cols) {
    int **matrix;
    int i;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    return matrix;
}

int main() {
    int rows, cols, i, j;
    int rows2, cols2;
    int **matrix1, **matrix2, **ans;

    printf("Enter the number of rows in matrix 1: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in matrix 1: ");
    scanf("%d", &cols);
    printf("Enter the number of rows in matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns in matrix 2: ");
    scanf("%d", &cols2);

    if (cols == rows2) {
        matrix1 = allocateMatrix(rows, cols);
        matrix2 = allocateMatrix(rows2, cols2);
        ans = allocateMatrix(rows, cols2);

        printf("Enter the elements of matrix 1:\n");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("Enter the elements of matrix 2:\n");
        for (i = 0; i < rows2; i++) {
            for (j = 0; j < cols2; j++) {
                scanf("%d", &matrix2[i][j]);
            }
        }

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols2; j++) {
                ans[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    ans[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        printf("Result of matrix multiplication:\n");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols2; j++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }

        for (i = 0; i < rows; i++) {
            free(matrix1[i]);
            free(ans[i]);
        }
        for (i = 0; i < rows2; i++) {
            free(matrix2[i]);
        }
        free(matrix1);
        free(matrix2);
        free(ans);
    } else {
        printf("Entered matrix dimensions cannot be multiplied.\n");
    }

    return 0;
}
