class Solution {
public:
    bool f(int i, int j,  string& s1, string& s2, string& s3, vector<vector<int>> &dp){
        if(i+j >= s3.length()) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s3[i+j]) {
            if(f(i+1, j, s1, s2, s3, dp)) return dp[i][j] = true;
        }
         if(s2[j] == s3[i+j]) {
            if(f(i, j+1, s1, s2, s3, dp)) return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return f(0, 0, s1, s2, s3, dp);
    }
};
