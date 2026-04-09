class Solution {
public:
    int dfs(int i , int j, int m , int n, vector<vector<int>>& memo){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(memo[i][j] != -1) return memo[i][j];
        int bottom = dfs(i+1, j, m, n, memo);
        int right = dfs(i, j+1, m, n, memo);
        return memo[i][j] =  bottom +  right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));

        return dfs(0,0,m,n, memo);
        
    }
};
