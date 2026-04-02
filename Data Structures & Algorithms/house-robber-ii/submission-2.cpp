class Solution {
private:
int dfs(int i, vector<int>& nums, vector<int>& dp){
    if(i >= nums.size()) return 0;
    
    if(dp[i] != -1) return dp[i];
    return dp[i] = max((nums[i] + dfs(i+2, nums, dp)), dfs(i+1, nums, dp));
}
public:
    int rob1(vector<int>& nums){
        vector<int> dp(nums.size(), -1);
        return dfs(0, nums, dp);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 0) return 0;

        
        vector<int> temp1, temp2;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size() - 1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1), rob1(temp2));
        
    }
};
