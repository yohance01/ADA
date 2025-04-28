#include <iostream>
using namespace std;

const int MAX = 20; // maximum board size
int board[MAX][MAX];

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    return true;
}

bool solve(int row, int n) {
    if (row >= n) return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;
            if (solve(row + 1, n)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) cout << "Q ";
            else cout << "N ";
        }
        cout << endl;
    }
}

void nQueen(int n) {
    for (int i = 0; i < n; i++) {     // initialize board to 0
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (!solve(0, n)) {
        cout << "No solution\n";
    } else {
        printBoard(n);
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    nQueen(n);
    return 0;
}
