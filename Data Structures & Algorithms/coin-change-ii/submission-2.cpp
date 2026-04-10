class Solution {
private:
       int f(int ind, int total, vector<int>& coins, vector<vector<int>>& dp){
        
        if(ind == 0) return (total % coins[0] == 0) ? 1 : 0;
        if(dp[ind][total] != 0) return dp[ind][total];
        //take 
        int take = 0;
        if(total >= coins[ind]){
        take = f(ind, total-coins[ind], coins, dp);
        }
        int notake = f(ind-1, total, coins, dp);
        return dp[ind][total] = take+notake;

       }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        return f(coins.size()-1, amount, coins, dp);
    }
};
