#include <stdio.h>
#include <stdbool.h>
#define MAX 20

int board[MAX][MAX] = {0};
int N;

void printSolution() 
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(board[i][j] ? "Q " : "# ");
        printf("\n");
    }
}

bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solveNQUtil(int col) {
    if (col == N) return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(col + 1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void solveNQ() {
    if (!solveNQUtil(0)) {
        printf("No solution exists\n");
        return;
    }
    printSolution();
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &N);
    if (N > MAX) {
        printf("N too large, max allowed is %d\n", MAX);
        return 1;
    }
    solveNQ();
    return 0;
}
