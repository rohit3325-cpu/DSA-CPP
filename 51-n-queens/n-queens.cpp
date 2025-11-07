class Solution {
public:
bool isSafe(int &row, int &cols, int &n, vector<string> &boards) {
    for (int i = 0; i < row; i++) {
        if (boards[i][cols] == 'Q')
            return false;
    }
    for (int i = row - 1, j = cols - 1; i >= 0 && j >= 0; i--, j--) {
        if (boards[i][j] == 'Q')
            return false;
    }
    for (int i = row - 1, j = cols + 1; i >= 0 && j < n; i--, j++) {
        if (boards[i][j] == 'Q')
            return false;
    }
    return true;
}


     void solve(int row, int n, vector<string> &board, vector<vector<string>> &ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, ans);
                board[row][col] = '.'; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, ans);
        return ans;
    }
};