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
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        dp[l1][l2] = 1;
        for(int i = l1; i>= 0; i--){
            for(int j = l2; j >= 0; j--){
                if(i == l1 && j == l2) continue;

            bool ans = false;
            if(i < l1 && s1[i] == s3[i+j]) {
                if(dp[i+1][j]) ans = true;
            }
            if(j < l2 && s2[j] == s3[i+j]) {
                if(dp[i][j+1]) ans = true;
            }
            
            dp[i][j] = ans;

            }
        }
        return dp[0][0];




//        return f(0, 0, s1, s2, s3, dp);
    }
};
