class Solution {
public:
   /* bool f(int i, vector<string>& wordDict, string& s,  vector<int> &dp){
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];
        for(auto word : wordDict){
            if(i+word.length() <= s.size() && s.substr(i, word.length()) == word){
                if(!f(i+word.length(), wordDict, s, dp)){
                    continue;
                }
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }*/
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[s.size()] = true;
        for(int i = s.size()-1; i >= 0; i--){
            for(auto word : wordDict){
                if(i+word.length() <= s.size() && s.substr(i, word.length()) == word){
                    dp[i] = dp[i+word.length()];
            } 
            if(dp[i]) break;
            }
        }
        return dp[0];
        
    }
};
