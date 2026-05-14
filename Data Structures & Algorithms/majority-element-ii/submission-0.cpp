class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3 + 1;
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto it : mp){
            if(it.second >= n){
                ans.push_back(it.first);
            }
        }
return ans;
    }
};