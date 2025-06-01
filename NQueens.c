#include <stdio.h>
#include <stdlib.h>

#define N 8  // Change N to solve for different board sizes

// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if placing queen at board[row][col] is safe
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return 0;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return 0;
    }

    return 1;  // Safe to place queen here
}

// Recursive utility function to solve N-Queens problem
int solveNQueensUtil(int board[N][N], int col) {
    // Base case: If all queens are placed
    if (col >= N)
        return 1;

    // Try placing queen in all rows in this column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place this queen
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1))
                return 1;

            // If placing queen here doesn't lead to solution, backtrack
            board[i][col] = 0;
        }
    }

    // If queen cannot be placed in any row in this column, return 0
    return 0;
}

// Main function to solve the problem and print the result
void solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0)) {
        printf("No solution exists for %d-Queens problem.\n", N);
        return;
    }

    printBoard(board);
}

int main() {
    solveNQueens();
    return 0;
}
