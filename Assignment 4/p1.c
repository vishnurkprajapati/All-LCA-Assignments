#include <stdio.h>
#include <stdlib.h>

int take_positive_integer_user_input(char message[]) {
    int input_integer;
    do {
        printf("%s", message);
        scanf("%d", &input_integer);
    } while (input_integer <= 0);
    return input_integer;
}

void print_matrix(int rows, int columns, int matrix[rows][columns]) {
    printf("\nResultant Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = take_positive_integer_user_input("Enter number of rows (non-zero): ");
    int columns = take_positive_integer_user_input("Enter number of columns (non-zero): ");

    int matrix1[rows][columns];
    int matrix2[rows][columns];
    int matrix_sum[rows][columns];

    printf("\nEnter the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element (%d, %d): ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element (%d, %d): ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Add elements using nested loops
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    print_matrix(rows, columns, matrix_sum);

    return EXIT_SUCCESS;
}
