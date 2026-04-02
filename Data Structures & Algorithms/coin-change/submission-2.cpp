class Solution {
public:
    int dfs(int amount, vector<int> &coins, vector<int>& dp){
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int res = 1e9;
        for(int coin : coins){
            if(amount - coin >= 0){
                res = min(res, 1+dfs(amount - coin, coins, dp));
              
            }
        }
        return dp[amount] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int mini = dfs(amount, coins, dp);
        return (mini == 1e9) ? -1 : mini;
    }
};
