class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       /* int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            unordered_set<int> hash;
            for(int j = i+1; j < n; j++){
                int third = -(nums[i]+nums[j]);
                if(hash.find(third) != hash.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hash.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;*/

         int n = nums.size();
         vector<vector<int>> ans;
         sort(nums.begin(), nums.end());
        int i = 0;
        while(i < n){
          int j = i+1;
          int k = n-1;
         
          int target = -nums[i];
          while(j< k){
            if(nums[j]+nums[k] > target){
               k--;
                while(k>0 && nums[k+1] == nums[k]) k--;
            }
            else if(nums[j]+nums[k] < target){
              j++;
                while(j<n-1 && nums[j-1] == nums[j]) j++;
            }
           else if(nums[j]+nums[k] == target){
                ans.push_back({nums[i], nums[j], nums[k]});
                k--;
                while(k>0 && nums[k+1] == nums[k]) k--;
                j++;
                while(j<n-1 && nums[j-1] == nums[j]) j++;
            }
          }
          
        i++;
        while(i < n-1 && nums[i-1] == nums[i]) i++;
        }
        
        return ans;
    }
};
