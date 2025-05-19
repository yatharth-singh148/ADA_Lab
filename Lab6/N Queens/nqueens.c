#include <stdio.h>
#include <stdlib.h>

int **board;
int N;
int solutionCount = 0;


int isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return 0;

    return 1;
}


void solveNQueens(int col) {
    if (col == N) {
        solutionCount++;
        printf("Solution %d:\n", solutionCount);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            solveNQueens(col + 1);
            board[i][col] = 0;
        }
    }
}

int main() {
    printf("Enter the value of N: ");
    scanf("%d", &N);
    board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        board[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    }

    solveNQueens(0);

    if (solutionCount == 0)
        printf("No solutions found.\n");
    else
        printf("Total solutions: %d\n", solutionCount);
    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);

    return 0;
}
