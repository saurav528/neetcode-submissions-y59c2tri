class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l =0, r=0;
        int count = 0;
       
        while( r< n-1){
            
             int maxi = 0;
            for(int i = l; i <= r; i++){
                maxi = max(i + nums[i], maxi);
            }
            l = r+1;
            r = maxi;
            count++;
        }
        return count;
    }
};
