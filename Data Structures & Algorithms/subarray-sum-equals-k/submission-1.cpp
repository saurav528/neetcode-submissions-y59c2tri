class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int cursum = 0;
        
        unordered_map<int,int> prefixsum;
        prefixsum[0]++;

        for(int i = 0; i < nums.size(); i++){
            cursum += nums[i];
            int diff = cursum - k;
            cnt += prefixsum[diff];
            prefixsum[cursum]++;
        }
        
        

        return cnt;
    }
};