class Solution {



public:
    string longestPalindrome(string s) {
        string ans = "";
        int reslen = 0;

        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                int l = i;
                int r = j;
                while(l<r && s[l] == s[r]){
                    r--;
                    l++;
                }
                if(l >= r && reslen < (j-i+1)){
                    ans = s.substr(i, j-i+1);
                    reslen = j-i+1;
                }
            }
        }

        return ans;
        
    }
};
