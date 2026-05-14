class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       /* int n = nums.size()/3 + 1;
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
return ans;*/
        int n = nums.size()/3 + 1;
        int el1 = 0, el2 =0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i< nums.size(); i++){
            if(cnt1 == 0 && nums[i] != el2){
                el1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && nums[i] != el1){
                el2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        int c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el1){
              c1++;
            }
            if(nums[i] == el2){
              c2++;
            }
        }
        vector<int> ans;
        if(c1 >= n) ans.push_back(el1);
        if(c2 >= n) ans.push_back(el2);
        return ans;













    }
};