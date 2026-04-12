class Solution {
public:
    int f(int i, int j, string word1, string word2, vector<vector<int>> &dp){
        if(j == 0) return i;
        if(i == 0) return j;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] == word2[j-1]){
            return dp[i][j] = 0 + f(i-1, j-1, word1, word2, dp);
        }
        else{
            return dp[i][j] = 1+ min({f(i-1, j-1, word1, word2, dp), f(i, j-1, word1, word2, dp), f(i-1, j, word1, word2, dp)});
        } // min(replace,insert, delete)
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // base case for tabulation 
         for(int i = 0; i <= n; i++) dp[i][0] = i;
         for(int j = 0; j <= m; j++) dp[0][j] = j;
         // nested loops
         for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0) continue;
                if(word1[i-1] == word2[j-1]){
                     dp[i][j] = 0 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+ min({ dp[i-1][j-1],  dp[i][j-1],  dp[i-1][j]});
                } // min(replace,insert, delete)
            }
         }

         return dp[n][m];
       // return f(word1.length(), word2.length(), word1, word2, dp);
    }
};
