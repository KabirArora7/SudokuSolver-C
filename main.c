#include <stdio.h>
#include <stdbool.h>

bool isFalse = false;
bool isTrue = true;

int grid[9][9] = 
{
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void print() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("---------------------\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool possible(int row, int column, int number) {
    int i, j;
    // Checking for row
    for (i = 0; i < 9; i++) {
        if (grid[row][i] == number) {
            return isFalse;
        }
    }
    // Checking for column
    for (i = 0; i < 9; i++) {
        if (grid[i][column] == number) {
            return isFalse;
        }
    }
    // Checking for 3x3 grid
    int x0 = (column / 3) * 3;
    int y0 = (row / 3) * 3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[y0 + i][x0 + j] == number) {
                return isFalse;
            }
        }
    }
    return isTrue;
}

bool solve() {
    int row, column, number;
    for (row = 0; row < 9; row++) {
        for (column = 0; column < 9; column++) {
            if (grid[row][column] == 0) {
                for (number = 1; number <= 9; number++) {
                    if (possible(row, column, number)) {
                        grid[row][column] = number;
                        if (solve()) {
                            return isTrue;
                        }
                        grid[row][column] = 0;
                    }
                }
                return isFalse;
            }
        }
    }
    return isTrue;
}

int main() {
    solve();
    print();
    return 0;
}
