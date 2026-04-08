class Solution {
public:
    
    int dp( int ind, int lasti, vector<int> &nums, vector<vector<int>>& memo){
        if(ind >= nums.size()) return 0;
        if(memo[ind][lasti+1] != -1) return memo[ind][lasti+1];
        if(lasti == -1 || nums[ind] > nums[lasti]){
           return memo[ind][lasti+1] = max(dp(ind+1, lasti, nums, memo), 1+dp( ind+1, ind, nums, memo));
        }
        return memo[ind][lasti+1] = dp(ind+1, lasti, nums, memo);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
      /*  vector<int> lis(nums.size(), 1);

        for(int i = nums.size()-1; i >=0; i--){
            for(int j = i+1; j < nums.size(); j++){

                if(nums[j] > nums[i]){
                    lis[i] = max(lis[i], 1+lis[j]);
                    //lis.push_back(val);
                    }
            }
        }
         return *max_element(lis.begin(), lis.end());*/
         vector<vector<int>> memo(n,vector<int>(n+1, -1));
        return dp(0, -1, nums, memo);
           
    }
};
