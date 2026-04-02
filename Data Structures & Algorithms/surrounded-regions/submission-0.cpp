
class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<char>>& board){
        if(board[r][c] == 'O') vis[r][c] = true;
        int delx[] = {-1,0,1,0};
        int dely[] = {0,-1,0,1};
        for(int k = 0; k< 4; k++){
            int row = r+delx[k];
            int col = c + dely[k];
            if(row >=0 && row < board.size() && col >=0 && col < board[0].size() &&
             !vis[row][col] && board[row][col] == 'O'){
                dfs(row, col, vis, board);
             }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int r = 0; r < n; r++){
             if(board[r][0] == 'O') dfs(r,0,vis,board);
             if(board[r][m-1] == 'O') dfs(r,m-1,vis,board);

        }
        for(int c = 0; c < m; c++){
            if(board[0][c] == 'O') dfs(0,c,vis,board);
             if(board[n-1][c] == 'O') dfs(n-1,c,vis,board);

        }
        for(int i = 0; i < n; i++){
            for(int j =0; j< m; j++){
                if(board[i][j] == 'O' && vis[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
        

    }
};
 