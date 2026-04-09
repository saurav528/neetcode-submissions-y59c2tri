class Solution {
public:
    /*int dfs(int i , int j, int m , int n, vector<vector<int>>& memo){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(memo[i][j] != -1) return memo[i][j];
        int bottom = dfs(i+1, j, m, n, memo);
        int right = dfs(i, j+1, m, n, memo);
        return memo[i][j] =  bottom +  right;
    }*/
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //dp[m-1][n-1] = 1;
        vector<int> prev(n+1, 0);
        //vector<int> cur(n, 0);
        for(int i = m-1; i>= 0; i--){
            vector<int> cur(n+1, 0);
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1) {cur[n-1] = 1; continue;}
                 int bottom = prev[j];
                 int right = cur[j+1];
                 cur[j] =  bottom +  right;

            }
            prev = cur;
        }

        return prev[0];
        
    }
};
