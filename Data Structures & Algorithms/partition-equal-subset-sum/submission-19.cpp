class Solution {
public:
    bool dp(int i, int target, vector<int>& nums, vector<vector<int>>& memo){
        if(target == 0 ) return true;
        if(i == 0  ) return (nums[0] == target);
        if(memo[i][target] != -1) return memo[i][target];
        bool notake = dp(i-1, target, nums, memo);

        // take
        bool take = false;
        if(target - nums[i] >= 0){
        take = dp(i-1, target - nums[i], nums, memo);
        }
        memo[i][target] = take || notake;
        return take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();      
        int target = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> memo(n, vector<int>(target, -1));

        if(target%2 == 1) return false;
        //target = target/2;
        return dp(n-1, target/2, nums, memo);
        
    }
};
