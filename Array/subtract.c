#include <stdio.h>

#define MAX_SIZE 100 // Maximum number of non-zero elements in a sparse matrix

// Function to add two sparse matrices in triplet form
int addSparseMatrices(int row1[], int col1[], int val1[], int size1, 
                      int row2[], int col2[], int val2[], int size2, 
                      int resultRow[], int resultCol[], int resultVal[]) {
    int i = 0, j = 0, k = 0;

    // Traverse through both matrices and add corresponding elements
    while (i < size1 && j < size2) {
        // If the rows and columns match, add the values
        if (row1[i] == row2[j] && col1[i] == col2[j]) {
            resultRow[k] = row1[i];
            resultCol[k] = col1[i];
            resultVal[k] = val1[i] - val2[j];
            i++;
            j++;
            k++;
        }
        // If the row and column of mat1 is smaller, add the element from mat1
        else if (row1[i] < row2[j] || (row1[i] == row2[j] && col1[i] < col2[j])) {
            resultRow[k] = row1[i];
            resultCol[k] = col1[i];
            resultVal[k] = val1[i];
            i++;
            k++;
        }
        // If the row and column of mat2 is smaller, add the element from mat2
        else {
            resultRow[k] = row2[j];
            resultCol[k] = col2[j];
            resultVal[k] = -val2[j];
            j++;
            k++;
        }
    }

    // Add any remaining elements from mat1
    while (i < size1) {
        resultRow[k] = row1[i];
        resultCol[k] = col1[i];
        resultVal[k] = val1[i];
        i++;
        k++;
    }

    // Add any remaining elements from mat2
    while (j < size2) {
        resultRow[k] = row2[j];
        resultCol[k] = col2[j];
        resultVal[k] = -val2[j];
        j++;
        k++;
    }

    return k;  // Return the size of the resulting triplet matrix
}

int main() {
    int size1, size2, sizeResult;

    // Input the size of first sparse matrix
    printf("Enter the number of non-zero elements in the first matrix: ");
    scanf("%d", &size1);
    int row1[size1], col1[size1], val1[size1];

    // Input the non-zero elements for the first matrix
    printf("Enter the non-zero elements (row, column, value) for the first matrix:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d %d %d", &row1[i], &col1[i], &val1[i]);
    }

    // Input the size of second sparse matrix
    printf("Enter the number of non-zero elements in the second matrix: ");
    scanf("%d", &size2);
    int row2[size2], col2[size2], val2[size2];

    // Input the non-zero elements for the second matrix
    printf("Enter the non-zero elements (row, column, value) for the second matrix:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d %d %d", &row2[i], &col2[i], &val2[i]);
    }

    // Resultant triplet matrix will have at most size1 + size2 non-zero elements
    int resultRow[size1 + size2], resultCol[size1 + size2], resultVal[size1 + size2];

    // Add the sparse matrices
    sizeResult = addSparseMatrices(row1, col1, val1, size1, row2, col2, val2, size2, resultRow, resultCol, resultVal);

    // Output the resultant triplet matrix
    printf("Resultant sparse matrix in triplet form:\n");
    for (int i = 0; i < sizeResult; i++) {
        printf("%d %d %d\n", resultRow[i], resultCol[i], resultVal[i]);
    }

    return 0;
}
