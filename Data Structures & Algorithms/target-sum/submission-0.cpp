class Solution {
public:
    int f(int ind, int sum, int target, vector<int>&  nums){
        if(ind == nums.size() && sum == target) return 1;
        if(ind > nums.size()) return 0;
        int plus = f(ind+1, sum + nums[ind], target, nums);
        int minus = f(ind+1, sum-nums[ind], target, nums);
        return plus+ minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return f(0, 0, target, nums);
    }
};
