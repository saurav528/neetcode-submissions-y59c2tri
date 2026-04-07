class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = INT_MIN;
        for(int i = 0; i< n; i++){
            for(int j = i; j < n; j++){
                int sum = accumulate(nums.begin()+i, nums.begin()+j+1,0);
                maxsum = max(sum, maxsum);
            }
        }
        return maxsum;
       
    }
};
