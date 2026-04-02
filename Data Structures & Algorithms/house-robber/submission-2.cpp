class Solution {
private:
int dfs(int i, vector<int>& nums, vector<int>& dp){
    if(i >= nums.size()) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = max((nums[i] + dfs(i+2, nums, dp)), dfs(i+1, nums, dp));
}
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(0, nums, dp);
        
    }
};
