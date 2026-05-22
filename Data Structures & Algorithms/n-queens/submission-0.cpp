class Solution {
public:
    bool IsSafe(vector<string> board, int row, int col , int n){
        int tempr = row;
        int tempc = col;
        // upper diagonal check
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = tempr;
        col = tempc;
        // horizontal back check
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = tempr;
        col = tempc;
        // lower diagonal check
        while(col >= 0 && row < n){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
   /* void f(int col,vector<string>& board, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(IsSafe(board, row, col, n)){
                board[row][col] = 'Q';
                f(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }*/
    void f2(int col,vector<string>& board, vector<vector<string>>& ans, int n,
     vector<int>& horizontalback, vector<int>& upper, vector<int>& lower){
           if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(horizontalback[row] == 0 && upper[n-1+col-row] == 0 && lower[row+col] == 0){
                board[row][col] = 'Q';

                horizontalback[row] = 1;
                upper[n-1+col-row] = 1;
                lower[row+col] = 1;

                f2(col+1, board, ans, n, horizontalback, upper, lower);

                board[row][col] = '.';

                horizontalback[row] = 0;
                upper[n-1+col-row] = 0;
                lower[row+col] = 0;

            }
        }
     }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<int> horizontalback(n,0), upper((2*n)+1, 0), lower((2*n)+1, 0);
        f2(0, board, ans, n, horizontalback, upper, lower);
        return ans;
    }
};