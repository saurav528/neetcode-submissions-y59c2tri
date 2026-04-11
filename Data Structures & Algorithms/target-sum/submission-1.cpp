class Solution {
public:
    int f(int ind, int sum, int target, vector<int>&  nums, vector<vector<int>>& dp, int offset){
        if(ind == nums.size() && sum == target) return 1;
        if(ind == nums.size()) return 0;
        if(dp[ind][sum+offset] != -1) return dp[ind][sum+offset];

        int plus = f(ind+1, sum + nums[ind], target, nums, dp, offset);
        int minus = f(ind+1, sum-nums[ind], target, nums, dp, offset);

        return dp[ind][sum+offset] = plus+ minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum*2+1, -1));
        return f(0, 0, target, nums, dp, sum);
    }
};
