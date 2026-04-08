class Solution {
public:/*
    int maxlen = INT_MIN;
    void dp(int len, int ind, int lasti, vector<int> &nums){
        maxlen = max(maxlen, len);
        if(ind >= nums.size()) return;

        if(lasti == -1 || nums[ind] > nums[lasti]){
            dp(len+1, ind+1, ind, nums);
        }
        dp(len, ind+1, lasti, nums);
    }
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);

        for(int i = nums.size()-1; i >=0; i--){
            for(int j = i+1; j < nums.size(); j++){
                
                if(nums[j] > nums[i]){
                    lis[i] = max(lis[i], 1+lis[j]);
                    //lis.push_back(val);
                    }
            }
        }
         return *max_element(lis.begin(), lis.end());
           // dp(0, 0, -1, nums);
           // return maxlen;    
    }
};
