#include <iostream>
#include <vector>
using namespace std;

// Function to solve N-Queens using Branch and Bound
void solveNQueens(int row, vector<string>& board, int n,
                  vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2) {
    
    // If all queens are placed
    if (row == n) {
        for (string line : board) {
            cout << line << endl;
        }
        cout << "---------------------" << endl;
        return;
    }

    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (!columns[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {
            // Place the queen
            board[row][col] = 'Q';
            columns[col] = true;
            diag1[row - col + n - 1] = true;
            diag2[row + col] = true;

            // Recurse for next row
            solveNQueens(row + 1, board, n, columns, diag1, diag2);

            // Backtrack and remove queen
            board[row][col] = '.';
            columns[col] = false;
            diag1[row - col + n - 1] = false;
            diag2[row + col] = false;
        }
    }
}

int main() {
    int n = 4; // You can change this to 8 or any other number

    // Create an empty board
    vector<string> board(n, string(n, '.'));

    // Keep track of used columns and diagonals
    vector<bool> columns(n, false);
    vector<bool> diag1(2 * n - 1, false); // '\' diagonal
    vector<bool> diag2(2 * n - 1, false); // '/' diagonal

    cout << "N-Queens Solutions using Branch and Bound:\n";
    solveNQueens(0, board, n, columns, diag1, diag2);

    return 0;
}
