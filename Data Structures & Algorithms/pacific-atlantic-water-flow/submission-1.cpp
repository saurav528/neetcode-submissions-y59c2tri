class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& ht){
        ocean[r][c] = true;
        int delx[] = {-1,0,1,0};
        int dely[] = {0,-1,0,1};
        for(int k = 0; k < 4; k++){
            int row = r+delx[k];
            int col = c+dely[k];
            if(row >= 0 && row < ht.size() && col >= 0 && col < ht[0].size() && !ocean[row][col] && ht[row][col] >= ht[r][c]){
                dfs(row,col,ocean,ht);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        for(int c = 0; c <m; c++){
            dfs(0, c, pac, heights);
            dfs(n-1,c,atl,heights);
        }
        for(int r = 0; r <n; r++){
            dfs(r, 0, pac, heights);
            dfs(r, m-1, atl, heights);
        }
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
