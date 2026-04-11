class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(int r, int c, vector<vector<int>>& matrix, int preval,vector<vector<int>>& dp ){
        int n = matrix.size(), m = matrix[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m || matrix[r][c] <= preval) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        int res = 1;
        for(auto d : directions){
          res = max(res, 1 + dfs(r + d[0], c + d[1], matrix, matrix[r][c], dp));
        }
        return dp[r][c] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp( matrix.size()+1, vector<int>(matrix[0].size()+1, -1));
        int maxlength = 0;
       for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){

             int length = dfs(i, j, matrix, INT_MIN, dp);
             maxlength = max(maxlength, length);

        }
       }
       return maxlength;
       //return f(0, 0, matrix);
    }
};
