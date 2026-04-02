class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        vector<int> ans;
        for(int i = 0; i< s.length(); i++){
            mp[s[i]] = i;
        }
        int size =0, end = 0;
        for (int i = 0; i < s.length(); i++){
            end = max(end, mp[s[i]]);
            size++;
            if(i == end){ 
                ans.push_back(size);
                size = 0;
                }
            
        }
return ans;

    }
};
