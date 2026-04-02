class Solution {
public:
    int dfs(int i, int n, vector<int>& dp){
        if(i == n) return 1;
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = dfs(i+1, n, dp) + dfs(i+2, n, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return dfs(0, n, dp);
        
    }
};
