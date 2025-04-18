#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> seen;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                string num(1, board[i][j]);
                if (!seen.insert(num + " in row " + to_string(i)).second ||
                    !seen.insert(num + " in col " + to_string(j)).second ||
                    !seen.insert(num + " in box " + to_string(i/3) + "-" + to_string(j/3)).second)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '2', '1', '9', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '5', '9', '8', '.'},
        {'.', '5', '9', '7', '4', '2', '.', '.', '.'},
        {'.', '4', '1', '8', '3', '6', '.', '.', '.'}
    };
    cout << (isValidSudoku(board) ? "Valid" : "Invalid") << endl; 
    return 0;
}
